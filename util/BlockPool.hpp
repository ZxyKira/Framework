/* *****************************************************************************************
 *    File Name   :BlockPool.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_BlockPool_hpp_
#define framework_util_BlockPool_hpp_


#include <stdint.h>

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
			private: bool needFree;
			private: uint32_t valueElementSize;
			private: uint32_t elementCapacity;
			private: uint8_t* buffer;
			
			private: union PoolFlag{
				uint16_t value;
				struct{
					uint16_t  flag  :3;
					uint16_t  block :13;
				}s;
			};
			
			private: struct BlockPoolMemory{
				uint16_t  isBusy;
				uint16_t  mod;
				
				struct{
					void      *startPoint;
					uint32_t  size;
				}buffer;
				
				struct{
					uint32_t  size;
					uint8_t    *flagBlock;
					void      *startPoint;
					
					struct{
						uint16_t  blockTotal;
						uint16_t  flagUse;
						uint16_t  flagStart;
						union PoolFlag flagTotal;
						union PoolFlag flagCount;
						union PoolFlag lastFlag;
					}count;
				}block;
			}blockPoolMemory;
			
			
			/* **************************************************************************************
			 *  Abstract method <Public>
			 */

			/* **************************************************************************************
			 *  Abstract method <Protected>
			 */

			/* **************************************************************************************
			 *  Construct Method
			 */
			public: BlockPool(uint32_t elementSize, uint32_t capacity){
				this->valueElementSize = elementSize;
				this->elementCapacity = capacity;
				this->buffer = new uint8_t[elementSize * capacity];
				this->needFree = true;
			}
			 
			public: BlockPool(void* buffer, uint32_t elementSize, uint32_t capacity){
				this->valueElementSize = elementSize;
				this->elementCapacity = capacity;
				this->buffer = (uint8_t*)buffer;
				this->needFree = false;
			}
			
			public: ~BlockPool(){
				if(needFree)
					delete this->buffer;
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
			public: uint32_t elementSize(void){
				return this->valueElementSize;
			}
			
			/**
			 *  Returns this pool's capacity.
			 *
			 *  @return The capacity of this pool.
			 */
			public: uint32_t capacity(void){
				return this->elementCapacity;
			}
			
			/**
			 *  Returns the number of elements in this pool.
			 *
			 *  @return the number of elements in this pool.
			 */
			public: uint32_t size(void){
				
			}
			
			/**
			 *  Returns this pool's limit.
			 *
			 *  @return The limit of this pool.
			 */
			public: uint32_t limit(void){
			
			}
			
			/**
			 *  Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
			 */
			public: void clear(void){
			
			}
			
			/**
			 *  Returns true if this pool contains no elements.
			 *
			 *  @return true if this pool contains no elements.
			 */
			public: bool isEmpty(void){
			
			}
			
			/**
			 *  Alloc memory from pool.
			 *
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: void* alloc(void){
			
			}
			
			/**
			 *  Alloc memory from pool and copy element.
			 *
			 *  @element Element pointer.
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: void* add(void* element){

			}
			
			/**
			 *  Free this element memory.	
			 *
			 *  @element Element pointer.
			 *  @return true if this poll found element and remove.
			 */
			public: bool remove(void* element){
			
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
			private: inline bool isBlockFlagFree(uint32_t blockNum, uint32_t flagNum){
				return (((this->blockPoolMemory.block.flagBlock[blockNum]&(1<<flagNum)))?false:true);
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
