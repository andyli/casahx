/*
	CASA Framework for ActionScript 3.0
	Copyright (c) 2010, Contributors of CASA Framework
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	- Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	
	- Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	- Neither the name of the CASA Framework nor the names of its contributors
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
	import flash.display.DisplayObject;
	import flash.display.Loader;
	import flash.display.LoaderInfo;
	import flash.events.Event;
	#if flash import flash.events.HTTPStatusEvent; #end
	import flash.events.IEventDispatcher;
	#if flash import flash.events.SecurityErrorEvent; #end
	#if flash import flash.system.LoaderContext; #end
	import org.casalib.core.UInt;
	import org.casalib.load.LoadItem;
	
	/*[Event(name="init", type="flash.events.Event")]*/
	/*[Event(name="unload", type="flash.events.Event")]*/
	/*[Event(name="httpStatus", type="flash.events.HTTPStatusEvent")]*/
	/*[Event(name="securityError", type="flash.events.SecurityErrorEvent")]*/
	
	/**
		Wraps <code>Loader</code> and extends from {@link LoadItem} and {@link Process}.
		
		In almost all cases you will want to use {@link ImageLoad} or {@link SwfLoad} instead of this class.
		
		@author Aaron Clinger
		@version 02/13/10
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.events.LoadEvent;
					import org.casalib.load.CasaLoader;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _casaLoader:CasaLoader;
						
						
						public function MyExample() {
							super();
							
							this._casaLoader = new CasaLoader("test.jpg");
							this._casaLoader.addEventListener(LoadEvent.COMPLETE, this._onComplete);
							this._casaLoader.start();
						}
						
						protected function _onComplete(e:LoadEvent):void {
							this.addChild(this._casaLoader.loader);
						}
					}
				}
			</code>
	*/
	class CasaLoader extends LoadItem {
		
		public var content(getContent, null) : DisplayObject ;
		public var loader(getLoader, null) : Loader ;
		public var loaderInfo(getLoaderInfo, null) : LoaderInfo ;
		inline public static var FLASH_CONTENT_TYPE:String = 'application/x-shockwave-flash';
		inline public static var JPEG_CONTENT_TYPE:String  = 'image/jpeg';
		inline public static var GIF_CONTENT_TYPE:String   = 'image/gif';
		inline public static var PNG_CONTENT_TYPE:String   = 'image/png';
		#if flash private var _context:LoaderContext; #end
		
		
		/**
			Creates and defines a CasaLoader.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file you wish to load.
			@param context: An optional LoaderContext object.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
			@throws Error if you try to load an empty <code>String</code> or <code>URLRequest</code>.
		*/
		public function new(request:Dynamic #if flash , ?context:LoaderContext = null #end) {
			super(new Loader(), request);
			
			#if flash
			this._context = context;
			#end
			
			this._initListeners(this.loaderInfo);
		}
		
		/**
			The Loader being used to load the image or SWF.
		*/
		private function getLoader():Loader {
			return cast( this._loadItem, Loader);
		}
		
		/**
			The content received from the CasaLoader. Available after load is complete.
			
			@throws Error if method is called before the SWF has loaded.
		*/
		private function getContent():DisplayObject {
			if (!this.loaded)
				throw 'Cannot access an external asset until the SWF has loaded.';
			
			return this.loader.content;
		}
		
		/**
			The LoaderInfo corresponding to the object being loaded.
		*/
		private function getLoaderInfo():LoaderInfo {
			return this._loadItem.contentLoaderInfo;
		}
		
		/**
			@exclude
		*/
		private override function getBytesTotal():Float {
			return (this._loadItem.contentLoaderInfo.bytesTotal == 0 && this.bytesLoaded != 0) ? Math.POSITIVE_INFINITY : this._loadItem.contentLoaderInfo.bytesTotal;
		}
		
		/**
			The number of bytes loaded of the requested file.
		*/
		private override function getBytesLoaded():UInt {
			return this._loadItem.contentLoaderInfo.bytesLoaded;
		}
		
		public override function destroy():Void {
			this._dispatcher.removeEventListener(Event.INIT, this._dispatchEvent);
			this._dispatcher.removeEventListener(Event.UNLOAD, this._dispatchEvent);
			#if flash
			this._dispatcher.removeEventListener(HTTPStatusEvent.HTTP_STATUS, this._onHttpStatus);
			this._dispatcher.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, this._dispatchEvent);
			#end
			
			super.destroy();
		}
		
		override function _load():Void {
			this._loadItem.load(this._request #if flash , this._context #end);
		}
		
		/**
			@sends Event#INIT - Dispatched when the properties and methods of a loaded SWF file are accessible.
			@sends Event#UNLOAD - Dispatched when <code>unload</code> is called.
			@sends HTTPStatusEvent#HTTP_STATUS - Dispatched if class is able to detect and return the status code for the request.
			@sends SecurityErrorEvent#SECURITY_ERROR - Dispatched if load is outside the security sandbox.
		*/
		override function _initListeners(dispatcher:IEventDispatcher):Void {
			super._initListeners(dispatcher);
			
			this._dispatcher.addEventListener(Event.INIT, this._dispatchEvent, false, 0, true);
			this._dispatcher.addEventListener(Event.UNLOAD, this._dispatchEvent, false, 0, true);
			#if flash 
			this._dispatcher.addEventListener(HTTPStatusEvent.HTTP_STATUS, this._onHttpStatus, false, 0, true);
			this._dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, this._dispatchEvent, false, 0, true);
			#end
		}
	}
