/* Source from:
http://pulsedlight3d.com
This sketch demonstrates getting distance with the LIDAR-Lite Sensor
It utilizes the 'Arduino Wire Library'

Adapted by: KARLA APARECIDA JUSTEN (https://github.com/karlajusten)

Placed the Servo Control together
*/

#include <Wire.h>
#include <Servo.h>
#define    LIDARLite_ADDRESS   0x62          // Default I2C Address of LIDAR-Lite.
#define    RegisterMeasure     0x00          // Register to write to initiate ranging.
#define    MeasureValue        0x04          // Value to initiate ranging.
#define    RegisterHighLowB    0x8f          // Register to get both High and Low bytes in 1 call.
#define    pos_servoY_UP       0             
#define    pos_servoY_DOWN      30
#define    pos_servoX_RIGHT    60             
#define    pos_servoX_LEFT   110

int distance = 0;
Servo myXservo;  // create servo object to control X servo 
Servo myYservo;  // create servo object to control Y servo
 
int posX = 0;    // variable to store X servo position 
int posY = 0;    // variable to store Y servo position 

void setup()
{
  Serial.begin(57600); // start serial communication at 9600bps
  myXservo.attach(10);  // attaches X servo on pin 10 to the servo object 
  myYservo.attach(9);   // attaches Y servo on pin 9 to the servo object;
  Wire.begin(); //join i2c bus//INITIALIZES THE LIBRARY; as it has no parameter, it considers the 12C bus as a master;
  Serial.println("Start!!!");
}

void loop() 
{ 
    Serial.print("Time1:  ");
    Serial.println(millis());
    for(posX = pos_servoX_RIGHT; posX <= pos_servoX_LEFT; posX += 1) // goes from 30 degrees to 150 degrees 
    {                                  
       for(posY = pos_servoY_UP; posY <= pos_servoY_DOWN; posY += 1){  //Y axis sweep
          myXservo.write(posX);              // tell servo to go to position in variable 'pos' 
          myYservo.write(posY);
          //delay(1);                       // waits for the servo to reach the position
          GetDist();
       } 
       for(posY = pos_servoY_DOWN; posY >= pos_servoY_UP; posY -= 1){ //Y axis sweep
          myXservo.write(posX);              // tell servo to go to position in variable 'pos' 
          myYservo.write(posY);
          //delay(1);                       // waits for the servo to reach the position 
          GetDist();
       }
    } 
    Serial.print("Time2:  ");
    Serial.println(millis());
    for(posX = pos_servoX_LEFT; posX >=pos_servoX_RIGHT; posX -=1)     // goes from 150 degrees to 30 degrees 
    { 
        for(posY = pos_servoY_UP; posY <= pos_servoY_DOWN; posY += 1){  //Y axis sweep
          myXservo.write(posX);              // tell servo to go to position in variable 'pos' 
          myYservo.write(posY);
          //delay(1);                       // waits for the servo to reach the position
          GetDist();
        } 
        for(posY = pos_servoY_DOWN; posY >= pos_servoY_UP; posY -=1){ //Y axis sweep
          myXservo.write(posX);              // tell servo to go to position in variable 'pos' 
          myYservo.write(posY);
          //delay(1);                       // waits for the servo to reach the position 
          GetDist();
        }
   }
}

void GetDist(){
   Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite//START TRANSMITTING WITH THE DEVICE
   Wire.write((int)RegisterMeasure); // sets register pointer to  (0x00)  
   Wire.write((int)MeasureValue); // sets register pointer to  (0x00)  
   Wire.endTransmission(); // stop transmitting
    
   delay(10); // Wait 20ms for transmit

   Wire.beginTransmission((int)LIDARLite_ADDRESS); // transmit to LIDAR-Lite
   Wire.write((int)RegisterHighLowB); // sets register pointer to (0x8f)
   Wire.endTransmission(); // stop transmitting
  
   delay(10); // Wait 20ms for transmit

   Wire.requestFrom((int)LIDARLite_ADDRESS, 2); // request 2 bytes from LIDAR-Lite

   while(Wire.available()==0){// wait some value
     delay(5);
   } 
   //
   if(2 <= Wire.available()) // if two bytes were received
   {
     distance = Wire.read(); // receive high byte (overwrites previous distance)
     distance = distance << 8; // shift high byte to be high 8 bits
     distance |= Wire.read(); // receive low byte as lower 8 bits
     Serial.print(posX);
     Serial.print(",");
     Serial.print(posY);
     Serial.print(",");
     Serial.println(distance);
  }
}
