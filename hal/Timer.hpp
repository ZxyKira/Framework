/* *****************************************************************************************
 *    File Name   :Timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_Timer_hpp_
#define framework_hal_Timer_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "Base.hpp"

namespace framework{
	namespace hal{	
		class Timer;
	}
}

class framework::hal::Timer : public framework::hal::Base{
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
	
  public: bool startAtTick(uint32_t tick, void* attachment,  void(execute)(Timer&, void*)){
		return false;
	}
	
  public: bool startAtTime(uint32_t us, void* attachment, void(execute)(Timer&, void*)){
		return false;
	}
	
  public: void cancel(void){
		return;
	}
	
  public: bool isBusy(void){
		return true;
	}
	
  public: int getRemaining(void){
		return 0;
	}
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: Timer(void) : Base(){
		return;
	}
	
	public: ~Timer(){
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

#endif //framework_hal_Timer_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
