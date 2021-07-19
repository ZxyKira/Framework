/* *****************************************************************************************
 *		File Name	 :TimerTask.hpp
 *		Create Date :2021-07-19
 *		Modufy Date :
 *		Information :
 */

#ifndef framework_util_TimerTask_hpp_
#define framework_util_TimerTask_hpp_

#include <stdint.h>

#include "../lang/Object.hpp"


namespace framework{
	namespace util{
		class Timer;
		class TimerTask;
	}
}



class framework::util::TimerTask : public framework::lang::Object{
	/* **************************************************************************************
	 *	Variable <Public>
	 */
	public: friend class Timer;
	
	
	/* **************************************************************************************
	 *	Variable <Protected>
	 */

	/* **************************************************************************************
	 *	Variable <Private>
	 */
	private: uint32_t delay;
	private: uint32_t period;


	/* **************************************************************************************
	 *	Abstract method <Public>
	 */
	public: virtual void run(void){};

	
	/* **************************************************************************************
	 *	Abstract method <Protected>
	 */

	/* **************************************************************************************
	 *	Construct Method
	 */
	public: TimerTask(void){}
		
	public: ~TimerTask(void){}

	/* **************************************************************************************
	 *	Public Method <Static>
	 */

	/* **************************************************************************************
	 *	Public Method <Override>
	 */

	/* **************************************************************************************
	 *	Public Method
	 */
	
	/**
	 *  Cancels this timer task. If the task has been scheduled for one-time execution and has 
	 *  not yet run, or has not yet been scheduled, it will never run. If the task has been 
	 *  scheduled for repeated execution, it will never run again. (If the task is running 
	 *  when this call occurs, the task will run to completion, but will never run again.)
	 *
	 *  Note that calling this method from within the run method of a repeating timer task
   *	absolutely guarantees that the timer task will not run again.
	 *
	 *  This method may be called repeatedly; the second and subsequent calls have no effect.
	 *
	 *  @return true if this task is scheduled for one-time execution and has not yet run, 
	 *          or this task is scheduled for repeated execution. Returns false if the task 
	 *          was scheduled for one-time execution and has already run, or if the task was 
	 *          never scheduled, or if the task was already cancelled. (Loosely speaking, this 
	 *          method returns true if it prevents one or more scheduled executions from taking 
	 *          place.)
	 */
	public: bool cancel(void){
		if((this->delay == 0) & (this->period == 0))
			return false;
		
		this->delay = 0;
		this->period = 0;
		
		return true;
	}

	/* **************************************************************************************
	 *	Protected Method <Static>
	 */

	/* **************************************************************************************
	 *	Protected Method <Override>
	 */

	/* **************************************************************************************
	 *	Protected Method
	 */

	/* **************************************************************************************
	 *	Private Method <Static>
	 */

	/* **************************************************************************************
	 *	Private Method <Override>
	 */
	 
	/* **************************************************************************************
	 *	Private Method
	 */
};

 
#endif //framework_util_TimerTask_hpp_
/* *****************************************************************************************
 *		End of file
 */ 
