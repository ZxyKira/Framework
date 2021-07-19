/* *****************************************************************************************
 *    File Name   :BlockPool.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_BlockPool_hpp_
#define framework_util_BlockPool_hpp_


#include <stdint.h>
#include <string.h>

#include "Pool.hpp"


namespace framework{
	namespace util{
		
	/* ************************************
	 *  Class BlockPool
	 */
		class BlockPool : public Pool{
			

			/* **************************************************************************************
			 *  Variable <Public>
			 */

			/* **************************************************************************************
			 *  Variable <Protected>
			 */

			/* **************************************************************************************
			 *  Variable <Private>
			 */
			private: struct BlockPoolMemory{
				struct{
					uint32_t elementSize;
					uint32_t capacity;
					uint8_t* buffer;
					bool needFree;
				}config;

				struct{
					uint32_t fixed;
					uint32_t size;
				}handle;
			}blockPool;
			
			
			/* **************************************************************************************
			 *  Abstract method <Public>
			 */

			/* **************************************************************************************
			 *  Abstract method <Protected>
			 */

			/* **************************************************************************************
			 *  Construct Method
			 */
			public: BlockPool(uint32_t elementSize, uint32_t capacity) : Pool(){
				memset(&this->blockPool, 0x00, sizeof(struct BlockPool::BlockPoolMemory));
				
				this->blockPool.config.elementSize = elementSize;
				this->blockPool.config.capacity = capacity;
				this->blockPool.config.buffer = new uint8_t[elementSize * capacity];
				this->blockPool.config.needFree = true;
				
				this->blockFormat();
			}
			 
			
			public: BlockPool(void* buffer, uint32_t elementSize, uint32_t capacity) : Pool(){
				memset(&this->blockPool, 0x00, sizeof(struct BlockPool::BlockPoolMemory));
				
				this->blockPool.config.elementSize = elementSize;
				this->blockPool.config.capacity = capacity;
				this->blockPool.config.buffer = (uint8_t*)buffer;
				this->blockPool.config.needFree = false;
				
				this->blockFormat();
			}
			
			
			public: ~BlockPool(){
				if(this->blockPool.config.needFree)
					delete (uint8_t*)this->blockPool.config.buffer;
			}
			
			/* **************************************************************************************
			 *  Public Method <Static>
			 */
			
			/* **************************************************************************************
			 *  Public Method <Override>
			 */
			
			/**
			 *	Returns this pool element size of byte
			 *
			 *  @return element size of byte.
			 */
			public: virtual uint32_t elementSize(void){
				return this->blockPool.config.elementSize;
			}
			
			/**
			 *  Returns this pool's capacity.
			 *
			 *  @return The capacity of this pool.
			 */
			public: virtual uint32_t capacity(void){
				return this->blockPool.config.capacity;
			}
			
			/**
			 *  Returns the number of elements in this pool.
			 *
			 *  @return the number of elements in this pool.
			 */
			public: virtual uint32_t size(void){
				return (this->blockPool.handle.size - this->blockPool.handle.fixed);
			}
			
			/**
			 *  Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
			 */
			public: virtual void clear(void){
				this->blockFormat();
			}
			
			/**
			 *  Returns true if this pool contains no elements.
			 *
			 *  @return true if this pool contains no elements.
			 */
			public: virtual bool isEmpty(void){
				if(blockPool.handle.size == blockPool.handle.fixed)
					return true;
				
				else
					return false;
			}
			
			/**
			 *  Alloc memory from pool.
			 *
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: virtual void* alloc(void){
				if(this->blockPool.handle.size == this->blockPool.config.capacity)
					return 0;
				
				uint32_t shift = 0;
				
				for(int i = this->blockPool.handle.fixed; i < this->blockPool.config.capacity; i++){
					if(!this->getUsingFlag(i)){
						shift = i;
						break;
					}
				}
				
				if(!shift)
					return 0;
				
				this->setUsingFlag(shift, true);
				++this->blockPool.handle.size;
				return this->getBlock(shift);
			}
			
			/**
			 *  Alloc memory from pool and copy element.
			 *
			 *  @element Element pointer.
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: virtual void* add(void* element){
				void* block = this->alloc();
				if(block == 0)
					return 0;
				
				memcpy(block, element, this->blockPool.config.elementSize);
				return block;
			}
			
			/**
			 *  Free this element memory.	
			 *
			 *  @element Element pointer.
			 *  @return true if this poll found element and remove.
			 */
			public: virtual bool remove(void* element){
				uint32_t shift = this->getBlockShift(element);
				if(shift < this->blockPool.handle.fixed)
					return false;
				
				if(this->getUsingFlag(shift)){
					this->setUsingFlag(shift, false);
					return true;
				}else{
					return false;
				}
			}
			
			/**
			 *  Performs the given action for each entry in this map until all entries have been processed.
			 *
			 *  @action The action to be performed for each entry.
			 */
			public: virtual void forEach(void(*action)(void* element)){
				if(action == 0)
					return;
				
				for(int i = blockPool.handle.fixed; i<blockPool.config.capacity; i++){
					if(getUsingFlag(i))
						action(getBlock(i));
					
				}
			}
			
			/* **************************************************************************************
			 *  Public Method
			 */

			/* **************************************************************************************
			 *  Protected Method <Static>
			 */
			
			/* **************************************************************************************
			 *  Protected Method <Override>
			 */
			
			/* **************************************************************************************
			 *  Protected Method
			 */

			/* **************************************************************************************
			 *  Private Method <Static>
			 */			

			/* **************************************************************************************
			 *  Private Method <Override>
			 */
			 
			/* **************************************************************************************
			 *  Private Method
			 */
			 
			/**
			 *
			 */
			private: void blockFormat(void){
				blockPool.handle.fixed = getFixedSize(blockPool.config.capacity, blockPool.config.elementSize);
				
				for(int i=0; i<blockPool.handle.fixed; i++)
					this->blockClear(i);
				
				for(int i=0; i<blockPool.handle.fixed; i++)
					this->setUsingFlag(i, true);
				
			}
			
			/**
			 *  
			 */
			private: uint32_t getFixedSize(uint32_t capacity, uint32_t elementSize){
				uint32_t bytes;
				uint32_t result;
				
				bytes = (capacity/8);
				
				if(capacity%8)
					++bytes;
				
				result = bytes/elementSize;
				if(bytes%elementSize)
					++result;
				
				return result;
			}
			
			/**
			 *
			 */
			private: inline void setUsingFlag(uint32_t shift, bool enable){
				uint32_t bytes = shift/8;
				uint32_t bits = shift%8;
				
				if(enable)
					this->blockPool.config.buffer[bytes] |= (1<<bits);
				
				else
					this->blockPool.config.buffer[bytes] &= ~(1<<bits);
				
				return;
			}
			
			/**
			 *
			 */
			private: inline void* getBlock(uint32_t shift){
				uint32_t bytes = shift * this->blockPool.config.elementSize;
				return &this->blockPool.config.buffer[bytes];
			}
			
			/**
			 *
			 */
			private: inline bool getUsingFlag(uint32_t shift){
				uint32_t bytes = shift/8;
				uint32_t bits = shift%8;
				
				if(this->blockPool.config.buffer[bytes] & (1 << bits))
					return true;
				else
					return false;
				
			}
			
			/**
			 *
			 */
			private: void* blockClear(uint32_t shift){
				void* block = this->getBlock(shift);
				memset(block, 0x00, blockPool.config.elementSize);
				return block;
			}
			
			/**
			 *
			 */
			private: void* blockCopy(uint32_t shift, void* element){
				void* block = this->getBlock(shift);
				memcpy(block, element, blockPool.config.elementSize);
				return block;
			}
			
			/**
			 *
			 */
			private: uint32_t getBlockShift(void* block){
				if((uint32_t)this->blockPool.config.buffer > (uint32_t)block)
					return 0;
				
				uint32_t shift = ((uint32_t)this->blockPool.config.buffer - (uint32_t)block) / this->blockPool.config.elementSize;
				
				if(shift >= this->blockPool.config.capacity)
					return 0;
				
				else
					return shift;
			}
			
			
		};
	/* ************************************
	 *  End Class BlockPool
	 */
		
	}
}

 
 
#endif //framework_util_BlockPool_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
