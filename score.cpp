#include "score.h"

    Score::Score(long numero_partie, std::string login_joueur, long meilleur_score){
      this->numeroPartie = numero_partie;
      this->loginJoueur = login_joueur;
      this->meilleurScore = meilleur_score;
    }
    
    Score::Score(long meilleur_score){
      this->meilleurScore = meilleur_score;
      this->numeroPartie = 0;
      this->loginJoueur = "";
    }