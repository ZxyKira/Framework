/* *****************************************************************************************
 *    File Name   :GeneralPurposePin.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_GeneralPurposePin_hpp_
#define framework_hal_GeneralPurposePin_hpp_

#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"


namespace framework{
	namespace hal{
		class GeneralPurposePin;
	}
}

class framework::hal::GeneralPurposePin{
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
   * Set io pin to high or low.
   *
   * @param value false = low, true = true.
   */
  public: virtual void setValue(bool value){
		return;
	}
  
  /**
   * Set io pin to high.
   */
  public: virtual void setHigh(void){
		return;
	}
  
  /**
   * Set io pin to low.
   */
  public: virtual void setLow(void){
		return;
	}
  
  /**
   * Set io not logic.
   */
  public: virtual void setToggle(void){
		return;
	}
  
  /**
   * Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  public: virtual void setDir(bool dir){
		return;
	}
  
  /**
   * Set io direction to input.
   */
  public: virtual void setInput(void){
		return;
	}
  
  /**
   * Set io direction to output.
   */
  public: virtual void setOutput(void){
		return;
	}
  
  /**
   * Get io read value.
   *
   * @return false = low, true = high.
   */
  public: virtual bool getValue(void){
		return false;
	}
  
	/**
   * Get io ditrction.
   *
   * @return false = input, true = output.
   */
  public: virtual bool getDir(void){
		return false;
	}
  
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
	public: GeneralPurposePin(void){
		return;
	}
	
	public: ~GeneralPurposePin(){
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

#endif //framework_hal_GeneralPurposePin_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
