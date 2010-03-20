/*
	CASA Lib for ActionScript 3.0
	Copyright (c) 2009, Aaron Clinger & Contributors of CASA Lib
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
package org.casalib.collection; 
	import org.casalib.collection.List;
	import org.casalib.util.ArrayUtil;
	
	/**
		An ordered or sequence collection that contains no duplicates. Similar to Java's Set but contains all the methods of List.
		
		@author Aaron Clinger
		@version 04/27/08
		@see List
	*/
	class UniqueList<T> extends List<T> {
		
		/**
			Creates a new UniqueList;
			
			@param collection: An Array of items to populate the contents of this list; UniqueList will only accept the unique elements of the Array.
		*/
		public function new(?collection:Array<T> = null) {
			super((collection == null) ? null : ArrayUtil.removeDuplicates(collection));
		}
		
		/**
			{@inheritDoc}
			
			@param item: {@inheritDoc}
			@return Returns <code>true</code> if the element was unique and added; otherwise <code>false</code>.
		*/
		public override function addItem(item:T):Bool {
			if (this.contains(item))
				return false;
			
			this._collection.push(item);
			
			return true;
		}
		
		/**
			{@inheritDoc}
			
			@param item: {@inheritDoc}
			@param index: {@inheritDoc}
			@return Returns <code>true</code> if the element was unique and added; otherwise <code>false</code>.
		*/
		public override function addItemAt(item:T, index:Int):Bool {
			if (this.contains(item))
				return false;
			
			this._collection.splice(index, 0, item);
			
			return true;
		}
		
		/**
			Modifies original list by adding all the elements from another list that aren't already present.
			
			@param items: {@inheritDoc}
			@return Returns <code>true</code> if any elements of the specified list were unique and added; otherwise <code>false</code>.
		*/
		public override function addItems(items:IList<T>):Bool {
			var uniqueItems:Array<T> = items.toArray();
			
			ArrayUtil.removeItems(uniqueItems, this.toArray());
			
			if (uniqueItems.length == 0)
				return false;
			
			this._collection = this._collection.concat(uniqueItems);
			
			return true;
		}
		
		/**
			Modifies original list by adding all the elements from another list, that aren't already present, at a specified position.
			
			@param items: {@inheritDoc}
			@param index: {@inheritDoc}
			@return Returns <code>true</code> if any elements of the specified list were unique and added; otherwise <code>false</code>.
		*/
		public override function addItemsAt(items:IList<T>, ?index:Int = 0x7fffffff):Bool {
			var uniqueItems:Array<T> = items.toArray();
			
			ArrayUtil.removeItems(uniqueItems, this.toArray());
			
			if (uniqueItems.length == 0)
				return false;
			
			return ArrayUtil.addItemsAt(this._collection, uniqueItems, index);
		}
		
		/**
			{@inheritDoc}
			
			@param item: {@inheritDoc}
			@param index: {@inheritDoc}
			@return {@inheritDoc}
			@throws Error if you try to set an item that is already contained in the list.
		*/
		public override function setItem(item:T, index:Int):T {
			if (this.contains(item))
				throw 'List already contains specified item (' + item + ').';
			
			return this._collection.splice(index, 1, item)[0];
		}
		
		/**
			{@inheritDoc}
			
			@param startIndex: {@inheritDoc}
			@param endIndex: {@inheritDoc}
			@return {@inheritDoc}
		*/
		public override function subList(?startIndex:Int = 0, ?endIndex:Int = 16777215):IList<T> {
			return new UniqueList<T>(this._collection.slice(startIndex, endIndex));
		}
		
		/**
			{@inheritDoc}
			
			@return {@inheritDoc}
		*/
		public override function clone():IList<T> {
			return new UniqueList<T>(this.toArray());
		}
	}
