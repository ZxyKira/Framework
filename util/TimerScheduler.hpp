/* *****************************************************************************************
 *    File Name   :TimerScheduler.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_TimerScheduler_hpp_
#define framework_util_TimerScheduler_hpp_

#include "..\hal\Timer.hpp"

#include "BlockPool.hpp"
#include "Timer.hpp"
#include "TimerTask.hpp"


namespace framework{
	namespace util{
		class TimerScheduler;
	}
}



class framework::util::TimerScheduler : public framework::util::Timer, private framework::util::BlockPool{
	/* **************************************************************************************
	 *  Variable <Public>
	 */

	/* **************************************************************************************
	 *  Variable <Protected>
	 */

	/* **************************************************************************************
	 *  Variable <Private>
	 */
	private: framework::hal::Timer* timer;
	private: bool isStart;

	
	/* **************************************************************************************
	 *  Abstract method <Public>
	 */

	/* **************************************************************************************
	 *  Abstract method <Protected>
	 */

	/* **************************************************************************************
	 *  Construct Method
	 */
	public:	TimerScheduler(void* buffer, uint32_t capacity) : 
		                     framework::util::Timer(), 
		                     framework::util::BlockPool(buffer, 4, capacity){

		this->timer = NULL;
		this->isStart = false;
		
		return;
	}
	
	public:	~TimerScheduler(){
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
	public:	virtual bool schedule(framework::util::TimerTask* task, uint32_t delay){
		return this->scheduleAtFixedRate(task, delay, 0);
	}
	
	/**
	 *
	 *
	 *  @task
	 *  @delay
	 *  @period
	 *  @return true successful
	 */
	public: virtual bool scheduleAtFixedRate(framework::util::TimerTask* task, uint32_t delay, uint32_t period){
		if(!this->isStart)
			return false;
		
		if(framework::util::Timer::isTimerTaskRunning(task))
			return false;
		
		void* result = framework::util::BlockPool::add(task);
		if(result == 0x00000000)
			return false;
		
		framework::util::Timer::setTimerTaskDelayPeriod(task, delay, period);
		return true;
	}
	
	/**
	 *
	 */
	public: bool start(uint32_t baseTimeMs){
		if(this->timer == NULL)
			return false;
		
		if(this->isStart)
			return false;
		
		this->isStart = true;
		
		
		return true;
	}
	
	/**
	 *
	 */
	public: bool start(framework::hal::Timer& timer, uint32_t baseTimeMs){
		if(this->isStart)
			return false;
		
		this->timer = &timer;
		return this->start(baseTimeMs);
	}
	
	/**
	 *
	 */
	public: void stop(void){
		this->isStart = false;
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
	private: void timerExecute(framework::hal::Timer& base, void* attachment){
		
	}
		
};
 
#endif //framework_util_TimerScheduler_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
