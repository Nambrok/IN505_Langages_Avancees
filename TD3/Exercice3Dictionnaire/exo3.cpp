using namespace std;
#include <iostream>
#include "Definition.cpp"

class Noeud{
  private:
    Definition* d;
    Noeud* suiv;

  public:
    Noeud(const char* clef, const char* def){
      d = new Definition(clef, def);
      suiv = NULL;
    }
    Noeud(const CString& clef, const CString& def){
      d = new Definition(clef, def);
      suiv = NULL;
    }
    Noeud(Definition* _d){
      d = _d;
      suiv= NULL;
    }

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

    ostream& operator<<(ostream& o){
      o<<d->getClef()<<" : "<<d->getDef()<<endl;
      return o;
    }

    ~Noeud(){
      delete d;
      delete suiv;
    }
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
    taille++;
  }

  /*
  void ajouterDef(const char* clef, const char* def){
    Noeud* act = tete;
    while(act->getSuiv() != NULL){
      act = act->getSuiv();
    }
  }//TODO: Ajout alphabétiquement par les clés des définitions.

  void ajouterDef(Definition& d){
    Noeud* nouv = new Noeud(d);
    taille++;
    if(tete == NULL){
      tete = nouv;
    }
    else{
      Noeud* actuel = tete;
      Noeud* prec = tete;
      while(actuel != NULL && nouv->getDef()->getClef().plusGrandQue(actuel->getDef()->getClef())){
        prec = actuel;
        actuel = actuel->getSuiv();
      }
      if(actuel == prec){
        tete = nouv;
      }
      else{
        prec->setSuiv(nouv);
      }
      nouv->setSuiv(actuel);
    }
  }*/

  CString recherche(const char* clef){
    // CString c = clef;
    CString c(clef);
    Noeud* tmp = tete;
    while(tmp != NULL && tmp->getDef()->getClef() <= c){ // Ne marche que si le dictionnaire est trié par ordre alphabétique.
      if(c == tmp->getClef()){//OH t'as pas la Surcharge == dans CString.cpp, ça va pas marcher.
        return tmp->getDef();
      }
      tmp = tmp->getSuiv();
    }
    return CString();
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
      for(int j= 0; j<i; j++){
        act = act->getSuiv();
      }
      return act->getAtt();
    }
  }

  void afficher(){
    Definition* tmp;
    for(int i = 0; i<taille; i++){
      tmp = getDef(i);
      cout<<tmp->getClef()<<" : "<<tmp->getDef()<<endl;
    }
  }

  int getTaille(){
    return taille;
  }

  void afficherTaille(){
    cout<<taille<<endl;
  }

  ~Dictionnaire(){
    delete tete;
  }
};

int main(){
  Dictionnaire d("Damien", "Nambrok");
  d.afficherTaille();
  d.afficher();
  d.addEnd("Florian", "Chrad");
  d.afficherTaille();
  d.afficher();
}
