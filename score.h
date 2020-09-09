#ifndef __SCORE_H__
#define __SCORE_H__

#include <string>

class Score{
  private:
    long meilleurScore;
    long numeroPartie;
    std::string loginJoueur;

  public:
    Score(long numero_partie, std::string login_joueur, long meilleur_score){
      this->numeroPartie = numero_partie;
      this->loginJoueur = login_joueur;
      this->meilleurScore = meilleur_score;
    }
    
    Score(long meilleur_score){
      this->meilleurScore = meilleur_score;
      this->numeroPartie = 0;
      this->loginJoueur = "";
    }

    long getMeilleurScore() const { return this->meilleurScore; }
    long getNumeroPartie() const { return this->numeroPartie; }
    std::string getLoginJoueur()const { return this->loginJoueur; }

    bool operator<(const Score& joueur_a_droite) const{
      if(this->meilleurScore < joueur_a_droite.meilleurScore) return false;
      return true;
    }
};

#endif