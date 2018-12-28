%Ball Balancer PID Thoerectical Simulation

%Mass of ball
m = 0.00246;
%Radius of ball
R = 0.03175;
%Gravity
g = -9.81;
%Length of beam
L = 0.30; 
%Lever arm length
d = 0.1438;
%Moment of inertia of the ball
J = 3.086e-6;

%Transfer function
s = tf('s');

%Position on beam
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