#include <AccelStepper.h>

// Define the stepper motor and the pins that it is connected to
AccelStepper stepper1(1, 0, 2); // (Type of driver: 2 pins, STEP, DIR)
const int en = 14;

void setup() {
  Serial.begin(115200);

  stepper1.setMaxSpeed(2000);      // Set maximum speed value for the stepper
  stepper1.setAcceleration(2000);  // Set acceleration value for the stepper
  stepper1.setCurrentPosition(0);  // Set the current position to 0 steps

  pinMode(en, OUTPUT);
  digitalWrite(en, LOW);  // Assuming this is for enabling the stepper driver
}

void loop() {
  if (Serial.available() > 0) {
    char br = Serial.read();

    if (br == '1') {
      // Move to position 150 steps
      stepper1.moveTo(50);
     

      // Move the motor towards the target position incrementally
      while (stepper1.distanceToGo() != 0) {
        stepper1.run();
        delay(1); // Small delay to allow ESP8266 to perform other tasks
      }
      stepper1.setCurrentPosition(0);

    }

    if (br == '0') {
      // Move to position 150 steps
      stepper1.moveTo(-50);
      

      // Move the motor towards the target position incrementally
      while (stepper1.distanceToGo() != 0) {
        stepper1.run();
        delay(1); // Small delay to allow ESP8266 to perform other tasks
      }
      stepper1.setCurrentPosition(0);

    }


    
  }
}
