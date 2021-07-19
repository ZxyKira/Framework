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

	
	/* **************************************************************************************
	 *  Abstract method <Public>
	 */

	/* **************************************************************************************
	 *  Abstract method <Protected>
	 */

	/* **************************************************************************************
	 *  Construct Method
	 */
	public:	TimerScheduler(framework::hal::Timer* timer, void* buffer, uint32_t capacity) : 
		                     framework::util::Timer(), 
		                     framework::util::BlockPool(buffer, 4, capacity){

		this->timer = timer;
		
		
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
	 *
	 *
	 *  @task
	 *  @delay
	 *  @return true successful
	 */
	public:	bool schedule(framework::util::TimerTask* task, uint32_t delay){
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
	public: bool scheduleAtFixedRate(framework::util::TimerTask* task, uint32_t delay, uint32_t period){
		if(framework::util::Timer::isTimerTaskRunning(task))
			return false;
		
		void* result = framework::util::BlockPool::add(task);
		if(result == 0x00000000)
			return false;
		
		framework::util::Timer::setTimerTaskDelayPeriod(task, delay, period);
		return true;
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
 
#endif //framework_util_TimerScheduler_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
