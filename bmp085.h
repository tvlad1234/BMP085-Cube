#ifndef _BMP085_H
#define _BMP085_H

///Modify to match used chip!
#include "stm32f0xx_hal.h"


//Modes
#define BMP085_ULTRALOWPOWER 0 //!< Ultra low power mode
#define BMP085_STANDARD 1      //!< Standard mode
#define BMP085_HIGHRES 2       //!< High-res mode
#define BMP085_ULTRAHIGHRES 3  //!< Ultra high-res mode

//Calibration data registers
#define BMP085_CAL_AC1 0xAA    //!< R   Calibration data (16 bits)
#define BMP085_CAL_AC2 0xAC    //!< R   Calibration data (16 bits)
#define BMP085_CAL_AC3 0xAE    //!< R   Calibration data (16 bits)
#define BMP085_CAL_AC4 0xB0    //!< R   Calibration data (16 bits)
#define BMP085_CAL_AC5 0xB2    //!< R   Calibration data (16 bits)
#define BMP085_CAL_AC6 0xB4    //!< R   Calibration data (16 bits)
#define BMP085_CAL_B1 0xB6     //!< R   Calibration data (16 bits)
#define BMP085_CAL_B2 0xB8     //!< R   Calibration data (16 bits)
#define BMP085_CAL_MB 0xBA     //!< R   Calibration data (16 bits)
#define BMP085_CAL_MC 0xBC     //!< R   Calibration data (16 bits)
#define BMP085_CAL_MD 0xBE     //!< R   Calibration data (16 bits)

//Commands
#define BMP085_CONTROL 0xF4         //!< Control register
#define BMP085_TEMPDATA 0xF6        //!< Temperature data register
#define BMP085_PRESSUREDATA 0xF6    //!< Pressure data register
#define BMP085_READTEMPCMD 0x2E     //!< Read temperature control register value
#define BMP085_READPRESSURECMD 0x34 //!< Read pressure control register value

#define STD_ATM_PRESS 101325

static const uint8_t BMP085_ADDR = 0x77 << 1; // Use 8-bit address
I2C_HandleTypeDef* bmpPort;
uint8_t oversampling;

//Calibration data (will be read from sensor)
int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
uint16_t ac4, ac5, ac6;

//I2C handling functions
uint8_t read8(uint8_t a);
uint16_t read16(uint8_t a);
void write8(uint8_t a, uint8_t d);

//Sensor Init function
uint8_t bmpBegin(uint8_t mode, I2C_HandleTypeDef* i2cdev);

//Sensor read functions
int32_t computeB5(int32_t UT);

float readTemperature(void);
int32_t readPressure(void);
uint16_t readRawTemperature(void);
uint32_t readRawPressure(void);



#endif /* _BMP085_H */
