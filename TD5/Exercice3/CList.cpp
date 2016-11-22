using namespace std;
#include <iostream>
#include "Noeud.cpp"

template<class T>
class CList{
protected:
  Noeud<T>* tete;
  int taille;
public:
  CList(){
    tete = NULL;
  }

  ~CList(){
    if(tete != NULL){
      delete tete;
      tete = NULL;
      taille = 0;
    }
  }

  Noeud<T>* getTete() const{
    return tete;
  }

  virtual CList<T> operator<(T i) = 0;
  CList<T>& operator>(T& i);
  friend ostream& operator<< <>(ostream& o, const CList<T>& p);
};

template<class T>
CList<T>& CList<T>::operator>(T& i){
  if(tete != NULL){
    Noeud<T>* tmp = tete->getNext();
    tete->setNext(NULL);
    i = tete->getVal();
    delete tete;
    tete = tmp;
    taille--;
    return *this;
  }
}

template<class T>
ostream& operator<<(ostream& o, const CList<T>& p){
  Noeud<T>* ptr = p.getTete();
  while(ptr != NULL){
    o<<ptr->getVal()<<' ';
    ptr = ptr->getNext();
  }
  return o;
}
