#include "Servo.h"

#define verticalServoPin 5
#define horizontalServoPin 6
#define delayForMovement 15
/**
 * LDR sensors configurations:
 *          * -> LDR3 == A2
 * 
 * * -> LDR4 == A3   * -> LDR2 == A1     <<- q2
 * 
 *          * -> LDR1 == A0
 *          
 **         ^
 **         ^
 **         | q1
 */

Servo verticalServo;
int q1 = 90;

Servo horizontalServo;
int q2 = 90;

void setup() {
    verticalServo.attach(verticalServoPin);
    horizontalServo.attach(horizontalServoPin);
}

void loop() {
    float ldr1 = analogRead(A0);
    float ldr2 = analogRead(A1);
    float ldr3 = analogRead(A2);
    float ldr4 = analogRead(A3);

    q1 += (ldr4-ldr2)/(1023.0)*90.0;
    q2 += (ldr3-ldr1)/(1023.0)*90.0;

    verticalServo.write(q1);
    horizontalServo.write(q2);

    delay(15);

}