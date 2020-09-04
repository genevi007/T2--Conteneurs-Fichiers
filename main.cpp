#include <iostream>
#include <fstream>
#include <climits>
#include <set>

#include "score.h"

int main() {
  std::set<Score> score;
  int choix;

  do{
    std::cout << "=== GÉNÉRATEUR DE FICHIER COMPATIBLE POUR ASTEROSTORM ===" << std::endl;
    std::cout << " 1. Générer un fichier Asterostorm compatible " << std::endl;
    std::cout << " 2. Quitter" << std::endl;

    std::cout << std::endl << " Votre choix : ";
    std::cin >> choix;    

    if(std::cin.fail() == true){
      std::cout << std::endl << " *Mauvais choix, veuillez recommencer!" << std::endl;
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      std::cout << std::endl;
    }

    else if(choix==1){

      //Lecture du fichier hiscore.txt
      std::ifstream hiscore("hiscore.txt");
        long le_numero;
        std::string le_login;
        long le_score;

        hiscore >> le_numero;
        hiscore >> le_login;
        hiscore >> le_score;

        Score joueur(le_numero,le_login,le_score);   
        
      hiscore.close();

      //Écriture du fichier asterostorm.txt
      std::ofstream asterostorm("asterostorm.txt");
      
      std::cout << std::endl << " *Nouveau fichier généré avec succès!" << std::endl;
      std::cout << std::endl;
    }

    else if(choix!=1 && choix!=2){
      std::cout << std::endl << " *Mauvais choix, veuillez recommencer!" << std::endl; 
    }
  }while(choix!=2);

  std::cout << std::endl << " Merci et à la prochaine!" << std::endl;  
}