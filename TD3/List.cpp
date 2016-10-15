using namespace std;
#include <iostream>
#include "Chaine.cpp"

class List{
private:
  Chaine* tete;
  int taille;
  
public:
  List(int v){
    tete = new Chaine(v);
    taille = 1;
  }
  List(){
    tete = NULL;
    taille = 0;
  }

  void addEnd(int n){
    Chaine* act = tete;
    while(act->getSuiv() != NULL){
      act = act->getSuiv();
    }
    act->setSuiv(new List(n));
    taille++;
  }

  void addDebut(int n){
    Chaine* act = new Chaine(n);
    act->setSuiv(tete);
    tete = act;
  }

  int getTaille(){
    return taille;
  }

  ~List(){
    Chaine* act;
    Chaine* tmp;
    if(tete != NULL){
      act = tete;
      while(act->getSuiv() != NULL){
        tmp = act;
        act = act->getSuiv();
        delete tmp;
      }
    }
  }
};
