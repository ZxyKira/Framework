/* *****************************************************************************************
 *    File Name   :DoubleBinaryOperator.hpp
 *    Create Date :2021-07-20
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_function_DoubleBinaryOperator_hpp_
#define frameworl_function_DoubleBinaryOperator_hpp_

#include <stdbool.h>
#include <stdint.h>
#include "../lang/Object.hpp"

namespace framework{
  namespace function{
    class DoubleBinaryOperator;
  }
}

class framework::function::DoubleBinaryOperator : public framework::lang::Object{
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
	
  public: virtual double accept(double value){
		return;
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
	public: DoubleBinaryOperator(void) : framework::lang::Object(){
		return;
	}
	
	public: ~DoubleBinaryOperator(){
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


#endif //frameworl_function_DoubleBinaryOperator_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
