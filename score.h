#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <string>

class Score{
  private:
    long meilleurScore;
    long numeroPartie;
    std::string loginJoueur;

  public:
    Score(long numero_partie, std::string login_joueur, long meilleur_score);
    Score(long meilleur_score);

    long getMeilleurScore();
    long getNumeroPartie();
    std::string getLoginJoueur();

};

#endif