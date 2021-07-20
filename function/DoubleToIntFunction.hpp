/* *****************************************************************************************
 *    File Name   :DoubleToIntFunction.hpp
 *    Create Date :2021-07-20
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_function_DoubleToIntFunction_hpp_
#define frameworl_function_DoubleToIntFunction_hpp_

#include <stdbool.h>
#include <stdint.h>
#include "../lang/Object.hpp"

namespace framework{
  namespace function{
    class DoubleToIntFunction;
  }
}

class framework::function::DoubleToIntFunction : public framework::lang::Object{
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
	
  public: virtual int applyAsInt(double value){
		return 0;
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
	public: DoubleToIntFunction(void) : framework::lang::Object(){
		return;
	}
	
	public: ~DoubleToIntFunction(){
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


#endif //frameworl_function_DoubleToIntFunction_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
