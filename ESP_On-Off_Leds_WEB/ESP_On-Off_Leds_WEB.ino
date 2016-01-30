#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX
String W =" ";
char w ;

void setup()
   {  Serial.begin(9600);
      BT1.begin(9600);
      pinMode(13, OUTPUT);
      pinMode(12, OUTPUT);
   }

void loop()
   {  if (BT1.available())                // Lo que entra por WIFI à Serial
         { w = BT1.read() ;
           Serial.print(w);
           W = W + w ;                    // Vamos montando un String con lo que entra
         }
      if (Serial.available())             // Lo que entra por Serial à WIFI
         {  char s = Serial.read();
            BT1.print(s);
         }
      if ( w == '\n')                     // Sin han pulsado intro
         { if ( W.indexOf("P13") > 0 )    // Comprobamos si P13 esta incluido en el string
               { digitalWrite(13, !digitalRead(13)) ;
                 Serial.println("Invirtiendo pin 13");
               }
               
           if ( W.indexOf("P12") > 0 )    // Comprobamos si P12 esta incluido en el string
               { digitalWrite(12, !digitalRead(12)) ;
                 Serial.println("Invirtiendo pin 12");
               }
                     
            W = "" ;  w = ' ' ;                    // Limpiamos las variables
         }
  }
