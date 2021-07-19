/* *****************************************************************************************
 *    File Name   :Pool.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_Pool_hpp_
#define framework_util_Pool_hpp_

#include <stdint.h>
#include "../lang/Object.hpp"

namespace framework{
	namespace util{
		class Pool;
	}
}


class framework::util::Pool : public framework::lang::Object{
	
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
	public: virtual uint32_t elementSize(void){return 0;};
	
	/**
	 *  Returns this pool's capacity.
	 *
	 *  @return The capacity of this pool.
	 */
	public: virtual uint32_t capacity(void){return 0;};
	
	/**
	 *  Returns the number of elements in this pool.
	 *
	 *  @return the number of elements in this pool.
	 */
	public: virtual uint32_t size(void){return 0;};
	
	/**
	 *  Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
	 */
	public: virtual void clear(void){};
	
	/**
	 *  Returns true if this pool contains no elements.
	 *
	 *  @return true if this pool contains no elements.
	 */
	public: virtual bool isEmpty(void){return 0;};
	
	/**
	 *  Alloc memory from pool.
	 *
	 *  @return element pointer if pool not full, otherwise null pointer.
	 */
	public: virtual void* alloc(void){return 0;};
	
	/**
	 *  Alloc memory from pool and copy element.
	 *
	 *  @element Element pointer.
	 *  @return element pointer if pool not full, otherwise null pointer.
	 */
	public: virtual void* add(void* elenemt){return 0;};
	
	/**
	 *  Free this element memory.	
	 *
	 *  @element Element pointer.
	 *  @return true if this poll found element and remove.
	 */
	public: virtual bool remove(void* element){return false;};
	
	
	/**
	 *  Performs the given action for each entry in this map until all entries have been processed.
	 *
	 *  @action The action to be performed for each entry.
	 */
	public: virtual void forEach(void(*action)(void* element)){};
	
	
	/* **************************************************************************************
	 *  Abstract method <Protected>
	 */

	/* **************************************************************************************
	 *  Construct Method
	 */
	
	public: Pool(void){
		return;
	}

	public: ~Pool(){
		return;
	}

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
 
 
#endif //framework_util_Pool_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
