# Diseño del sistema - Mini Telemetría ESP32

I2C GPIO Pin
-------------
SDA -> GPIO8
SCL -> GPIO9

MPU6050 Address
---------------
When Logic is:
0 -> LSB = 0 -> 0x68[HEX]
1 -> LSB = 1 -> 0x69[HEX]

MPU6050 Who Am i Reg
0x75[HEX]
