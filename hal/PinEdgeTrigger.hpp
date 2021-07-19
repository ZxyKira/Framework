/* *****************************************************************************************
 *    File Name   :PinEdgeTrigger.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_PinEdgeTrigger_hpp_
#define framework_hal_PinEdgeTrigger_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "Base.hpp"


namespace framework{
	namespace hal{
		class PinEdgeTrigger;
	}
}

class framework::hal::PinEdgeTrigger : public framework::hal::Base{
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
  public: virtual bool enableRise(void* attachment, void(*execute)(PinEdgeTrigger*, void*)){
		return false;
	}
	
  public: virtual bool enableFall(void* attachment, void(*execute)(PinEdgeTrigger*, void*)){
		return false;
	}
	
  public: virtual void disableRise(void){
		return;
	}
	
  public: virtual void disableFall(void){
		return;
	}
	
  public: virtual void disableAll(void){
		return;
	}
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: PinEdgeTrigger(void) : framework::hal::Base(){
		return;
	}
	
	public: ~PinEdgeTrigger(){
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

#endif //framework_hal_PinEdgeTrigger_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
