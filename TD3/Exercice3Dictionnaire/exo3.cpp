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

  void setSuiv(Dictionnaire* n){
    suiv = n;
  }

  void addEnd(const char* clef, const char* def){
    Dictionnaire* tmp = this;
    while(tmp->getSuiv() != NULL){
      tmp = tmp->getSuiv();
    }
    tmp->setSuiv(new Dictionnaire(clef, def));
  }

  Dictionnaire* getSuiv(){
    return this->suiv;
  }

  Definition* getDef(){
    return this->d;
  }

  Definition* getDef(int i){
    // Dictionnaire* tmp = this;
    // if(taille == 1){
    //   return this->getDef();
    // }
    // else{
    //   for(int i = 0; i<taille; i++){
    //     if(tmp->getSuiv() != NULL){
    //         tmp = tmp->getSuiv();
    //     }
    //     else{
    //       cerr<<"Le i spécifié est trop grand."<<endl;
    //     }
    //   }
    //   return tmp->getDef();
    // }
  }//TODO: Réécrire cette méthode, elle fait des core dump quand on entre dans le else.

  void afficher(int i){
    Definition* t = getDef(i);
    cout<<t->getClef()<<" : "<<t->getDef()<<endl;
  }

  void afficher(){
    if(taille == 0){
      cerr<<"Le Dictionnaire que vous essayer d'afficher est vide."<<endl;
    }
    else{
      for(int i = 0; i<taille; i++){
        afficher(i);
      }
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
  Dictionnaire d("Damien", "Nambrok");
  d.afficher();
  d.addEnd("Bonjour", "Connard");
  d.afficher();
}
