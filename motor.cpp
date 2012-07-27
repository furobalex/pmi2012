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
    pinMode(PIN_BUTEE_DEPLIE, INPUT);
    digitalWrite(PIN_BUTEE_DEPLIE, HIGH);
    pinMode(PIN_BUTEE_PLIE, INPUT);
    digitalWrite(PIN_BUTEE_PLIE, HIGH);// pull up sur pin 2
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
    if(digitalRead(PIN_BUTEE_DEPLIE)==LOW)
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
    if(digitalRead(PIN_BUTEE_PLIE)== LOW)
    { 
      etat=0;
      Stop();
      return true;
    }
    break;
  }
  return false;
}
