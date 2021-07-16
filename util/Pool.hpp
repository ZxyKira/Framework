/* *****************************************************************************************
 *    File Name   :Pool.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_Pool_hpp_
#define framework_util_Pool_hpp_


#include <stdint.h>

namespace framework{
	namespace util{
		
	/* ************************************
	 *  Class BlockPool
	 */
		class Pool{
			
			/* **************************************************************************************
			 *  Variable <Public>
			 */

			/* **************************************************************************************
			 *  Variable <Protected>
			 */

			/* **************************************************************************************
			 *  Variable <Private>
			 */

			/* **************************************************************************************
			 *  Abstract method <Public>
			 */
			
			/**
			 *	Returns this pool element size of byte
			 *
			 *  @return element size of byte.
			 */
			public: virtual uint32_t elementSize(void);
			
			/**
			 *  Returns this pool's capacity.
			 *
			 *  @return The capacity of this pool.
			 */
			public: virtual uint32_t capacity(void);
			
			/**
			 *  Returns the number of elements in this pool.
			 *
			 *  @return the number of elements in this pool.
			 */
			public: virtual uint32_t size(void);
			
			/**
			 *  Returns this pool's limit.
			 *
			 *  @return The limit of this pool.
			 */
			public: virtual uint32_t limit(void);
			
			/**
			 *  Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
			 */
			public: virtual void clear(void);
			
			/**
			 *  Returns true if this pool contains no elements.
			 *
			 *  @return true if this pool contains no elements.
			 */
			public: virtual bool isEmpty(void);
			
			/**
			 *  Alloc memory from pool.
			 *
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: virtual void* alloc(void);
			
			/**
			 *  Alloc memory from pool and copy element.
			 *
			 *  @element Element pointer.
			 *  @return element pointer if pool not full, otherwise null pointer.
			 */
			public: virtual void* add(void* elenemt);
			
			/**
			 *  Free this element memory.	
			 *
			 *  @element Element pointer.
			 *  @return true if this poll found element and remove.
			 */
			public: virtual bool remove(void* element);
			
			
			/* **************************************************************************************
			 *  Abstract method <Protected>
			 */

			/* **************************************************************************************
			 *  Construct Method
			 */

			/* **************************************************************************************
			 *  Public Method <Static>
			 */

			/* **************************************************************************************
			 *  Public Method <Override>
			 */

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
			
			
		};
	/* ************************************
	 *  End Class BlockPool
	 */
		
	}
}

 
 
#endif //framework_util_Pool_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
