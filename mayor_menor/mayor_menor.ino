// programa para comparar 2 numeros y decidir cual es mayor de ambos.

int X;
void setup() {
  Serial.begin(9600);

}


//---------------------------------BUCLE INFINITO--------------------------------------
void loop() {
  
// Serial.println("por favor ingrese el primer numero:");
while(Serial.available()){    // Recepcion del numero A
  String A = GetLineA();
  int X = A.toInt();          //Como esperamos un numero, convertimos el texto a numero A
  Serial.println(X);
}
 
// Serial.println("por favor ingrese el segundo numero:");
while(Serial.available()){    // Recepcion del numero B
  String B = GetLineB();
  int Y = B.toInt();          //Como esperamos un numero, convertimos el texto a numero B
  Serial.println(Y);
  
  
  int z = X + Y;
  Serial.println(z);
}

}



  
}


//-----------------------------FUNCION PARA OBTENER EL NUMERO A-------------------------------
String GetLineA()
{  
  String A = "" ; 
  if (Serial.available())
      { 
        char c = Serial.read(); ;
        while ( c != '\n')
            {   A = A + c ;
                delay(25) ;
                c = Serial.read();
            }
         return(A) ;
      }
}


//-----------------------------FUNCION PARA OBTENER EL NUMERO B-------------------------------
String GetLineB()
{  String B = "" ; 
  if (Serial.available())
      { 
        char c = Serial.read(); ;
        while ( c != '\n')
            {   B = B + c ;
                delay(25) ;
                c = Serial.read();
            }
         return(B) ;
      }
}
