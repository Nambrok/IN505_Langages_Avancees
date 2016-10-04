using namespace std;
#include <iostream>
#include <list>

class Vecteur{
private:
  list<int> T;
public:
  Vecteur(){
    T = new list();
  }

  Vecteur(int a){
    T = new list();
    T.push_back(a);
  }

  Vecteur(Vecteur& v){
    //Réécrire tous le reste.
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
    return T.size();
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

  Vecteur& operator=(const Vecteur& a){
    delete[] this->T;
    this->taille = a.getTaille();
    this->T = new int[this->taille];
    for(int i =0; i<this->taille; i++){
      this->T[i] = a.getVal(i);
    }
  }

  int operator[](int i){
    return this->getVal(i);
  }

  void operator+=(int d){
    add(d);
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
    delete[] this->T;
  }
};

int main(){
  Vecteur T(10);
  Vecteur A(10);
  T+= 13;
  T.afficher();
  A.afficher();

}
