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
  Serial.begin(9600);

	servo_base.attach(SERVO_BASE);
	servo_hombro.attach(SERVO_HOMBRO);
	servo_garra.attach(SERVO_GARRA);
	
}

void loop()
{

//En esta segunda parte, vamos a programar el brazo para que haga un simple PICK&PLACE

//PICK&PLACE, como su nombre indica, coge un objeto en un punto, y lo deja en otro. Este ciclo
//se repite indefinidamente

//Elegiremos para los puntos de pick y de place los puntos (90, 0) y (0, 0), respectivamente
//Podeis hacer todas las florituras que querais con el brazo, sed creativos!

//No os olvideis de los delays entre movimientos, que los movimientos no son instantaneos!!

/* PROGRAMAR DESDE AQUÍ...*/


  
/* ...HASTA AQUÍ*/

delay(3000);

}
