# PID_BallBalancer
2D beam ball balance using PID controller implemented on an arduino.

The aim of the PID_BallBalancer is to use a PID controller to adjust the location of the ball to a desired point on the beam. 

To determine the location of the ball, an ultrasonic sensor will be used. 

The calculated distance from the sensor is then fed into the PID algorithm implemented on an Arduino, which outputs a value corresponding to a change of angle on the servo motor. 

The constants of the PID controller is determined by finding the transfer function of the system and then designed using an arbitrary percent overshoot and settling time.

The constants can also be determined by manually tuning the system.

### Materials Used
  * Arduino microcontroller (Uno R3)
  * Ultrasonic sensor (HC-SR04)
  * Servo Motor (SG90)
  * Balsa Wood Frame

### Arduino Connections
<p align="center">
	<img src="https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/ArduinoDiagram.png" alt="Arduino Connections Image"/>
</p>

### Dimensions [in]
<p align="center">
	<img src="https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/dimensions.png" alt="Dimensons Image"/>
</p>

### SolidWorks Rendering
<p align="center">
	<img src="https://raw.githubusercontent.com/JFBarryLi/PID_BallBalancer/master/img/SolidWorksRendering.JPG" alt="SolidWorks Rendering Image"/>
</p>
