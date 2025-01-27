#include <iostream>
#include <cctype> // Pour isdigit
#include "multiplication.h"

// Fonction qui effectue la multiplication de N x 1 a N x 10

void affiche_table10 ( int nbre ) {

    int resultat;
    for ( int i = 1; i <= 10; i++ ) {
        resultat = nbre*i;
        std::cout << nbre << " x "  << i << " = " << resultat << "\n";
    }
}

// Fonction qui effectue la multiplication de N x 1 a N x 20

void affiche_table20 ( int nbre ) {

    int resultat;
    for ( int i = 1; i <= 20; i++ ) {
        resultat = nbre*i;
        std::cout << nbre << " x "  << i << " = " << resultat << "\n";
    }
}

// Fonction qui verifie si les nombres entres par utilisateur sont des entiers

bool verifier_entier ( const char tab [] ) {
    if ( tab [0] == '\0') { // Pour verifier si la chaine est vide 
        return false;  // Si oui la fonction retourne faux
    }
    for ( int i = 0; tab [i] != '\0'; i++ ) {
        if ( !isdigit (tab [i]) ) { // Verifie si un caractere est un entier 
            return false;
        }
    }
    return true;
}

// Fonction permettant d extraire les nombres a multiplier dans la chaine de caracteres entree par l utilisateur

void extraire_valeurs(const char nbre[], int nombre[200], int& taille) {
    char element[100];
    int index = 0;
    taille = 0;
    bool valide = true;

    for (int i = 0; nbre[i] != '\0'; i++) {
        if (nbre[i] == ',' || nbre[i + 1] == '\0') {
            if (nbre[i + 1] == '\0' && nbre[i] != ',') {
                element[index++] = nbre[i];
            }
            element[index] = '\0';

            // Supprime les espaces inutiles dans la chaine de caractères
            int debut = 0;
            int fin = index - 1;
            while (element[debut] == ' ') {
                debut++;
            }
            while (element[fin] == ' ') {
                fin--;
            }
            element[fin + 1] = '\0';

            // Valide qu'il s'agit bien d'un entier
            if (verifier_entier(element)) {
                nombre[taille++] = atoi(element); // Convertit en entier et ajoute au tableau nombre
            } else {
                valide = false;
                break;
            }

            // Réinitialise pour la prochaine valeur
            index = 0;
        } else if (nbre[i] != ' ') {
            element[index++] = nbre[i];
        }
    }
    // En cas de mauvaise saisie
    if (!valide) {
        std::cout << "Erreur ! Vous avez saisi des elements negatifs ou non numeriques.\n";
        std::cout << "Veuillez reessayer." << std::endl;
    }
}



