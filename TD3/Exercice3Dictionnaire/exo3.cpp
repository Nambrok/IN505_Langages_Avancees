using namespace std;
#include <iostream>
#include "Definition.cpp"

class Noeud{
  private:
    Definition* d;
    Noeud* suiv;

  public:
    Noeud(const char* clef, const char* def):d(clef, def), suiv(NULL);
    Noeud(CString& clef, CString& def):d(clef, def), suiv(NULL);
    Noeud(Definition& d):d(&d), suiv(NULL);

    Noeud* getSuiv(){
      return suiv;
    }

    void setSuiv(Noeud* n){
      suiv = n;
    }

    CString getDef(){
      return d->getDef();
    }

    CString getClef(){
      return d->getClef();
    }

    Definition* getAtt(){
      return d;
    }

    // ostream& operator<<(ostream& o){
    //   o<<d->getClef()<<" : "<<d->getDef()<<endl;
    //   return o;
    // }
};

class Dictionnaire{
private:
  Noeud* tete;
  int taille;

public:
  Dictionnaire(const CString& clef, const CString& def){
    tete = new Noeud(clef, def);
    taille = 1;
  }

  Dictionnaire(const char* clef, const char* def){
    tete = new Noeud(clef, def);
    taille = 1;
  }

  Dictionnaire(){
    tete = NULL;
    taille = 0;
  }

  void addEnd(const char* clef, const char* def){
    Noeud* act = tete;
    while(act->getSuiv() != NULL){
      act = act->getSuiv();
    }
    act->setSuiv(new Noeud(clef, def));
  }

  Definition* getDef(int i){
    if(i>taille){
      cerr<<"Le i spécifié est plus grand que la taille de la liste."<<endl;
    }
    else if(i<0){
      cerr<<"Le i spécifié est plus petit que 0."<<endl;
    }
    else{
      Noeud* act = tete;
      for(int j= 0; i<j; j++){
        act = act->getSuiv();
      }
      return act->getAtt();
    }
  }

  void afficher(){
    Noeud* tmp = tete;
    while(tmp->getSuiv() != NULL){
      cout<<tmp;
      tmp = tmp->getSuiv();
    }
  }

  int getTaille(){
    return taille;
  }

  void afficherTaille(){
    cout<<taille<<endl;
  }

  ~Dictionnaire(){
    Noeud* tmp = tete;
    Noeud* act = tete;
    for(int i = 0; i<taille; i++){
      act = act->getSuiv();
      delete tmp;
      tmp = act;
    }
  }
};

int main(){
  Dictionnaire d("Damien", "Nambrok");
  d.afficherTaille();
  d.afficher();
  d.addEnd("Bonjour", "Connard");
  d.afficherTaille();
  d.afficher();
}
