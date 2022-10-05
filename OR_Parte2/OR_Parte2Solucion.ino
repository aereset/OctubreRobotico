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

//PUNTO INICIAL (0, 90)
  ang.a = 0;
  ang.b = 90;
  bool apertura_garra = true;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 1 (90, 90)

  ang.a = 90;
  ang.b = 90;
  apertura_garra = true;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 2 (90, 0)

  ang.a = 90;
  ang.b = 0;
  apertura_garra = true;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//CERRAMOS GARRA

  apertura_garra = false;

  garra(apertura_garra);

  delay(4000);

//PUNTO 3 (90, 45)

  ang.a = 90;
  ang.b = 45;
  apertura_garra = false;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 4 (180,45)

  ang.a = 180;
  ang.b = 45;
  apertura_garra = false;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 5 (180, 135)

  ang.a = 180;
  ang.b = 135;
  apertura_garra = false;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 6 (0, 135)

  ang.a = 0;
  ang.b = 135;
  apertura_garra = false;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(2000);

//PUNTO 7 (0, 0)

  ang.a = 0;
  ang.b = 0;
  apertura_garra = false;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  delay(2000);

//ABRIMOS GARRA

  apertura_garra = true;

  garra(apertura_garra);

  delay(4000);

//PUNTO FINAL (0, 90)

  ang.a = 0;
  ang.b = 90;
  apertura_garra = true;

  coord = cinematica_directa(ang);

  garra(apertura_garra);
  mover(ang);

  Serial.println("Coordenadas actuales: " + String(coord.x) + ", " + String(coord.y) + ", " + String(coord.z));
  
  delay(5000);






 //  Serial.print("Coordenadas actuales: " , coord.x , ", " , coord.y , ", " , coord.z);
  

}
