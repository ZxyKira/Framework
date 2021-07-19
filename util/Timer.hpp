/* *****************************************************************************************
 *    File Name   :Timer.hpp
 *    Create Date :2021-07-19
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_Timer_hpp_
#define framework_util_Timer_hpp_

#include <stdint.h>

#include "../lang/Object.hpp"
#include "TimerTask.hpp"

namespace framework{
	namespace util{
		class Timer;
	}
}

class framework::util::Timer : public framework::lang::Object{
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
	 *  Terminates this timer, discarding any currently scheduled tasks. Does not interfere 
	 *  with a currently executing task (if it exists). Once a timer has been terminated, 
	 *  its execution thread terminates gracefully, and no more tasks may be scheduled on it.
	 *	Note that calling this method from within the run method of a timer task that was 
	 *  invoked by this timer absolutely guarantees that the ongoing task execution is the last 
	 *  task execution that will ever be performed by this timer.
	 *
	 *  This method may be called repeatedly; the second and subsequent calls have no effect.
	 */
	public: virtual void cancel(){
		return;
	}
	
	/**
	 *  Removes all cancelled tasks from this timer's task queue. Calling this method has no 
	 *  effect on the behavior of the timer, but eliminates the references to the cancelled 
	 *  tasks from the queue. If there are no external references to these tasks, they become 
	 *  eligible for garbage collection.
	 *
	 *  Most programs will have no need to call this method. It is designed for use by the rare 
	 *  application that cancels a large number of tasks. Calling this method trades time for 
	 *  space: the runtime of the method may be proportional to n + c log n, where n is the 
	 *  number of tasks in the queue and c is the number of cancelled tasks.
   * 
	 *  Note that it is permissible to call this method from within a a task scheduled on this 
	 *  timer.
	 * 
	 *  @return the number of tasks removed from the queue.
	 */
	public: virtual uint32_t purge(){
		return 0;
	}
	
	/**
	 *  Schedules the specified task for execution after the specified delay.
	 *
	 *  @task task to be scheduled.
	 *  @delay delay in milliseconds before task is to be executed.
	 *  @return true successful, false if task was already scheduled or cancelled.
	 */
	public: virtual bool schedule(framework::util::TimerTask* task, uint32_t delay){
		return false;
	}
	
	/**
	 *  
	 */
	public: virtual bool scheduleAtFixedRate(framework::util::TimerTask* task, uint32_t delay, uint32_t period){
		return false;
	}
	
	/* **************************************************************************************
	 *  Abstract method <Protected>
	 */

	/* **************************************************************************************
	 *  Construct Method
	 */
	public: Timer(void){};
	
	public: ~Timer(void){};
		
		
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

  protected: bool isTimerTaskRunning(TimerTask* timerTask){
		if((timerTask->delay == 0) & (timerTask->period == 0))
			return false;
		
		else
			return true;
	}

	protected: uint32_t getTimerTaskDelay(TimerTask* timerTask){
		return timerTask->delay;
	}
	
	protected: uint32_t getTimerTaskPeriod(TimerTask* timerTask){
		return timerTask->period;
	}
	
	protected: void setTimerTaskDelay(TimerTask* timerTask, uint32_t delay){
		timerTask->delay = delay;
	}
	
	protected: void setTimerTaskPeriod(TimerTask* timerTask, uint32_t period){
		timerTask->period = period;
	}
	
	protected: void setTimerTaskDelayPeriod(TimerTask* timerTask, uint32_t delay, uint32_t period){
		timerTask->delay = delay;
		timerTask->period = period;
	}

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

 
 
#endif //framework_util_Timer_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
