/*
AERIS_Sytem_Control_Board
Galileo Team
H.Giannetta
https://2019.spaceappschallenge.org/challenges/our-moon/eeny-meeny-miney-sample/teams/galileo/project

----------------------- 
NASA SpaceApps 2019 international hackathon
https://www.spaceappschallenge.org/
-----------------------
*/


//  Include following libraries to access IR sensor

#include <IRremote.h>
#include <IRremoteInt.h>
#include <DCMotor.h>

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int RECV_PIN = 12;          //  The digital pin that the signal pin of the sensor is connected to
int AERIS_XRF_PIN = 10; // XRF Aeris output control bit
int AERIS_RAMAN_PIN = 9; // Raman Aeris output control bit
int AERIS_POLIMER_PIN = 8; // Polimer deposition Aeris output control bit
int AERIS_PRINT_PIN = 7; // Print with conductive  Aeris output control bit
int AERIS_LASER_PIN = 6; // XRF Aeris output control bit


IRrecv receiver(RECV_PIN);  //  Create a new receiver object that would decode signals to key codes
decode_results results;     //  A varuable that would be used by receiver to put the key code into

DCMotor motor0(M0_EN, M0_D0, M0_D1); // configuro motor
DCMotor motor1(M1_EN, M1_D0, M1_D1); // configuro motor

//Remote control parameter codification
//const IR_Code_FW = 458;
int MotorVelRef = 30.0;
int MotorTimeRef = 5000;


void setup() {
  Serial.begin(9600);       //  Setup serial port to send key codes to computer
  receiver.enableIRIn();    //  Enable receiver so that it would start processing infrared signals
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}

void loop() {
  if(receiver.decode(&results)) {             //  Decode the button code and put it in "results" variable
    Serial.println(results.value, HEX);       //  Print the code as a hexadecimal value
    //Serial.println(results.value, DEC);       //  Print the code as a hexadecimal value
    
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second

    switch (results.value) {
    case 1112: // Forward
    case 66648:// Forward
      //do something when var equals 1
      motor0.setSpeed(MotorVelRef);
      motor1.setSpeed(-MotorVelRef);
      delay(200);
      break;

    case 1113: // Reverse
    case 66649:// Reverse 
      //do something when var equals 1
      motor0.setSpeed(-MotorVelRef);
      motor1.setSpeed(MotorVelRef);
      delay(200);
      break;
      
    case 1068: // Play continously      
    case 66604:// Play continously
      //do something when var equals 1
      motor0.setSpeed(MotorVelRef);
      motor1.setSpeed(-MotorVelRef);
      delay(MotorTimeRef);
      break;

    case 1112: // Forward
    case 66648:// Forward
      //do something when var equals 1
      motor0.setSpeed(MotorVelRef);
      motor1.setSpeed(-MotorVelRef);
      delay(200);
      break;
      
    case 1115: // AERIS Instrument Positioning (Available only in the Arduino board that control AERIS )
    case 66651:// AERIS Instrument Positioning (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      motor0.setSpeed(MotorVelRef);
      motor1.setSpeed(-MotorVelRef);
      delay(MotorTimeRef);
      break;
      
    case 1116: // AERIS XRF (Available only in the Arduino board that control AERIS )
    case 66652:// AERIS XRF (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      digitalWrite(AERIS_XRF_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(AERIS_XRF_PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      break;

    case 1117: // AERIS RAMAN (Available only in the Arduino board that control AERIS )
    case 66653:// AERIS RAMAN (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      digitalWrite(AERIS_RAMAN_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(AERIS_RAMAN_PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      break;
      
    case 1118: // AERIS POLIMER DEPOSITION (Available only in the Arduino board that control AERIS )
    case 66654:// AERIS POLIMER DEPOSITION (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      digitalWrite(AERIS_POLIMER_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(AERIS_POLIMER_PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      break;

    case 1119: // AERIS PRINT CONDUCTIVE INK FILM DEPOSITION FOR RFID TAG (Available only in the Arduino board that control AERIS )
    case 66655:// AERIS PRINT CONDUCTIVE INK FILM DEPOSITION FOR RFID TAG (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      digitalWrite(AERIS_PRINT_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(AERIS_PRINT_PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      break;

    case 1119: // AERIS LASER ABLATION CONFORMATION FOR THE RFID TAG (Available only in the Arduino board that control AERIS )
    case 66655:// AERIS LASER ABLATION CONFORMATION FOR THE RFID TAG (Available only in the Arduino board that control AERIS )
      //do something when var equals 1
      digitalWrite(AERIS_LASER_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);               // wait for a second
      digitalWrite(AERIS_LASER_PIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      break;
          
    case 1271: // Increment Vel
    case 66807:// Increment Vel
      //do 
      MotorVelRef = MotorVelRef+10; 
      break;
     
    case 1053: // Increment Time
    case 66589:// Increment Time
      //do  
      MotorTimeRef = MotorTimeRef+1000;
      break;  

    default:
      // if nothing else matches, do the default
      // default is optional

      break;
    } 


    motor0.setSpeed(0.0);
    motor1.setSpeed(0.0);    
    //motor0.brake();
    //motor1.brake(); 

    receiver.resume();       //  Continue listening for new signals
  }
}




