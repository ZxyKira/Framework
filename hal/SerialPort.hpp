/* *****************************************************************************************
 *    File Name   :SerialPort.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_SerialPort_hpp_
#define framework_hal_SerialPort_hpp_

#include "stdint.h"
#include "stdbool.h"

#include "Base.hpp"
#include "..\io\InputStream.hpp"
#include "..\io\OutputStream.hpp"


namespace framework{
  namespace hal{
    class SerialPort;
  }
}


class framework::hal::SerialPort : public framework::hal::Base, 
                                   public framework::io::InputStream, 
                                   public framework::io::OutputStream{
        
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
  public: virtual bool setBaudrate(int baudrate){
		return false;
	}
	
  public: virtual int setBaudrate(void){
		return 0;
	}
	
  public: virtual bool setDatabit(int dataBit){
		return false;
	}
	
  public: virtual int getDatabit(void){
		return 0;
	}
	
  public: virtual bool open(void){
		return false;
	}
	
  public: virtual void close(void){
		return;
	}
	
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
  public: SerialPort(void) : framework::hal::Base(), framework::io::InputStream(), framework::io::OutputStream(){
		return;
	}
	
	public: ~SerialPort(){
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

#endif //framework_hal_SerialPort_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
