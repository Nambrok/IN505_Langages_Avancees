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
    act->setSuiv(new Chaine(n));
    taille++;
  }

  void addDebut(int n){
    Chaine* act = new Chaine(n);
    act->setSuiv(tete);
    tete = act;
  }

  Chaine* getTete(){
    return tete;
  }
  
  int getValTete(){
    return tete->getVal();
  }

  bool chercherVal(int n){
    Chaine* act = tete;
    while(act->getSuiv() != NULL && act->getVal() != n){
      act = act->getSuiv();
    }
    if(act->getVal() == n){
      return true;
    }
    return false;
  }

  Chaine* getChaine(int i){
    if(i<= taille){
      int d = 0; Chaine* act = tete;
      while(act->getSuiv() != NULL && d != i){
        act = act->getSuiv();
      }
      return act;
    }
    else{
      return NULL;
    }
  }

  int getVal(int i){
    int d = 0; Chaine* act = tete;
    while(act->getSuiv() != NULL && d != i){
      act = act->getSuiv();
    }
    return act->getVal();
  }

  int operator[](int i){
    int d = 0; Chaine* act = tete;
    while(act->getSuiv() != NULL && d != i){
      act = act->getSuiv();
    }
    return act->getVal();
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
