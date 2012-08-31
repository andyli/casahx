/*
	CASA Lib for ActionScript 3.0
	Copyright (c) 2011, Aaron Clinger & Contributors of CASA Lib
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	- Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	
	- Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	- Neither the name of the CASA Lib nor the names of its contributors
	  may be used to endorse or promote products derived from this software
	  without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
package org.casalib.load; 
	#if flash
	import flash.events.AsyncErrorEvent;
	import flash.events.NetStatusEvent;
	import flash.events.SecurityErrorEvent;
	import flash.net.NetConnection;
	import flash.net.NetStream;
	import flash.media.Video;
	#end
	import flash.events.Event;
	import flash.events.IEventDispatcher;
	import org.casalib.core.UInt;
	import org.casalib.events.VideoInfoEvent;
	import org.casalib.events.VideoLoadEvent;
	import org.casalib.load.LoadItem;
	import org.casalib.math.Percent;
	import org.casalib.time.EnterFrame;
	import org.casalib.util.LoadUtil;
	
	/*[Event(name="cuePoint", type="org.casalib.events.VideoInfoEvent")]*/
	/*[Event(name="metaData", type="org.casalib.events.VideoInfoEvent")]*/
	/*[Event(name="buffered", type="org.casalib.events.VideoLoadEvent")]*/
	/*[Event(name="progress", type="org.casalib.events.VideoLoadEvent")]*/
	/*[Event(name="asyncError", type="flash.events.AsyncErrorEvent")]*/
	/*[Event(name="netStatus", type="flash.events.NetStatusEvent")]*/
	/*[Event(name="securityError", type="flash.events.SecurityErrorEvent")]*/
	
	/**
		Provides an easy and standardized way to load video files. VideoLoad also includes {@link VideoLoadEvent buffer progress information} in the progress event.
		
		@author Aaron Clinger
		@version 08/06/10
		@example 
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.events.VideoLoadEvent;
					import org.casalib.load.VideoLoad;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _videoLoad:VideoLoad;
						
						
						public function MyExample() {
							super();
							
							this._videoLoad = new VideoLoad("test.flv");
							this._videoLoad.pauseStart = true;
							this._videoLoad.addEventListener(VideoLoadEvent.PROGRESS, this._onProgress);
							this._videoLoad.addEventListener(VideoLoadEvent.BUFFERED, this._onBuffered);
							this._videoLoad.start();
							
							this.addChild(this._videoLoad.video);
						}
						
						protected function _onProgress(e:VideoLoadEvent):void {
							trace(e.millisecondsUntilBuffered + " milliseconds until buffered");
							trace(e.buffer.percentage + "% buffered");
							trace(e.progress.percentage + "% loaded");
						}
						
						protected function _onBuffered(e:VideoLoadEvent):void {
							e.target.netStream.resume();
						}
					}
				}
			</code>
	*/
	class VideoLoad extends LoadItem {
		
		public var buffer(getBuffer, null) : Percent ;
		public var buffered(getBuffered, null) : Bool ;
		public var duration(getDuration, setDuration) : Float;
		public var metaData(getMetaData, null) : Dynamic ;
		public var millisecondsUntilBuffered(getMillisecondsUntilBuffered, null) : Int ;
		#if flash
		public var netConnection(getNetConnection, null) : NetConnection ;
		public var netStream(getNetStream, null) : NetStream ;
		var _netConnection:NetConnection;
		public var video(getVideo, null) : Video ;
		var _video:Video;
		#end
		public var pauseStart(getPauseStart, setPauseStart) : Bool;
		var _buffered:Bool;
		var _isOpen:Bool;
		var _duration:Float;
		var _framePulse:EnterFrame;
		var _pauseStart:Bool;
		var _buffer:Percent;
		var _millisecondsUntilBuffered:Int;
		var _metaData:Dynamic;
		var _completeWhenBuffered:Bool;
		
		
		/**
			Creates a new VideoLoad.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the video you wish to load.
			@param completeWhenBuffered: If the load should be considered complete when buffered <code>true</code>, or when the video has completely loaded <code>false</code>; defaults to <code>false</code>.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
			@throws <code>Error</code> if you try to load an empty <code>String</code> or <code>URLRequest</code>.
		*/
		public function new(request:Dynamic, ?completeWhenBuffered:Bool = false) {
			#if flash
			this._netConnection = new NetConnection();
			this._netConnection.connect(null);
			#end
			
			super(#if flash new NetStream(this._netConnection)#else null #end, request);
			
			this._initListeners(this._loadItem);
			
			this._completeWhenBuffered      = completeWhenBuffered;
			this._duration                  = -1;
			this._buffer                    = new Percent();
			this._millisecondsUntilBuffered = -1;
			this._framePulse                = EnterFrame.getInstance();
			
			#if flash
			this._video = new Video();
			this._video.attachNetStream(this._loadItem);
			#end
		}
		
		/**
			The duration/length of the video.
			
			@usageNote Setting this value will override the length (provided by the video metadata) that is used to calculate buffer.
		*/
		private function getDuration():Float{
			return this._duration;
		}
		
		private function setDuration(seconds:Float):Float{
			this._duration = seconds;
			return seconds;
		}
		
		/**
			Indicates to pause video at start <code>true</code>, or to let the video automatically play <code>false</code>; defaults to <code>false</code>.
		*/
		private function getPauseStart():Bool{
			return this._pauseStart;
		}
		
		private function setPauseStart(shouldPause:Bool):Bool{
			this._pauseStart = shouldPause;
			return shouldPause;
		}
		
		#if flash
		/**
			A Video class with attached NetStream.
		*/
		private function getVideo():Video {
			return this._video;
		}
		
		/**
			The NetConnection class used by the VideoLoad class.
		*/
		private function getNetConnection():NetConnection {
			return this._netConnection;
		}
		
		/**
			The NetStream class used by the VideoLoad class.
		*/
		private function getNetStream():NetStream {
			return cast( this._loadItem, NetStream);
		}
		#end
		
		/**
			The time remaining in milliseconds until the video has completely buffered.
			
			@usageNote {@link VideoLoad} will report <code>-1</code> milliseconds until two seconds of load time has elapsed.
		*/
		private function getMillisecondsUntilBuffered():Int {
			return this._millisecondsUntilBuffered;
		}
		
		/**
			The percent the video has buffered.
			
			@usageNote {@link VideoLoad} will report <code>0</code> percent until two seconds of load time has elapsed.
		*/
		private function getBuffer():Percent {
			return this._buffer.clone();
		}
		
		/**
			Determines if the requested video has buffered <code>true</code>, or hasn't finished buffering <code>false</code>.
		*/
		private function getBuffered():Bool {
			return this._buffered;
		}
		
		/**
			The meta data information embedded in the video being loaded.
		*/
		private function getMetaData():Dynamic {
			return this._metaData;
		}
		
		/**
			@exclude
		*/
		public override function start():Void {
			this._isOpen = false;
			
			super.start();
		}
		
		/**
			@exclude
		*/
		public override function stop():Void {
			this._framePulse.removeEventListener(Event.ENTER_FRAME, this._onFrameFire);
			
			super.stop();
		}
		
		/**
			@usageNote <code>destroy</code> does not close the internal NetStream object. To completely destroy a VideoLoad you have to close the NetStream object:
			<code>
				this._videoLoad.netStream.close();
				this._videoLoad.destroy();
			</code>
		*/
		public override function destroy():Void {
			#if flash
			this._dispatcher.removeEventListener(AsyncErrorEvent.ASYNC_ERROR, this._dispatchEvent);
			this._dispatcher.removeEventListener(NetStatusEvent.NET_STATUS, this._netStatus);
			this._netConnection.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, this._dispatchEvent);
			#end
			
			this._loadItem.client = this._loadItem;
			
			super.destroy();
		}
		
		/**
			@sends AsyncErrorEvent#ASYNC_ERROR - Dispatched when an exception is thrown asynchronously.
			@sends SecurityErrorEvent#SECURITY_ERROR - Dispatched if load is outside the security sandbox.
		*/
		override function _initListeners(dispatcher:IEventDispatcher):Void {
			this._dispatcher = dispatcher;
			
			#if flash
			this._dispatcher.addEventListener(AsyncErrorEvent.ASYNC_ERROR, this._dispatchEvent, false, 0, true);
			this._dispatcher.addEventListener(NetStatusEvent.NET_STATUS, this._netStatus, false, 0, true);
			this._netConnection.addEventListener(SecurityErrorEvent.SECURITY_ERROR, this._dispatchEvent, false, 0, true);
			#end
			
			var customClient = {
				onCuePoint: this._onCuePoint,
				onMetaData: this._onMetaData
			};
			
			this._loadItem.client = customClient;
		}
		
		/**
			@sends VideoLoadEvent#PROGRESS - Dispatched as video is received during the download process.
			@sends VideoLoadEvent#BUFFERED - Dispatched when video is buffered.
		*/
		override function _calculateLoadProgress():Void {
			var justBuffered:Bool    = false;
			var currentTime:Int      = getTimer();
			var loadComplete:Bool    = this.bytesLoaded >= this.bytesTotal;
			this._Bps                = LoadUtil.calculateBps(this.bytesLoaded, this._startTime, currentTime);
			this._time               = currentTime - this._startTime;
			
			this._progress.decimalPercentage = this.bytesLoaded / this.bytesTotal;
			
			if (!this.buffered && this.duration > 0) {
				if (currentTime - this._startTime > 2000) {
					var videoLength:UInt = Std.int(Math.max((this.duration - 2) * 1000, 0));
					
					this._buffer                    = LoadUtil.calculateBufferPercent(this.bytesLoaded, this.bytesTotal, this._startTime, currentTime, videoLength);
					this._millisecondsUntilBuffered = Std.int(LoadUtil.calculateMillisecondsUntilBuffered(this.bytesLoaded, this.bytesTotal, this._startTime, currentTime, videoLength));
				}
				
				if (this.buffer.decimalPercentage == 1 || this._progress.decimalPercentage == 1)
					this._buffered = justBuffered = true;
			}
			
			if (this.buffered || loadComplete) {
				if (loadComplete && !this.buffered)
					this._buffered = justBuffered = true;
				
				this._buffer.decimalPercentage  = 1;
				this._millisecondsUntilBuffered = 0;
			}
			
			if (this._completeWhenBuffered)
				this._progress.decimalPercentage = this._buffer.decimalPercentage;
			
			this.dispatchEvent(this._createDefinedVideoLoadEvent(VideoLoadEvent.PROGRESS));
			
			if (justBuffered) {
				this.dispatchEvent(this._createDefinedVideoLoadEvent(VideoLoadEvent.BUFFERED));
				
				if (this._completeWhenBuffered) {
					this._onComplete();
					return;
				}
			}
			
			if (loadComplete && this.buffered)
				this._onComplete();
		}
		
		override function _complete():Void {
			super._complete();
			
			this._framePulse.removeEventListener(Event.ENTER_FRAME, this._onFrameFire);
		}
		
		override function _load():Void {
			this._loadItem.play(this._request.url);
			
			if (this.pauseStart)
				this._loadItem.pause();
			
			this._buffer.percentage         = 0;
			this._millisecondsUntilBuffered = -1;
			this._buffered                  = false;
			
			this._framePulse.addEventListener(Event.ENTER_FRAME, this._onFrameFire, false, 0, true);
			this._calculateLoadProgress();
		}
		
		function _createDefinedVideoLoadEvent(type:String):VideoLoadEvent {
			var vidLoadEvent:VideoLoadEvent        = new VideoLoadEvent(type);
			vidLoadEvent.attempts                  = this.attempts;
			vidLoadEvent.Bps                       = this.Bps;
			vidLoadEvent.buffer                    = this.buffer;
			vidLoadEvent.bytesLoaded               = this.bytesLoaded;
			vidLoadEvent.bytesTotal                = this.bytesTotal;
			vidLoadEvent.latency                   = this.latency;
			vidLoadEvent.millisecondsUntilBuffered = this.millisecondsUntilBuffered;
			vidLoadEvent.progress                  = this.progress;
			vidLoadEvent.retries                   = this.retries;
			vidLoadEvent.time                      = this.time;
			
			return vidLoadEvent;
		}
		
		/**
			@sends VideoInfoEvent#CUE_POINT - Dispatched when a video cue point is reached.
		*/
		function _onCuePoint(infoObject:Dynamic):Void {
			var vidInfoEvent:VideoInfoEvent = new VideoInfoEvent(VideoInfoEvent.CUE_POINT);
			vidInfoEvent.infoObject         = infoObject;
			
			this.dispatchEvent(vidInfoEvent);
		}
		
		/**
			@sends VideoInfoEvent#META_DATA - Dispatched when video meta data is received.
		*/
		function _onMetaData(infoObject:Dynamic):Void {
			if (this.duration == -1)
				this.duration = infoObject.duration;
			
			var vidInfoEvent:VideoInfoEvent = new VideoInfoEvent(VideoInfoEvent.META_DATA);
			vidInfoEvent.infoObject         = infoObject;
			
			this._metaData = infoObject;
			
			this.dispatchEvent(vidInfoEvent);
		}
		
		#if flash
		/**
			@sends NetStatusEvent#NET_STATUS - Dispatched when a NetStream object has reporting its status.
		*/
		function _netStatus(e:NetStatusEvent):Void {
			if (!this._isOpen) {
				this._isOpen = true;
				this._onOpen(new Event(Event.OPEN));
			}
			
			if (e.info.level == 'error' && !this.loaded)
				this._onLoadError(e);
			else
				this.dispatchEvent(e);
		}
		#end
		
		function _onFrameFire(e:Event):Void {
			this._calculateLoadProgress();
		}
	}
