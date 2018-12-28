%Ball Balancer PID Thoerectical Simulation

%Mass of ball [kg]
m = 0.00246;
%Radius of ball [m]
R = 0.03175;
%Gravity [m/s^2]
g = -9.81;
%Length of beam [m]
L = 0.30; 
%Lever arm length [m]
d = 0.1438;
%Polar Moment of inertia of the ball [m^4]
J = 3.086e-6;

%Transfer function
s = tf('s');

%Position on beam [m]
Pos = -m*g*d/L/(J/R^2+m)/s^2;

%Proportional constant
Kp = 17.5;
%Derivative constant
Kd = 12;
%Integration constant
Ki = 1.2;

%PID controller
Ce = pid(Kp,Ki,Kd);

%Closed loop negative feedback
sys_cl = feedback(Ce*Pos,1);

%Step response
step(0.15*sys_cl);