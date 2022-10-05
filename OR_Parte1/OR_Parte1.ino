#include "OctubreRobotico.h"

Servo servo_base;
Servo servo_hombro;
Servo servo_garra;

Coordenadas coord;
Angulos ang;

// MOVER
// Mueve los servos según los ángulos indicados en la estructura "ang".
void mover(Angulos ang)
{
  ang.b = map(ang.b, 0, 180, 0, 145);
  servo_base.write(ang.a);
  servo_hombro.write(ang.b);
}

// GARRA
// Abre o cierra la garra.
void garra(bool c)
{
  if(c == ABRIR) 
    servo_garra.write(ANGULO_ABIERTO);
  else 
    servo_garra.write(ANGULO_CERRADO);
}

// CINEMÁTICA DIRECTA
// Calcula la posición X,Y,Z del extremo del robot según la posición
// de las articulaciones del robot.
Coordenadas cinematica_directa(Angulos ang)
{  
  // INSTRUCCIONES:
  //    - La variable "coord" tiene tres elementos: x, y ,z.
  //    - Lo que debes hacer es implementar las ecuaciones de la cinemática
  //      directa que aparecen en las diapositivas.
  //    - Para ello, sólo debes asignar valor a las variables x, y, z de la estructura "coord".
  //    - Para darles valor solo tienes que hacer:
  //        coord.x = loquesea;
  //        coord.y = loquesea;
  //        coord.z = loquesea;
  //
  
  Coordenadas coord;
  
  /* PROGRAMAR DESDE AQUÍ...*/


  
  /* ...HASTA AQUÍ*/
  
  return coord;
}

// CINEMATICA INVERSA
// Calcula los ángulos que hay que girar las articulaciones para llegar
// a una determinada posición X,Y,Z.
Angulos cinematica_inversa(Coordenadas coord)
{  
  // INSTRUCCIONES:
  //    - La variable "ang" tiene dos elementos: a, b.
  //    - Lo que debes hacer es implementar las ecuaciones de la cinemática
  //      inversa que aparecen en las diapositivas.
  //    - Para ello, sólo debes asignar valor a las variables a, b de la estructura "ang".
  //    - Para darles valor solo tienes que hacer:
  //        ang.a = loquesea;
  //        ang.b = loquesea;
  //
  
  Angulos ang;
  
  /* PROGRAMAR DESDE AQUÍ...*/


  
  /* ...HASTA AQUÍ*/
  
  return ang;
}

void setup()
{

  Serial.begin(9600);
	Serial.setTimeout(10000);

	Serial.println("Inicializando programa");	
	
	servo_base.attach(SERVO_BASE);
	Serial.println("\t\t...");
	
	servo_hombro.attach(SERVO_HOMBRO);
	Serial.println("\t\t...");
	
	servo_garra.attach(SERVO_GARRA);
	Serial.println("\t\t...");

	Serial.println("Programa Inicializado yeiii\n");

  Serial.println("Estos son los distintos modo de operacion");
  Serial.println("\tModo 1: Mover con Cinematica Directa.");
  Serial.println("\tModo 2: Mover con Cinematica Inversa.");
  Serial.println("\tModo 3: Control de la garra.");
  Serial.print("Elija el modo de operacion: ");	
}

void loop()
{
  if (Serial.available())
	{
		switch(Serial.read())
		{
			case '1':		
				Serial.println("Modo Cinematica Directa.\n");

				Serial.println("Introduzca el angulo a: ");
				ang.a = Serial.parseFloat();
				Serial.println("Introduzca el angulo b: ");
				ang.b = Serial.parseFloat();

				coord = cinematica_directa(ang);
        mover(ang);

        Serial.println("Elija otro modo de operacion: ");
        
			break;

			case '2':		
				Serial.println("Modo Cinematica Inversa.\n");
				
				Serial.println("Introduzca la coordenada x: ");
				coord.x = Serial.parseFloat();
				Serial.println("Introduzca la coordenada y: ");
				coord.y = Serial.parseFloat();
				Serial.println("Introduzca la coordenada z: ");
				coord.z = Serial.parseFloat();

				ang = cinematica_inversa(coord);	

        mover(ang);

        Serial.println("Elija otro modo de operacion: ");

			break;

			case '3':
				Serial.println("Quieres cerrar (0) o abrir (1) la garra? ");
				
				bool c = Serial.parseInt();

				garra(c);

        Serial.println("Elija otro modo de operacion: ");
        
			break;

			default:
				Serial.println("No eres muy listo tu... Elige otro numero");
			break;
		}	
	}
}
