#include "Cuerpo.hpp"

int** initParams() {
  int **pins = pins = new int*[PATAS];
  for (int i = 0; i < EJES; i++) {
    pins[i] = new int[EJES];
  }

  pins[0][0] = 8; //Pata 1 Eje 1 => Pin 8
  pins[0][1] = 9; //Pata 1 Eje 2 => Pin 9
  pins[0][2] = 10; //Pata 1 Eje 3 => Pin 10
  
  return pins;
}

Cuerpo *cuerpo;
int numMovements;
boolean secuenceRequest;
struct BasicMovementType {
  char tipoMov;
  int pata;
  int eje;
  int angulo;
} movements[PATAS*EJES*50];

void setup() {  
  Serial.begin(9600);
  cuerpo = new Cuerpo(PATAS,EJES,initParams());
  cuerpo->init();
  Serial.println("---------------------------");
  // Mensaje inicial en el monitor serial
  Serial.println("Escribir comando (Pata-Eje-Angulo): ");
}

char checkOption(String command) {
  char option = command.charAt(0);
  Serial.print("Opcion elegida ");
  Serial.println(option);
  return option;
}

void readMove(String command) {
  Serial.println("readMove");
  BasicMovementType movement;
  String tail = command.substring(1);
  Serial.println(tail);
  char * pch = strtok (tail.c_str(),"-");
  int i = 0;
  while (pch != NULL) {
    switch(i) {
      case 0: movement.pata = atoi(pch);
        break;
      case 1: movement.eje = atoi(pch);
        break;
      case 2: movement.angulo = atoi(pch);
        break;               
    }
    pch = strtok (NULL, "-");
    i++;
  }

  numMovements = 1;

  movements[0] = movement;
}

void readSecuence() {
  Serial.println("readSecuence");  
  numMovements = 0;
  for(int i=1;i<=PATAS;i++) {
    for(int j=1;j<=EJES;j++) {
      for(int z=0;z<=180;z+=45) {
        movements[numMovements].pata = i;          
        movements[numMovements].eje = j;
        movements[numMovements].angulo = z;
        
        /*Serial.print("Inicializando mov ");
        Serial.print(numMovements);       
        Serial.print("->");
        Serial.print(i);        
        Serial.print("+");
        Serial.print(j);            
        Serial.print("+");
        Serial.println(z);*/
        numMovements++;
      }
      for(int z=180;z>=0;z-=45) {
        movements[numMovements].pata = i;          
        movements[numMovements].eje = j;
        movements[numMovements].angulo = z;
        
        /*Serial.print("Inicializando mov ");
        Serial.print(numMovements);       
        Serial.print("->");
        Serial.print(i);        
        Serial.print("+");
        Serial.print(j);            
        Serial.print("+");
        Serial.println(z);*/
        numMovements++;
      }

      /*movements[numMovements].pata = i;          
      movements[numMovements].eje = j;
      numMovements++;*/
    }
    
  }
}

void commandRead() {
  char character;
  String command;
  
  while (Serial.available() > 0) {
    character = Serial.read();
    delay(10);
    command.concat(character);
  }

  Serial.print("Comando leido: ");
  Serial.println(command);

  char option = checkOption(command);
  switch(option) {
    case 'm': 
          Serial.println("Movimiento");
          readMove(command);
      break;
    case 's': 
          Serial.println("Secuencia");
          readSecuence();
          secuenceRequest = true;
      break;
    default: Serial.println("Opcion desconocida");
  }

  /*Serial.print(movements[0].pata);        
  Serial.print("+");
  Serial.print(movements[0].eje);            
  Serial.print("+");
  Serial.println(movements[0].angulo);*/
}

void cleanSerial() {
   // Rutina de limpieza del buffer del puerto
   while (Serial.available() > 0) {
    Serial.read();
   }
}

void loop() {
    if (Serial.available()) {
     delay(10);
     
     commandRead();
    
    if(numMovements > 0) {
       for(int i=0;i<numMovements;i++) {
         Serial.print("Pata ");
         Serial.print(movements[i].pata);
         Serial.print(" Eje ");
         Serial.print(movements[i].eje);
         Serial.print(" Grados ");
         Serial.println(movements[i].angulo);
  
         cuerpo->move(movements[i].pata,movements[i].eje, movements[i].angulo); 
  
         // Mensaje de confirmacion del angulo ingresado por Monitor Serial
         /*Serial.print("Hecho. Posicion angular actual: "); 
         Serial.print(movements[i].angulo);
         Serial.println(" grados");
         Serial.println("---------------------------");*/     
       }

      if(secuenceRequest) {
        Serial.println("Reset secuencia");
        cuerpo->init();
        secuenceRequest = false;
      }
      Serial.println("Reset movimientos");
      numMovements = 0;      
     }
     cleanSerial();
    }
}

