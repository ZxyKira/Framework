/* *****************************************************************************************
 *    File Name   :BlockPool.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_BlockPool_hpp_
#define framework_util_BlockPool_hpp_


#include <stdint.h>

namespace framework{
	namespace util{
		
		
		class BlockPool{
			private: uint32_t blockSize;
			private: uint32_t blockCount;
			private: uint8_t* blockBuffer;
			
			public: BlockPool(void* buffer, uint32_t size, uint32_t count){
				this->blockSize = size;
				this->blockCount = count;
				this->blockBuffer = (uint8_t*)buffer;
			}
			
			public: uint32_t getBlockSize(void){
				return this->blockSize;
			}
			
			public: uint32_t getBlockCount(void){
				return this->blockCount;
			}
			
		
		};

		
	}
}

 
 
#endif //framework_util_BlockPool_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
