using namespace std;
#include <iostream>

class Vecteur{
private:
  int* T;
  int taille;
public:
  Vecteur(){
    this->T = new int;
    this->taille = 0;
  }

  Vecteur(int a){
    this->T = new int[1];
    this->T[0] = a;
    this->taille = 1;
  }

  Vecteur(Vecteur& v){
    this->taille = v.getTaille();
    this->T = new int[this->taille];
    for(int i =0; i<this->taille; i++){
      this->T[i] = v.getVal(i);
    }
  }

  void add(int d){
    int* n = new int[this->taille+1];
    int* tmp = this->T;
    for(int i = 0; i<this->taille; i++){
      n[i] = tmp[i];
    }
    n[this->taille] = d;
    this->taille +=1;
    this->T = n;
    delete tmp;
  }

  int getTaille() const{
    return this->taille;
  }

  int getVal(int i) const{
    return this->T[i];
  }

  void afficher(){
    for(int i = 0; i<this->taille; i++){
      cout<<i<<" "<<T[i]<<endl;
    }
  }

  bool operator==(Vecteur& v){
    if(this->taille != v.getTaille()){
      return false;
    }
    for(int i = 0; i<this->taille; i++){
      if(this->T[i]!=v.getVal(i)){
        return false;
      }
    }
    return true;
  }

  int operator[](int i){
    return this->getVal(i);
  }

  void operator+=(int d){
    add(d);
  }

  // <<
  // >>

};

int main(){
  cout<<"Hello World!"<<endl;
  Vecteur T(10);
  T.afficher();
  T+=13;
  T.afficher();
  T+= 1002;
  T.afficher();
}
