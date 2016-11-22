using namespace std;
#include <iostream>
#include "CList.cpp"

template<class T>
class CFile: public CList<T>{
public:
  CFile(){}
  ~CFile(){}

  CFile<T<& operator<(T x);
};

template<class T>
CFile<T>& CFile::operator<(T x){
  Noeud<T>* tmp = this->tete;
  while (tmp->getNext() != NULL) {
    tmp = tmp->getNext();
  }
  tmp->setNext(new Noeud<T>(x));
  taille++;
  return *this;
}
