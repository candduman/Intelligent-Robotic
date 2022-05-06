1.1 Purpose of Project
Purpose of this project is to locate a black object on a white background using C# image processing and
aim the laser at the black object.
1.2 Required Parts
1. 1 x Arduino Nano
2. 1 x USB Data Cable
3. 1 x Breadboard
4. 2 x Servo Motor
5. 1 x Arduino Pan Tilt
6. 1 x KY-008 Laser Module
7. 18 x Jumper Cable (Male to Female)
8. 1 x Universal Bant
1.3 Introduction
Before mounting the servo motors to the pan tilt, we print 90 degrees to our motors with arduino.
Then we mount the motors on the pan tilt. After that, I glued the laser onto the pan tilt with
silicone(Figure 1).
![image](https://user-images.githubusercontent.com/53488195/167212167-45ded231-b078-4243-89c3-8e4188b0ce25.png)

Figure 1
We created an Arduino file that contains writes angles comes from C# to servos motors and opens
laser.After all the connections are made, we stick the Robot to the keyboard in line with the camera(Figure 2 ).
There is a distance of about 20 cm between the camera and the robot. We will use this distance later in the
formula.We make sure that the laptop screen is 90 degrees. Then we position the laptop on a desk. We
measure the distance between the screen and the wall. Then we run the C # application and measure the width
of the area covered by the camera. These values are very important for the calibration of the system. I
measured my values as distance 100 cm and width 145 cm.
![image](https://user-images.githubusercontent.com/53488195/167212184-0fc86439-283d-4ddf-a7df-465f59187780.png)

Figure 2
I calculated width / BWImage.Width(myscale) in C# code. This calculation calculates cm per pixel. We
convert the image on the camera to black and convert the black colors to white using C#. The purpose of this
process is to detect the black object we will use more easily and to see it more clearly on the screen. we find
the center point of the black object via C#. With the values we have, we find the angles that the robot will turn
by solving the Inverse Kinematic formula(Th Values).
Inverse Kinematic Formula ➔ Th1 = Atan2(Py/Px) Th2 = Atan(Sin(Th1)*(Pz-d1)/Py)
After calculating Th1 and Th2 we have to write them to Servo Motors. But there is a trick that we
shouldn’t skip We write send Th1 and Th2 adding both +90 degrees because we set 90 degrees for both servo
motors as 0 point. 
