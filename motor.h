/* 0
   Prototypes de fonctions gérant la crémaillere
   Auteurs : Jeremy et Aurélien
   Derniere modif : 22/07/2012
*/

#ifndef MOTEUR

  #define MOTEUR
  
    #define SPEED 100
    #define PIN_CREMAILLERE 3  // chiffre correspondant au pin M4
    
    void avancerCremaillere();
    void reculerCremaillere();
    void Stop();
    void initialisation();
    bool paf();
  
#endif
