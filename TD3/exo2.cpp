using namespace std;
#include <iostream>

class Vecteur{
private:
  int T[];
  int taille;
public:
  Vecteur(){
    this->T = new int[0];
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

  bool operator==(Vecteur& v){
    if(this->taille != v.getTaille()){
      return false;
    }
    for(int i = 0; i<this->taille; i++){
      if(this->taille[i]!=v.getVal(i)){
        return false;
      }
    }
    return true;
  }

  int operator[](int i){
    return this->getVal(i);
  }
  // void operator+=(int d){
  //   add(i);
  // }
  //
  // <<
  // >>
  //
  // void add(int d){
  //
  // }

  int getTaille() const{
    return this->taille;
  }

  int getVal(int i) const{
    return this->T[i];
  }


  ~Vecteur(){
    delete this->T;
  }
};

int main(){
  cout<<"Hello World!"<<endl;
  Vecteur T(10);
  cout<<T[0];
}
