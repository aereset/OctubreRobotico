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
  Coordenadas coord;
  coord.x = L2 * cos(DEG2RAD * ang.b)*cos(DEG2RAD * ang.a);
  coord.y = L2 * cos(DEG2RAD * ang.b)*sin(DEG2RAD * ang.a);
  coord.z = L1 + L2 * sin(DEG2RAD * ang.b);
  return coord;
}

// CINEMATICA INVERSA
// Calcula los ángulos que hay que girar las articulaciones para llegar
// a una determinada posición X,Y,Z.
Angulos cinematica_inversa(Coordenadas coord)
{
  Angulos ang;
  ang.a = RAD2DEG * atan(coord.y / coord.x);
  ang.b = RAD2DEG * asin(( coord.z - L1 ) / L2 );
  return ang;
}

void setup()
{
	Serial.println("Inicializando programa");
	
	Serial.begin(9600);
	Serial.setTimeout(10000);

	servo_base.attach(SERVO_BASE);
	Serial.println("\t\t...");
	
	servo_hombro.attach(SERVO_HOMBRO);
	Serial.println("\t\t...");
	
	servo_garra.attach(SERVO_GARRA);
	Serial.println("\t\t...");

	Serial.println("Programa Inicializado yeiii");
}

void loop()
{
	if (Serial.available())
	{
		Serial.println("Estos son los distintos modo de operacion");
		Serial.println("\tModo 1: Mover con Cinematica Directa.");
		Serial.println("\tModo 2: Mover con Cinematica Inversa.");
		Serial.println("\tModo 3: Control de la garra.");
		Serial.print("Elija el modo de operacion: ");	  

		switch(Serial.read())
		{
			case '1':		
				Serial.println("Modo Cinematica Directa.\n");

				Serial.println("Introduzca el angulo a: ");
				ang.a = Serial.parseFloat();
				Serial.println("Introduzca el angulo b: ");
				ang.b = Serial.parseFloat();

				coord = cinematica_directa(ang);
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
			break;

			case '3':
				Serial.println("Quieres cerrar (0) o abrir (1) la garra? ");
				
				bool c = Serial.parseInt();

				garra(c);
			break;

			default:
				Serial.println("No eres muy listo tu... Elige otro numero");
			break;
		}

		mover(ang);
	}
}
