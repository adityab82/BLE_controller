# BLE_controller

## Edit in library - Lemming Dev

To ensure that the right joystick works as expected, I needed to make a change in the library used. The edit was made to the setRightThumb function in the BleGamepad.cpp file. Change rZ -> rX so that axes 2 and 3 are set by this function instead of the original axes 2 and 5.

Now the right joystick works as expected

## Solidworks Model

![alt text](image-1.png)


## Circuit
![alt text](Circuit_I.jpg)
![alt text](Circuit_II.jpg)

