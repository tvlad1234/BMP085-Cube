# BMP085-Cube
*BMP085/BMP180 Library for STM32Cube*\
Based on [Adafruit-BMP085-Library](https://github.com/adafruit/Adafruit-BMP085-Library)

### Initializing the sensor
Before reading the sensor, it must be initialized with _bmpBegin_.\
_bmpBegin_ takes two parameters: sensor mode and a pointer to the I2C Handler and returns 1 if connection was successful.\
_Example:_ `bmpBegin(BMP085_STANDARD, &hi2c1);`\
Other usable modes are `BMP085_ULTRALOWPOWER`,  `BMP085_HIGHRES`,  `BMP085_ULTRAHIGHRES.` 

### Reading the sensor
`readBMPTemperature()` returns the temperature in °C as _float_.
`readBMPPressure()` returns the atmospheric pressure in Pascals (Pa) as _uint32_t_.


