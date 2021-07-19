/* *****************************************************************************************
 *    File Name   :InputStream.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_io_InputStream_hpp_
#define framework_io_InputStream_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "../lang/Object.hpp"

namespace framework{
	namespace io{
		class InputStream;
	}
}

class framework::io::InputStream{
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
	 *
	 */
  public: virtual int available(void){
		return 0;
	}
	
	/**
	 *	read sync
	 */
  public: virtual int read(void* data, int length){
		return 0;
	}
		
	/**
	 *	read async
	 */
  public: virtual int read(void* data, int lengthl, void* attachment, void(*execute)(InputStream*, void*)){
		return 0;
	}
		
	/**
	 *	
	 */
  public: virtual int skip(int skip){
		return 0;
	}
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
	public: InputStream(void){
		return;
	}
	
	public: ~InputStream(){
		return;
	}
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

#endif //framework_io_InputStream_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
