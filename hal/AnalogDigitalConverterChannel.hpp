/* *****************************************************************************************
 *    File Name   :AnalogDigitalConverterChannel.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_AnalogDigitalConverterChannel_hpp_
#define framework_hal_AnalogDigitalConverterChannel_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "../lang/Object.hpp"

/* *****************************************************************************************
 *    Macro
 */ 

/* *****************************************************************************************
 *    Typedef List
 */ 

/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

namespace framework{
	namespace hal{
		class AnalogDigitalConverterChannel;
	}
}

class framework::hal::AnalogDigitalConverterChannel : public framework::lang::Object{
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
  public: virtual bool enable(void){
		return false;
	}
	
  public: virtual bool disable(void){
		return false;
	}
	
  public: virtual uint32_t read(void){
		return 0;
	}
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: AnalogDigitalConverterChannel(void) : framework::lang::Object(){
		return;
	}
	
	public: ~AnalogDigitalConverterChannel(void){
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

#endif //framework_hal_AnalogDigitalConverterChannel_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
