using namespace std;
#include <iostream>
#include "Definition.cpp"

class Dictionnaire{
private:
  Definition* d;
  Dictionnaire* suiv;
  int taille;

public:
  Dictionnaire(const CString& clef, const CString& def){
    d = new Definition(clef, def);
    suiv = NULL;
    taille = 1;
  }

  Dictionnaire(const char* clef, const char* def){
    d = new Definition(clef, def);
    suiv = NULL;
    taille = 1;
  }
  Dictionnaire(){
    d = NULL;
    suiv = NULL;
    taille = 0;
  }

  Dictionnaire* getSuiv(){
    return this->suiv;
  }

  Definition* getDef(){
    return this->d;
  }

  Definition* getDef(int i){
    Dictionnaire* tmp = this;
    for(int i = 0; i<taille; i++){
      tmp = tmp->getSuiv();
    }
    return tmp->getDef();
  }

  void afficher(int i){
    cout<<getDef(i)->getDef()<<endl;
  }

  void afficher(){
    for(int i = 0; i<taille; i++){
      afficher(i);
    }
  }

  ~Dictionnaire(){
    Dictionnaire *tmp, *act;
    act = this;
    tmp = act;
    while(act->getSuiv() != NULL){
      act = act->getSuiv();
      delete tmp;
      tmp = act;
    }
  }
};

int main(){
  Dictionnaire d(new CString("Damien"), new CString("Nambrok"));
  d.afficher();
}
