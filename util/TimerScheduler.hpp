/* *****************************************************************************************
 *    File Name   :TimerScheduler.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_TimerScheduler_hpp_
#define framework_util_TimerScheduler_hpp_

#include "..\hal\timer.hpp"


namespace framework{
	namespace util{
		
		class TimerTask;
		
		
		class TimerBase{
			public: virtual bool cancel(TimerTask* timerTask);
		};
		
		
		class TimerTask{
			private: framework::util::TimerBase* timerBase;
			
			public:	bool registor(TimerBase* timerBase){
				
				if(this->timerBase == 0x00000000){
					this->timerBase = timerBase;
					return true;
				
				}else{
					return false;
				
				}
				
			}
			
			public: void cancel(void){
				if(this->timerBase == 0x00000000)
					return;
				
				this->timerBase->cancel(this);
			}
			
			public: virtual void run(void);	 
		};
		
		
		
		class TimerScheduler : public TimerBase{
			private: framework::hal::Timer::Timer* timer;
			
			public:
				TimerScheduler(framework::hal::Timer::Timer* timer){
					this->timer = timer;
				}
				
				bool schedule(framework::util::TimerTask* task, long delay){
					if(!task->registor(this))
						return false;
					
					return true;
				}
				
		};


	}
}

 
 
#endif //framework_util_TimerScheduler_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
