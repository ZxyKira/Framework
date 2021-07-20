/* *****************************************************************************************
 *    File Name   :Stream.h
 *    Create Date :2021-07-20
 *    Modufy Date :
 *    Information :
 */
 
#ifndef framework_io_Stream_hpp_
#define framework_io_Stream_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "InputStream.hpp"
#include "OutputStream.hpp"



namespace framework{
  namespace io{
    class Stream;
  }
}

class framework::io::Stream : public framework::io::OutputStream, 
                                     framework::io::InputStream{
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
  public: virtual bool isOpen(){
		return false;
	}
	
  public: virtual void close(){
		return;
	}
																			 
																			 
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: Stream(void) : framework::io::OutputStream(), 
                         framework::io::InputStream(){
    
    return;
  }
  
  public: ~Stream(){
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

#endif //framework_io_Stream_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
