using namespace std;
#include <iostream>
#include "CList.cpp"

template<class T>
class CPile: public CList<T>{
public:
  CPile(){}
  ~CPile(){}

  CPile<T<& operator<(T x);
};

CPile<T>& CPile::operator<(T x){
  Noeud<T>* ptr = this->tete;
  this->tete = new Noeud<T>(x);
  this->tete->setNext(ptr); taille++;
  return *this;
}
