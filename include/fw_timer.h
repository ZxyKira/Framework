/* *****************************************************************************************
 *    File Name   :fw_timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-16
 *    Information :
 */
 
#ifndef fw_timer_H_
#define fw_timer_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_timer_api_t fw_timer_api_t;
typedef struct _fw_timer_handle_t fw_timer_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_timer_event_execute_t)(fw_timer_handle_t* _this, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_timer_handle_t
 */ 
typedef struct _fw_timer_handle_t{
  void* memory;
  const fw_timer_api_t* api;
}fw_timer_handle_t; 
 
/* *****************************************************************************************
 *    Struct - fw_timer_api_t
 */ 
typedef struct _fw_timer_api_t{
  bool  (*init)             (fw_timer_handle_t* _this);
  bool  (*deinit)           (fw_timer_handle_t* _this);
  bool  (*isEnable)         (fw_timer_handle_t* _this);
  bool  (*startAtTick)      (fw_timer_handle_t* _this, uint32_t tick, fw_timer_event_execute_t execute, void* attachment);
  bool  (*startAtTime)      (fw_timer_handle_t* _this, uint32_t us, fw_timer_event_execute_t execute, void* attachment);
  bool  (*stop)             (fw_timer_handle_t* _this);
  
  struct{
    FW_STRUCT_TASK_SCHEDULER(fw_timer_handle_t*) taskScheduler;
  }support;
}fw_timer_api_t;

/* *****************************************************************************************
 *    Macro
 */ 
#define FW_TIMER_API_LINK(profix, name) \
fw_timer_api_t name = {                 \
  .FW_API_LINK(profix, init),           \
  .FW_API_LINK(profix, deinit),         \
  .FW_API_LINK(profix, startAtTick),    \
  .FW_API_LINK(profix, startAtTime),    \
  .FW_API_LINK(profix, stop),           \
  .support = {                                                  \
    .FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix, taskScheduler), \
  },                                                            \
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_timer_H_
/* *****************************************************************************************
 *    End of file
 */ 
