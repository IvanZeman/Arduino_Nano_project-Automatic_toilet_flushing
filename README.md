# automatic-toilet-flushing-Arduino-

If the signal from the PIR sensor is in the HIGH state for longer than 10 seconds, the algorithm evaluates the presence of a person at the urinal as a TRUE. If this signal is shorter than 10 seconds, nothing happens. The algorithm starts from the beginning.

If the presence of a person at the urinal is evaluated as a TRUE and the signal from PIR sensor immediately changes to LOW (the person has left the urinal), at that moment the countdown to flushing starts - flashing of the LED diode starts. After countdown the flushing system is activated. This is followed by a 5-second pause for the flushing of the urinal, after which the flushing system will be turn off.

After the urinal is flushed, the algorithm starts from the beginning.

Note:
The PIR sensor deactivates the output with a delay of 3 seconds.

Programming the Arduino Nano via Arduino IDE:
![IMG_20230820_122605](https://github.com/IvanZeman/automatic-toilet-flushing-Arduino-/assets/142148101/5cf1a8e0-c802-4768-8464-d6a251885dee)

Automatic flushing system hardware:
![IMG_20230820_112613](https://github.com/IvanZeman/automatic-toilet-flushing-Arduino-/assets/142148101/90d6ac8f-f191-4883-a1ee-ed9f4b9a9a7c)

Plastic box for automatic flushing system:
![IMG_20230820_112443](https://github.com/IvanZeman/automatic-toilet-flushing-Arduino-/assets/142148101/fa4e842a-81be-4c02-af14-20cfa798113f)
