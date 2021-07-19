/* *****************************************************************************************
 *    File Name   :AnalogDigitalConverter.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_AnalogDigitalConverter_hpp_
#define framework_hal_AnalogDigitalConverter_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"
#include "AnalogDigitalConverterChannel.hpp"

namespace framework{
	namespace hal{
		class AnalogDigitalConverter;
	}
}

class framework::hal::AnalogDigitalConverter : public framework::hal::Base{
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
  public: virtual bool enableChannel(uint32_t channel){
		return false;
	}
	
  public: virtual bool disableChannel(uint32_t channel){
		return false;
	}
	
  public: virtual uint32_t read(uint32_t channel){
		return 0;
	}
	
  public: virtual framework::hal::AnalogDigitalConverterChannel getChannel(uint32_t channel){
		return framework::hal::AnalogDigitalConverterChannel();
	}
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: AnalogDigitalConverter(void) : framework::hal::Base(){
		return;
	}
	
	public: ~AnalogDigitalConverter(){
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


#endif //fw_adc_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
