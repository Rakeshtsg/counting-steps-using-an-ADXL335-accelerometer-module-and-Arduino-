/*This code uses the X and Z axis readings from the accelerometer to determine the magnitude of the change in acceleration. 
 * It then compares this change to a threshold value to determine if a step has been taken. 
 * all Rights are reserved V electronics Pvt. Ltd (RAKESH T S) 
 *This code is more sophisticated as it considers changes in acceleration in multiple axis and adjusts the threshold dynamically.*/
#define X 0
#define Y 1
#define Z 2

const int stepPin = 2;
int steps = 0;
int sensorValue[3];
int previousValue = 0;
int threshold = 20;

void setup() {
  pinMode(stepPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue[X] = analogRead(X);
  sensorValue[Y] = analogRead(Y);
  sensorValue[Z] = analogRead(Z);

  int currentValue = abs(sensorValue[X] - sensorValue[Z]);

  if (currentValue - previousValue > threshold) {
    steps++;
    Serial.println("Steps: " + String(steps));
  }
  previousValue = currentValue;
  delay(100);
}
