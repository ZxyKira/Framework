/* *****************************************************************************************
 *    File Name   :base.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_hal_base_hpp_
#define frameworl_hal_base_hpp_

#include <stdbool.h>
#include <stdint.h>
#include "../lang/Object.hpp"

namespace framework{
  namespace hal{
    class Base;
  }
}

class framework::hal::Base : public framework::lang::Object{
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
   *  initialze hardware;
   */
  public: virtual bool init(void){
		return false;
	}
  
  /**
   *  uninitialze hardware.
   */
  public: virtual bool deinit(void){
		return false;
	}
  
  /**
   *  get hardware initialzed status.
   * 
   * @return false = not init, true = initd
   */
  public: virtual bool isInit(void){
		return false;
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
	public: Base(void) : framework::lang::Object(){
		return;
	}
	
	public: ~Base(){
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

/* *****************************************************************************************
 *    Inline function
 */ 


#endif //frameworl_hal_base_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
