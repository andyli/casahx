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
	
	/**
		Interface for list collections.
		
		@author Aaron Clinger
		@author Dave Nelson
		@version 06/04/09
	*/
	interface IList<T> {
		
		
		/**
			Appends the specified item to the end of this list.
			
			@param item: Element to be inserted.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function addItem(item:T):Bool;
		
		/**
			Inserts an item as a specified position.
			
			@param item: Element to be inserted.
			@param index: Position where the elements should be added.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function addItemAt(item:T, index:Int):Bool;
		
		/**
			Modifies original list by adding all the elements from another list.
			
			@param items: List of elements to add.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function addItems(items:T):Bool;
		
		/**
			Modifies original list by adding all the elements from another list at a specified position.
			
			@param items: List of elements to add.
			@param index: Position where the elements should be added.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function addItemsAt(items:IList<T>, ?index:Int = 0x7fffffff):Bool;
		
		/**
			Removes all of the items from this list.
		*/
		function clear():Void;
		
		/**
			Determines if this list contains a specified element.
			
			@param item: Element to search for.
			@return Returns <code>true</code> if the list contains the element; otherwise <code>false</code>.
		*/
		function contains(item:T):Bool;
		
		/**
			Determines if this list contains all of the elements of the specified list.
			
			@param items: List of elements to be checked for containment.
			@return Returns <code>true</code> if list contains all elements of the list; otherwise <code>false</code>.
		*/
		function containsAll(items:IList<T>):Bool;
		
		/**
			Determines if the list specified in the <code>list</code> parameter is equal to this list object.
			
			@param list: An object that implements {@link IList}.
			@return Returns <code>true</code> if the object is equal to this list; otherwise <code>false</code>.
		*/
		function equals(list:IList<T>):Bool;
		
		/**
			Returns the element at the specified position in this list.
			
			@param index: The position of the element to return.
			@return The element at the specified position in this list.
		*/
		function getItemAt(index:UInt):T;
		
		/**
			Returns a portion of this list.
			
			@param startIndex: The starting position.
			@param endIndex: The ending position.
			@return The specified portion of the list.
		*/
		function subList(?startIndex:Int = 0, ?endIndex:Int = 16777215):IList<T>;
		
		/**
			Finds the position of the first occurrence of a specified item.
			
			@param item: The element to search for.
			@param fromIndex: The position in the list from which to start searching for the item.
			@return Returns the index of the last occurrence, or <code>-1</code> if the element doesn't exist.
		*/
		function indexOf(item:T, ?fromIndex:Int = 0):Int;
		
		/**
			Determines if this list contains no elements.
			
			@return Returns <code>true</code> if the list contains no items; otherwise <code>false</code>.
		*/
		function isEmpty():Bool;
		
		/**
			Finds the position of the last occurrence of a specified item.
			
			@param item: The element to search for.
			@param fromIndex: The position in the list from which to start searching for the item.
			@return Returns the index of the last occurrence, or <code>-1</code> if the element doesn't exist.
		*/
		function lastIndexOf(item:T, ?fromIndex:Int = 0x7fffffff):Int;
		
		/**
			The number of elements in the list.
		*/
		function size():UInt;
		
		/**
			Modifies the list by removing all items that are identical to the specified item.
			
			@param item: Element to remove.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function removeAllInstancesOfItem(item:T):Bool;
		
		/**
			Removes the first occurance of the specified item in the list.
			
			@param item: Element to remove.
			@return Returns <code>true</code> if the list contained the item; otherwise <code>false</code>.
		*/
		function removeItem(item:T):Bool;
		
		/**
			Removes the element at the specified position in this list.
			
			@param index: The position of the item to removed.
			@return The item previously at the specified index.
		*/
		function removeItemAt(index:Int):T;
		
		/**
			Removes only the specified items in a list.
			
			@param items: List of elements to remove.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function removeItems(items:IList<T>):Bool;
		
		/**
			Retains only the specified items in a list.
			
			@param items: List of elements to keep.
			@return Returns <code>true</code> if the list was changed as a result of the call; otherwise <code>false</code>.
		*/
		function retainItems(items:IList<T>):Bool;
		
		/**
			Replaces an item at a specified position.
			
			@param item: The item to be stored.
			@param index: The index of the item to replace.
			@return The element previously at the specified position.
		*/
		function setItem(item:T, index:Int):T;
		
		/**
			Returns an Array containing all of the elements in the list in order.
			
			@return Returns an Array containing all of the elements in the list in order.
		*/
		function toArray():Array<T>;
		
		/**
			Returns a list that is an exact copy of the original list.
			
			@return Returns a list that is an exact copy of the original list.
		*/
		function clone():IList<T>;
		
		/**
			Returns a string that represents the items in the list.
			
			@return Returns a string that represents the items in the list.
		*/
		function toString():String
	}
