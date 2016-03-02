#include <math.h>

int calculaVelocidade(int holesForSec, float defDelay){
    float pi = 3.14;  // Valor do PI
    float radius = 5.75;  // Raio em centímetros
    int holes = 608;  // valor de 1 volta

    int speed = (2 * pi * (radius / holes) * (holesForSec / (defDelay / 1000)));

    return speed;
}

int distanciaPercorrida(int rotation){
  float pi = 3.14;  // Valor do PI
    float radius = 5.75;  // Raio em centímetros
    int holes = 608;  // valor de 1 volta

    int distance = (2 * pi * (radius / holes) * rotation);

    return distance;
}

int coordenadaY(float lRotation, float rRotation){
  float x,y;
  int z = 22;
  if (lRotation > rRotation){
    x = rRotation;
    y = lRotation;
  } else if (lRotation < rRotation){
    x = lRotation;
    y = rRotation;
  }

  float r = (x * z) / (y - x);
  
//  float angulo = asin(x/r);
  float angulo = x / r;

  float raio = r + (z / 2);
  float yCoord = raio * sin(angulo);

  return yCoord;
}

int coordenadaX(float lRotation, float rRotation){
  float x,y;
  int z = 22;
  if (lRotation > rRotation){
    x = rRotation;
    y = lRotation;
  } else if (lRotation < rRotation){
    x = lRotation;
    y = rRotation;
  }

  float r = (x * z) / (y - x);
  
//  float angulo = asin(x/r);
  float angulo = x / r;

  float raio = r + (z / 2);
  float yCoord = raio * cos(angulo) - raio;

  return yCoord;
}