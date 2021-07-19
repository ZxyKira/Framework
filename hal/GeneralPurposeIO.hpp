/* *****************************************************************************************
 *    File Name   :GeneralPurposeIO.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :2017-07-19
 *    Information :
 */

#ifndef framework_hal_GeneralPurposeIO_hpp_
#define framework_hal_GeneralPurposeIO_hpp_

#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"
#include "Pin.hpp"
#include "GeneralPurposePin.hpp"


namespace framework{
	namespace hal{
		class GeneralPurposeIO;
	}
}



class framework::hal::GeneralPurposeIO : public framework::hal::Base{
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
   * @param port GPIO port.
   */
  public: virtual uint32_t read(uint32_t port){
		return 0;
	}
  
  /**
   *
   * @param port GPIO port.
   * @param value GPIO write value.
   */
  public: virtual void set(uint32_t port, uint32_t value){
		return;
	}
  
  /**
   *  
   */
  public: virtual void clear(uint32_t port, uint32_t mask){
		return;
	}
  
  /**
   *  
   */
  public: virtual void toggle(uint32_t port, uint32_t mask){
		return;
	}
  
  /**
   *  
   */
  public: virtual void dir(uint32_t port, uint32_t value){
		return;
	}
  
  /**
   *  
   */
  public: virtual void dirClear(uint32_t port, uint32_t mask){
		return;
	}
  
  /**
   *  
   */
  public: virtual void dirSet(uint32_t port, uint32_t mask){
		return;
	}
  
  /**
   *  
   */
  public: virtual framework::hal::GeneralPurposePin getPin(uint32_t port, uint32_t pin){
  	return framework::hal::GeneralPurposePin();
  };
  
  /**
   *  
   */
  public: virtual framework::hal::GeneralPurposePin getPin(framework::hal::Pin::Pin pin){
  	return framework::hal::GeneralPurposePin();
  }
	
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: GeneralPurposeIO(void) : framework::hal::Base(){
		return;
	}
	
	public: ~GeneralPurposeIO(){
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

#endif //framework_hal_GeneralPurposeIO_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
