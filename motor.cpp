/* 
   Fonctions gérant le mouvement de la crémaillere 
   Auteurs : Jeremy et Aurélien
   Derniere modif : 22/07/2012
*/

#include "motor.h"
#include "AFMotor.h"
#include <Arduino.h>

AF_DCMotor moteur (PIN_CREMAILLERE);

// Avance la crémaillere
void avancerCremaillere()
{
    moteur.run(FORWARD);
}

// rentre la crémaillere
void reculerCremaillere()
{
    moteur.run(BACKWARD);
}

//arrête le moteur
void Stop()
{
  moteur.run(RELEASE);
}
// a ajouter a l'initialisation
void initialisation()
{
    moteur.setSpeed(SPEED);
    pinMode(52, INPUT);
    digitalWrite(52, HIGH);
    pinMode(53, INPUT);
    digitalWrite(53, HIGH);// pull up sur pin 2
    Serial.begin(9600);
    Serial.println("bonjour");
}


bool paf()
{
  static  int etat = 0;
  switch(etat)
  {
    case 0:
    avancerCremaillere();
    etat=1;
    break;
    
    case 1:
    if(digitalRead(52)==LOW)
    {
      etat=2;
      Stop();
    }
    break;
    
    case 2:
    reculerCremaillere();
    etat=3;
    break;
    
    case 3:
    if(digitalRead(53)== LOW)
    { 
      etat=0;
      Stop();
      return true;
    }
    break;
  }
  return false;
}
