#include "powerSave.h"
#include "settings.h"

#ifdef HAS_WS2812_LED
#include "ws2812.h"
#endif

/* Turn off the display */
void turnOffDisplay() {
  setBrightness(0,false);
}

/* If the device screen is off, turn on, else just refresh sleep timer */
bool wakeUpScreen(){
  previousMillis = millis();
  if(isScreenOff){
    isScreenOff = false;
    dimmer = false;
    getBrightness();
    delay(200);
    return true;
  }else if(dimmer){
    dimmer = false;
    getBrightness();
    delay(200);
    return true;
  }
  return false;
}

/* Check if it's time to put the device to sleep */
void checkPowerSaveTime(){
  if(bruceConfig.dimmerSet!=0){
    if((millis() - previousMillis) >= (bruceConfig.dimmerSet * 1000) && dimmer == false && isSleeping == false){
      dimmer = true;
      setBrightness(5, false);
    }else if((millis() - previousMillis) >= ((bruceConfig.dimmerSet * 1000) + 5000) && isScreenOff == false && isSleeping == false){
      isScreenOff = true;
      #ifdef HAS_WS2812_LED
      ws2812_TurnOff();
      #endif
      turnOffDisplay();
    }
  }
}

/* Put device on sleep mode */
void sleepModeOn(){
  isSleeping = true;
  #ifdef HAS_WS2812_LED
  ws2812_TurnOff();
  #endif
  setCpuFrequencyMhz(80);
  turnOffDisplay();
  delay(200);
}

/* Wake up device */
void sleepModeOff(){
  isSleeping = false;
  #ifdef HAS_WS2812_LED
  ws2812_TurnOn();
  #endif
  setCpuFrequencyMhz(240);
  getBrightness();
  delay(200);
}
