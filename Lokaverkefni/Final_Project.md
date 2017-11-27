# Project Description
Let the robot find and knock over all columns in a predefined area.

## How we will achieve it
We will define the area by making sure the surface is white and it will be surrounded by a black surface. Once the robot leaves the white area and reads black it will turn around to stay in the area it's supposed to be in. The robot finds the columns by turning in a circle until it reads shorter distance to the next object and goes towards it until it's close enough at which point it will turn a bit, lower it's arm and turn again to knock the column over with its claw, than raise the claw again and turn to find the next column.
The robot can be stopped by pressing a button on the remote controller or if it crashes into an obstacle with an attached button.

## What we need
Robot with a claw.


Remote controller : To run the robot and have an emergency stop button.


3 motors, port 2, 3 & 7: 2 motors To get the wheels spinning, 1 to get the claw arm to go up and down.


Line Follower, analog sensors 2: To read if the robot is within the designated area (reads whether it's on black or white surface).


Sonarsensor, Digital sensor port 11: To determine if the robot sees an obstacle and how far it is from it (In this case the columns).


Touch button, digital sensor port 19: If the button is hit the robot will stop.


Potentmeter, digital port 4: Determine whether the arm is up or down.
