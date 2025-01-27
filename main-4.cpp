#include <iostream>
#include "multiplication.h"

int main () {

  // Entete du programme

  std::cout << "\n";
  std::cout << " _______ AllGenerate _______";
  std::cout << " \n \n ";
  std::cout << " Bienvenue sur AllGenerate, votre generateur de table de multiplication favori.";
  std::cout << " \n \n ";

  // Variables 
  int choix;
  char nbre [200]; // Pour la chaine 
  int nombre [200]; // Pour les valeurs extraites
  int taille = 0; // Navigue dans le tableau nombre 
  int resultat; // Resultat de chaque multiplication
  bool running = true; // Controle la boucle principale
  char continuer; // Verifie si l'utilisateur veut continuer
  bool choix_valide = false; // Controle le choix 

  while (running) { // Cree une boucle interminable

    while (!choix_valide) {

        // Menu du programme 

      std::cout << "Veuillez choisir, s'il vous plait, si vous souhaitez une multiplication de votre nombre par les dix ou les vingt premiers entiers positifs, ou encore de quitter le programme :\n";
      std::cout << "1. Table de N x 1 a N x 10\n";
      std::cout << "2. Table de N x 1 a N x 20\n";
      std::cout << "3. Quitter\n"; // Pour quitter le programme
      std::cout << "Votre choix (1 a 3): ";
      std::cin >> choix;
            
      switch (choix) {

        case 1:
        case 2:
        case 3:

        choix_valide = true;
        break;
        default:

        std::cout << "Erreur ! Veuillez entrer un chiffre compris de 1 a 3 :\n";
        break;
      }
    }
  	
    switch ( choix ) { // Cree une boucle de choix

      case 1:

        // Cas de la multiplication N x 1 a N x 10
    
  	    std::cout << " Veuillez entrer votre(vos) nombre(s) a multiplier en les separant par une virgule (ex: 2,3,4) : ";
        std::cin >> nbre;
        extraire_valeurs ( nbre, nombre, taille );
        for (int i = 0; i < taille; i++) {
          std::cout << "La table de multiplication de " << nombre[i] << " est :\n";
          affiche_table10(nombre[i]);
          std::cout << std::endl;
        }

      break;

      case 2:

      // Cas de la multiplication N x 1 a N x 20
          
  	    std::cout << " Veuillez entrer votre(vos) nombre(s) a multiplier en les separant par une virgule (ex: 2,3,4) : ";
        std::cin >> nbre;
        extraire_valeurs ( nbre, nombre, taille );
        for (int i = 0; i < taille; i++) {
          std::cout << "La table de multiplication de " << nombre[i] << " est :\n";
          affiche_table20(nombre[i]);
          std::cout << std::endl;
        }

      break;

      case 3:

        std::cout << " Merci d'avoir utilise ce programme. A la prochaine ! ";
        running = false;
        
      break;
    
      default:

        std::cout << " Erreur ! Veuillez entrer un chiffre compris de 1 a 3 : ";

      break;
    }

    // Demande à l'utilisateur s'il souhaite continuer

    if (running) {
      
      std::cout << "Voulez-vous en faire une autre (O/N) ? ";
      std::cin >> continuer;
      if (continuer != 'O' && continuer != 'o') {
        std::cout << " Merci d'avoir utilise ce programme. A la prochaine ! ";
        running = false;
      }
    }
  }
  return 0;
}


