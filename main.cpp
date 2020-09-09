#include <iostream>
#include <fstream>
#include <climits>
#include <set>
#include <ctime>

#include "score.h"

//Petite fonction de nettoyage empruntée au cours 
//"Concepts de structuration des données informatiques" :)
void nettoyerStdCin() {
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
  }
}

int main() {
  std::set<Score> score;
  time_t tmm = time(0);   //Date et heure actuelle basée sur le système
  int choix;

  do{
    std::cout << "=== GÉNÉRATEUR DE FICHIER COMPATIBLE POUR ASTEROSTORM ===" << std::endl;
    std::cout << " 1. Générer un fichier Asterostorm compatible " << std::endl;
    std::cout << " 2. Quitter" << std::endl;

    std::cout << std::endl << " Votre choix : ";
    std::cin >> choix;    
    nettoyerStdCin();

    if(std::cin.fail() == true){
      std::cout << std::endl << " *ERREUR! Faites un choix entre 1 et 2" << std::endl;
      std::cout << std::endl;
    }

    else if(choix==1){

      //Lecture du fichier hiscore.txt
      std::ifstream hiscore("hiscore.txt");

      while(!hiscore.eof()){
        long le_numero;
        std::string le_login;
        long le_score;

        try{
          hiscore >> le_numero;
          hiscore >> le_login;
          hiscore >> le_score;
          nettoyerStdCin();

          if(le_numero==0) throw std::out_of_range("Numéro de partie = 0");   //Ligne 4 à 6 de hiscore.txt

          Score joueur(le_numero,le_login,le_score);
          
          if(hiscore.eof() == false){   //Ignorer le dernier '/n'
            score.insert(joueur);                    
          }
        }
        catch (const std::exception& une_exception) {
          std::cout << std::endl;
          std::cout << " *Un ou plrs joueurs avec un numéro 0 ont été ignorés!" << std::endl;
        }
      }
      hiscore.close();

      //Écriture du fichier asterostorm.txt
      std::ofstream asterostorm("asterostorm.txt"); 

      std::set<Score>::iterator iter;
      for (iter=score.begin(); iter!=score.end(); iter++) {
        asterostorm << iter->getLoginJoueur() << std::endl;
        asterostorm << iter->getNumeroPartie() << std::endl;
        asterostorm << "Asterostorm=" << iter->getMeilleurScore() << std::endl;
      }
      asterostorm.close();
      
      std::cout << "----------------------------------------" << '\n';
      std::cout << " *En date du : " << ctime(&tmm) << '\n';
      std::cout << " *NOUVEAU FICHIER généré avec succès!" << '\n';
      std::cout << "----------------------------------------" << '\n';
      std::cout << "  Merci et à la prochaine!" << std::endl;  
      break;
    }

    else if(choix!=1 && choix!=2){
      std::cout << std::endl << " *ERREUR! Faites un choix entre 1 et 2" << std::endl;
      std::cout << std::endl;      
    }
  }while(choix!=2);

  if(choix==2){
    std::cout << "----------------------------------------" << '\n';
    std::cout << " *En date du : "  << ctime(&tmm) << '\n';
    std::cout << "  AUCUN NOUVEAU FICHIER n'a été généré!" << '\n';
    std::cout << "----------------------------------------" << '\n';      
    std::cout << "  Merci d'être passé! " << std::endl;
  }
  
}