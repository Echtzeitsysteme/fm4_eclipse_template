#include "acceleration.h"
#include "acceleration_app.h"
#include "rgb_led.h"
#include "display.h"
#include "gfx.h"

static float cppp_orientationValues[3];

void AccelerationMain(){
  cppp_initLEDs();
  while(1){
    if(cppp_accelerationDataAvailable == 1){
      cppp_orientationValues[0] = ((float)((cppp_accelerationData[ACCELERATION_AXIS_X]))) / (float)cppp_sensitivity[ACCELERATION_AXIS_X];
      cppp_orientationValues[1] = ((float)((cppp_accelerationData[ACCELERATION_AXIS_Y]))) / (float)cppp_sensitivity[ACCELERATION_AXIS_Y];
      cppp_orientationValues[2] = ((float)((cppp_accelerationData[ACCELERATION_AXIS_Z]))) / (float)cppp_sensitivity[ACCELERATION_AXIS_Z];
      cppp_accelerationDataAvailable = 0;

      // Write your code here ...
    }
  }
}
