/* *****************************************************************************************
 *    File Name   :fw_timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-25
 *    Information :
 */
 
#ifndef FW_TIMER_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"
#include "version.h"



/* *****************************************************************************************
 *    Macro
 */ 

/*----------------------------------------
 *  FW_ADC_REQ_FW_ADC_CHANNEL_VERSION
 *----------------------------------------*/
#define FW_ADC_REQ_FW_BASE_VERSION VERSION_DEFINEE(1,0,0)
#if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION)
  #if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION) == 2
      #error "FW_BASE_VERSION under 1.0.x"
  #else
    #warning "FW_BASE_VERSION revision under 1.0.0"
  #endif
#endif



/*----------------------------------------
 *  FW_TIMER_VERSION
 *----------------------------------------*/
#define FW_TIMER_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_TIMER_API_LINK
 *----------------------------------------*/
#define FW_TIMER_API_LINK(profix)    \
{                                    \
  .FW_API_LINK(profix, init),        \
  .FW_API_LINK(profix, deinit),      \
  .FW_API_LINK(profix, startAtTick), \
  .FW_API_LINK(profix, startAtTime), \
  .FW_API_LINK(profix, stop),        \
  .support = {                       \
    .taskScheduler = FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix), \
  },                                                             \
}



/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_timer_handle_t fw_timer_handle_t;



/* *****************************************************************************************
 *    Typedef Function
 */ 
typedef void (*fw_timer_event_execute_t)(fw_timer_handle_t* _this, void* attachment);



/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 
 
/*----------------------------------------
 *  fw_timer_api_t
 *----------------------------------------*/
struct fw_timer_api_t{
  bool  (*init)             (fw_timer_handle_t* _this);
  bool  (*deinit)           (fw_timer_handle_t* _this);
  bool  (*isEnable)         (fw_timer_handle_t* _this);
  bool  (*startAtTick)      (fw_timer_handle_t* _this, uint32_t tick, fw_timer_event_execute_t execute, void* attachment);
  bool  (*startAtTime)      (fw_timer_handle_t* _this, uint32_t us, fw_timer_event_execute_t execute, void* attachment);
  bool  (*stop)             (fw_timer_handle_t* _this);
  
  struct{
    FW_STRUCT_TASK_SCHEDULER(fw_timer_handle_t*) taskScheduler;
  }support;
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_timer_handle_t
 *----------------------------------------*/
typedef struct _fw_timer_handle_t{
  void* memory;
  const struct fw_timer_api_t* api;
}fw_timer_handle_t; 
 


/* *****************************************************************************************
 *    Inline Function
 */ 



#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_TIMER_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
