/* *****************************************************************************************
 *    File Name   :Transfer.h
 *    Create Date :2021-07-20
 *    Modufy Date :
 *    Information :
 */
 
#ifndef framework_io_Transfer_hpp_
#define framework_io_Transfer_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "../lang/Object.hpp"

namespace framework{
  namespace io{
    class Transfer;
  }
}

class framework::io::Transfer : public framework::lang::Object{
	public: struct Packet{
		void* transfer;
		void* receiver;
		uint32_t length;
		uint32_t dummy;
	};
	
	
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
	 * Xfer
	 */
	public: virtual bool xfer(Packet &packet, void* attachment, void (execute)(Transfer&, void*)){
		return false;
	}	
	
	/**
	 * Xfer
	 */
	public: virtual bool xfer(Packet &packet){

	}	
	
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: Transfer(void) : framework::lang::Object(){
    
    return;
  }
  
  public: ~Transfer(){
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

#endif //framework_io_Transfer_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
