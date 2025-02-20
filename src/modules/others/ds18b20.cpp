#include "ds18b20.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "core/display.h"
#include "core/mykeyboard.h"


void DS18B20(void){

  String temperature;
  OneWire oneWire(DS18B20_PIN);
  DallasTemperature sensors(&oneWire);
  DeviceAddress tempDeviceAddress; 

  sensors.begin();

  tft.fillScreen(bruceConfig.bgColor);

  while (!check(EscPress))
  {
    sensors.requestTemperatures(); 
    float temperatureC = sensors.getTempCByIndex(0);
    float temperatureF = sensors.getTempFByIndex(0);

    drawMainBorderWithTitle("Temperature", true);
    tft.setTextSize(4);
    tft.setTextColor(bruceConfig.priColor, bruceConfig.bgColor);

    temperature = String(temperatureC,3) + " C";
    tft.drawString(temperature, 60, 60, 1);

    temperature = String(temperatureF,3) + " F";
    tft.drawString(temperature, 60, 110, 1);

    delay(2000);
    }
}