const int trigPin = 2; //HC-SR04 Trigger pin is connected to Arduino 2 pin
const int echoPin = 3; //HC-SR04 Echo pin is connected to Arduino 3 pin
char userInput; //Variable used for catching user input through serial communication

long duration; //Duration needed for sound wave to return to HC-SR04
int distance; //Distance calculated

//Setup function used for configuring before the program enters main loop() function
void setup() {
  pinMode(trigPin, OUTPUT); //Initialising trigPin as output
  pinMode(echoPin, INPUT); //Initialising echoPin as input
  Serial.begin(9600); //Starting serial communication with baud rate of 9600
}

//Loop function used after setup has been configured 
void loop() {

  if(Serial.available() > 0) { //Function that returns number of bytes available to be captured from serial ports. If there is a byte waiting, we enter the IF statement
    userInput = Serial.read(); //Reading input from serial port
    if(userInput == 'g') { //If the input matches our predetermened input 'g', it's time to catch the distance
      /*Catching distance using HC-SR04 and sending it through serial port*/
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    
      duration = pulseIn(echoPin, HIGH);
      distance = duration*0.034/2;
    
      Serial.println(distance);
      /********************************************************************/
    }
  }
}
