# Proteus Car Controller

![simulation](assets/simulation.gif)

This is a simulation of a car drived by bluetooth, through the emisor bluetooth (which could be a smartphone) the user can `accelerate`, `reverse`, `turn left`, `turn right`, `slow down` the motor, `speed up` the motor and `stop`.

## Software used

- [Arduino](arduino.cc).
- Proteus 8 Profesional (8.8 version).
- [Virtual Serial Port Driver](https://www.eltima.com/vspd-post-download.html) (from Etilma Software).

## Adding L289 Library to proteus
- You can download the library at this link: https://www.theengineeringprojects.com/2017/09/l298-motor-driver-library-proteus.html 
- Once you downloaded the rar file, open it and extract the files.
- You will get two files in it, named as:
    L298MotorDriverTEP.LIB
    L298MotorDriverTEP.IDX
- Place these two files in the Library folder of your Proteus Software.
- Now restart your Proteus software and search for L298 Motor Driver in the search box.
- Here is what it should look like:
![L298-Motor-Driver](assets/L298-Motor-Driver.png)

## How to execute it?

Just follow the next steps:

1. Open Virtual Serial Port Driver.

![step1](assets/step1.png)

2. Add pair.

![step2](assets/step2.jpg)

3. Open the Arduino code in Arduino.

![step3](assets/step3.png)

4. Go to preferences.

![step4](assets/step4.png)

5. Check the `Show verbose output during compilation` option and press ok.

![step5](assets/step5.jpg)

6. Verify the code (make sure your board is `Arduino Mega or Mega 2560`).

![step6](assets/step6.png)

7. Select and copy the `.hex` path and the end of the console line.

![step7](assets/step7.png)

8. Open the Proteus project.

![step8](assets/step8.png)

9. Double click in the Arduino and paste the previously path.

![step9](assets/step9.jpg)

10. Simulate.

![step10](assets/step10.png)


## Methods inside the arduino file:
- Inside the loop method we have a switch case to see which command the user is giving to the program, so the following methods start to work:

1. accelerate() : as him name is saying this method accelerates the motor of the car.
2. reverse() : the method is responsible for reversing the car.
3. stop() : the method stops the car.
4. turnRight() : the method makes the car turn right.
5. turnLeft() : the method makes the car turn left.

## Simulation Options

- A: Accelerate the motor.
- B: Reverse the motor.
- S: Stop the motor.
- O: Slow down the motor.
- P: Speed Up the motor.
- L: Turn left 45 degrees the servo motor.
- R: Turn right 45 degrees the servo motor.
