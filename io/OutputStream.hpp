/* *****************************************************************************************
 *    File Name   :OutputStream.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_io_OutputStream_hpp_
#define framework_io_OutputStream_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "../lang/Object.hpp"

namespace framework{
	namespace io{
		class OutputStream;
	}
}

class framework::io::OutputStream : public framework::lang::Object{
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
  public: virtual void flush(void){
		return;
	}
	
	/**
	 *  write blocking
	 */
  public: virtual bool write(void* data, int length){
		return false;
	}
	
	/**
	 *  write nonBlocking
	 */
  public: virtual bool write(void* data, int lengthl, void* attachment, void(*execute)(OutputStream*, void*)){
		return false;
	}
	
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: OutputStream(void){
		return;
	}
	
	public: ~OutputStream(){
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

#endif //framework_io_OutputStream_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
