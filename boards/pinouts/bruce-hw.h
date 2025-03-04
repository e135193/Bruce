#ifndef __T_BRUCE_HW_H__
#define __T_BRUCE_HW_H__
#define T_EMBED_1101

#include <stdint.h>
#include "soc/soc_caps.h"

// Main I2C Bus
#define SPI_SS_PIN      -1
#define SPI_MOSI_PIN    9
#define SPI_MISO_PIN    10
#define SPI_SCK_PIN     11
static const uint8_t SS    = SPI_SS_PIN;
static const uint8_t MOSI  = SPI_MOSI_PIN;
static const uint8_t SCK   = SPI_MISO_PIN;
static const uint8_t MISO  = SPI_SCK_PIN;

// Set Main I2C Bus
#define GROVE_SDA 8
#define GROVE_SCL 18
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;


// TFT_eSPI display
#define ST7789_DRIVER   1
#define USER_SETUP_LOADED
#define USE_HSPI_PORT
#define SMOOTH_FONT     1
#define TFT_INVERSION_ON
#define TFT_WIDTH       170
#define TFT_HEIGHT      320
#define TFT_BL          21   
#define TFT_MISO        SPI_MISO_PIN   
#define TFT_MOSI        SPI_MOSI_PIN
#define TFT_SCLK        SPI_SCK_PIN
#define TFT_CS          41 
#define TFT_DC          16
#define TFT_RST         40
#define SPI_FREQUENCY   80000000
#define SPI_READ_FREQUENCY 20000000

// Display Setup
#define HAS_SCREEN
#define ROTATION        3
#define MINBRIGHT       (uint8_t) 1
#define PIN_POWER_ON    -1

// Font Sizes
#define FP  1
#define FM  2
#define FG  3

// SD Card
#define SDCARD_CS   13
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN
#define SDCARD_SCK  SPI_SCK_PIN

// NRF24
#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN    47
#define NRF24_SS_PIN    17
#define NRF24_MOSI_PIN  SPI_MISO_PIN
#define NRF24_SCK_PIN   SPI_SCK_PIN
#define NRF24_MISO_PIN  SPI_MOSI_PIN

// CC1101
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN 3 
#define CC1101_GDO2_PIN 38
#define CC1101_SW1_PIN  -1
#define CC1101_SW0_PIN  -1
#define CC1101_SS_PIN   12
#define CC1101_MISO_PIN SPI_MISO_PIN
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN  SPI_SCK_PIN

//PN532
#define PN532_RF_REST   -1
#define PN532_IRQ       -1

// RGB LED
#define HAS_RGB_LED         1
#define RGB_LED             14
#define LED_TYPE            WS2812B
#define LED_ORDER           GRB
#define LED_TYPE_IS_RGBW    0
#define LED_COUNT           8

// I2S INTERFACE
#define HAS_NS4168_SPKR
#define I2S_BCLK    46
#define I2S_WCLK    39
#define I2S_DOUT    7		// Speaker
#define I2S_DIN     42		// Microphone
#define I2S_MCLK    RGB_LED

// Serial
#define SERIAL_TX 43 
#define SERIAL_RX 44
static const uint8_t TX = SERIAL_TX;
static const uint8_t RX = SERIAL_RX;
#define TX1 TX
#define RX1 RX

// Encoder
#define HAS_ENCODER
#define ENCODER_INA	5
#define ENCODER_INB	4
#define ENCODER_KEY	0
#define HAS_BTN	    1
#define BTN_ALIAS	'"Mid"'
#define SEL_BTN	    ENCODER_KEY
#define BK_BTN	    6
#define BTN_ACT	    LOW

// IR
#define LED	        2		
#define RXLED	    1 
#define LED_ON	    HIGH
#define LED_OFF	    LOW

// RFID 
#define RFID125_RX_PIN	    SERIAL_RX
#define RFID125_TX_PIN  	SERIAL_TX

// DS18B20 Temperature Sensor
#define DS18B20_PIN         15

// BadUSB 
#define USB_as_HID          1

#endif /* Pins_Arduino_h */
