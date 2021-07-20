/* *****************************************************************************************
 *    File Name   :DoublePredicate.hpp
 *    Create Date :2021-07-20
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_function_DoublePredicate_hpp_
#define frameworl_function_DoublePredicate_hpp_

#include <stdbool.h>
#include <stdint.h>
#include "../lang/Object.hpp"

namespace framework{
  namespace function{
    class DoublePredicate;
  }
}

class framework::function::DoublePredicate : public framework::lang::Object{
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
	
  public: virtual bool test(double value){
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
	public: DoublePredicate(void) : framework::lang::Object(){
		return;
	}
	
	public: ~DoublePredicate(){
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


#endif //frameworl_function_DoublePredicate_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
