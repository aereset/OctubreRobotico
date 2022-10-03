#ifndef __REMAKE_OR__
  #define __REMAKE_OR__
  #include <Servo.h>

  #define SERVO_BASE    9
  #define SERVO_HOMBRO  10
  #define SERVO_GARRA   11
  
  #define ANGULO_ABIERTO 90
  #define ANGULO_CERRADO 0

  #define L1 10.0 //poner decimales porfi OwO
  #define L2 20.0 //poner decimales porfi UwU

  #define ABRIR 1
  #define CERRAR 0

  #define RAD2DEG (180.0/PI)
  #define DEG2RAD (PI/180.0)
  
  // COORDENADAS: estructura que contiene la posición X,Y,Z
  // de un punto, en metros.
  struct Coordenadas
  {
    float x;
    float y;
    float z;
  };

  struct Angulos //Estan en grados no se olviden IwI
  {
    float a;
    float b;
  };
  
  
#endif
