using namespace std;
#include <iostream>
#include "List.cpp"


class Vecteur{
private:
  List* l;
public:
  Vecteur(){
    l = new List();
  }

  Vecteur(int a){
    l = new List(a);
  }

  Vecteur(Vecteur& v){
    l = new List();
    //TODO: Ecrire cette méthode, du genre for(int i = 0; i<v.getTaille(); i++){l.addEnd(v.getVal(i));}
  }

  void add(int d){
    l->addEnd(d);
  }

  int getTaille() const{
    return l->getTaille();
  }

  int getVal(int i) const{
    return l->getVal(i);
  }

  void afficher(){
    for(int i = 0; i<l->getTaille(); i++){
      cout<<i<<" "<<l->getVal(i)<<endl;
    }
  }

  bool operator==(Vecteur& v){
    if(this->getTaille() != v.getTaille()){
      return false;
    }
    for(int i = 0; i<this->getTaille(); i++){
      if(l->getVal(i)!=v.getVal(i)){
        return false;
      }
    }
    return true;
  }


  Vecteur& operator=(const Vecteur& a){
    delete l;
    l = new List();
    for(int i = 0; i<a.getTaille(); i++){
      l+=a;
    }
  }

  int operator[](int i) const{
    return l->getVal(i);
  }

  void operator+=(int d){
    l->addEnd(d);
  }

  // Vecteur& operator+(Vecteur& v){
  //   Vecteur* n = new Vecteur();
  //   if(this->taille == v.getTaille()){
  //     for(int i = 0; i<this->taille; i++){
  //       n+=(this->T[i]+v[i]);
  //     }
  //   }
  //   return *n;
  // }

  // void afficher(ostream &flux) const{
  //   for(int i = 0; i<this->taille; i++){
  //
  //   }
  //   flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
  // }

  // <<
  // >>
  ~Vecteur(){
    delete l;
  }
};

int main(){
  Vecteur T(10);
  Vecteur A(10);
  T+= 13;
  T.afficher();
  A.afficher();

}
