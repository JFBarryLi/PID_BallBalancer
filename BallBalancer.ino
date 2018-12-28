#include <Servo.h>

// defines pins numbers
const int trigPin = 9; //Ultrasonic Sensor Trig Pin
const int echoPin = 10; //Ultrasonic Sensor Echo Pin
const int servoPin = 13; //Servo Pin

// defines variables
long duration; //Time it Took for Sound to Comeback
int distance; //Location of Ball from Sensor
int pos = 0; //Servo Position
double StartAngle = 102; //Angle of servo when beam is parallel to the ground
double pError,iError,dError; //Error values associated with PID
double Output; //Sum of error values multiplied by their corresponding gains
double prevError; //Error from previous iteration
unsigned long prevTime,now; //Previous time and current time
double dt; // Change in time

int Setpoint = 0;  //Desired point on the beam

//Gains
float Kp = 0.16; //0.17
float Ki = 0.00005; // 0.0001
float Kd = 7; // 1.8

Servo servo;  // create servo object to control the servo

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  servo.attach(servoPin);  // attaches the servo on pin 13 to the servo object
  servo.write(StartAngle); //Initiate the motor to the horizonal angle
  Serial.begin(9600); //Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2 - 15;
  // Prints the distance on the Serial Monitor
  if (distance > 30 or distance < -30) {
    distance = -12; // Anything above or below this value is just disturbances
  }
  if (distance == 0 or distance == 0) {
    distance = 0; // Adjust for sensor noise
  }


  //PID Algorithm
  now = millis();
  dt = (now - prevTime);
  pError = Setpoint - distance;
  dError = (pError - prevError) / dt;
  iError = iError + (pError * dt);
  if (iError > 10) {
    iError = 10;
  }

  Output = Kp * pError + Ki * iError + Kd * dError;

  //Upper and Lower Bound of PID
  if (Output >20) {
    Output = 20;
  }
  if (Output <-20) {
    Output = -20;
  }

  servo.write(StartAngle + Output);

  Serial.print("PID: ");
  Serial.println(Output);
  prevError = pError;
  prevTime = now;

}
