/*
 * This project is to test the serial communication
 * between processing and arduino, enjoy this little
 * game.
 * 
 * File : SerialGame
 * Author : Frank Fang
 * Arduino part : get the serial input from joystick
 * and send it to processing part.
 */
 
int pinX = 0;
int pinY = 1;
int preX, preY, curX, curY;
int button = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int curX = map(analogRead(pinX), 0, 1023, 0, 255);
  
  Serial.write('s');  // write your own communication protocal
  //Serial.print("x = "); Serial.print(curX);
  Serial.write(curX);
  
  Serial.write(digitalRead(button));
  delay(20);
}

