/* *****************************************************************************************
 *    File Name   :fw_io.h
 *    Create Date :2020-08-12
 *    Modufy Date :2020-11-30
 *    Information :
 */
#ifndef fw_io_H_
#define fw_io_H_

#include <stdint.h>
#include <stdbool.h>

#include "fw_io_pin.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_io_api_t fw_io_api_t;

/* *****************************************************************************************
 *    Function Type
 */ 

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_io_handle_t{
  void* memory;
  const fw_io_api_t *API;
}fw_io_handle_t;

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_io_api_t{
  bool                (*init)      (fw_io_handle_t handle);
  bool                (*deinit)    (fw_io_handle_t handle);
  uint32_t            (*read)      (fw_io_handle_t handle, const uint16_t port);
  void                (*set)       (fw_io_handle_t handle, const uint16_t port, const uint32_t mask);
  void                (*clear)     (fw_io_handle_t handle, const uint16_t port, const uint32_t mask);
  void                (*toggle)    (fw_io_handle_t handle, const uint16_t port, const uint32_t mask);
  void                (*dir)       (fw_io_handle_t handle, const uint16_t port, const uint32_t val);
  void                (*dirClear)  (fw_io_handle_t handle, const uint16_t port, const uint32_t mask);
  void                (*dirSet)    (fw_io_handle_t handle, const uint16_t port, const uint32_t mask);
  fw_io_pin_handle_t  (*getIoPin)  (fw_io_handle_t handle, const uint16_t port, const uint16_t pin);
}fw_io_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_H_
/* *****************************************************************************************
 *    End of file
 */ 
