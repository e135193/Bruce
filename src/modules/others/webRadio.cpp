#include "webRadio.h"
#include <Audio.h>
#include "core/mykeyboard.h"
#include "core/utils.h"

#if defined(HAS_NS4168_SPKR)

static TaskHandle_t RadioHandlerTask = NULL;
Audio audio;

bool deletetask;

static void TaskRadioHandler(void *parameter)
{
    audio.setPinout(I2S_BCLK, I2S_WCLK, I2S_DOUT);
    audio.setVolume(21);
    audio.connecttohost((char*)parameter);

    padprintln("");
    padprintln((char*)parameter);
    padprintln("Web Radio Streaming...");

    while (deletetask)
    {
        audio.loop();
    }
    vTaskDelete(NULL);
}

void WebRadio(const char *RadioCh)
{
  Serial.println("Radio Task is started.");
  Serial.println(RadioCh);

  drawMainBorderWithTitle("Web Radio", true);

  while(WiFi.status() != WL_CONNECTED)
  {
    padprint("Please Connect to the internet");
    if(check(EscPress)) goto END;
    delay(100);
  }

    xTaskCreatePinnedToCore(TaskRadioHandler,     // Function Name: Task_InputHandler runs forever
        "RadioHandler",                           // Name of task
        4096,                                     // Stack size of task (minimum 768 for empty task)
        (void *)RadioCh,                          // Task Parameter
        1,                                        // Task Priority
        &RadioHandlerTask,                        // Task handle for tracking task
        0);                                       // Runs task at CPU Core 0

    while(!check(EscPress))
    {
        delay(10);
    }

END:
    deletetask = 0;
    Serial.println("Radio app stopped");
}

void WebRadio_menu() {

  std::vector<Option> options;

  for (const auto& entry : bruceConfig.webRadioCh) {
      options.emplace_back(std::string(entry.menuName.c_str()), [=]() { WebRadio(entry.content.c_str()); });
  }
  options.emplace_back("Main menu", [=]() { backToMenu(); });

  loopOptions(options);
}

#endif