# PID_BallBalancer
2D beam ball balance using PID controller implemented on an arduino

The aim of the PID_BallBalancer is to adjust the location of the ball to a desired point on the beam. 

To determine the location of the system, an ultrasonic sensor will be used. 

The calculated distance is then fed into the PID algorithm implemented on an Arduino, which outputs a value corresponding to a change of angle on the servo motor. 

The gains of the PID compensator is determined by finding the transfer function of the system and then designed using an arbitrary percent overshoot and settling time.

### Materials Used
  * Arduino microcontroller (Uno R3)
  * Ultrasonic sensor (HC-SR04)
  * Servo Motor (SG90)
  * Balsa Wood Frame

### Arduino Connections
![alt text](https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/ArduinoDiagram.png "Arduino Connections")


### Dimensions
![alt text](https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/dimensions.png "Arduino Connections")

### SolidWorks Rendering
![alt text](https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/SolidWorksRendering.jpg "Arduino Connections")
