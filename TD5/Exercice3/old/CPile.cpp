#include "CList.cpp"

template<class T>
class CPile: public CList{
public:
  CPile();
  ~CPile();
  CPile& operator<(T i);
};

template<class T>
CPile& CPile<T>::operator<(T i){
    Noeud* ptr =tete;
    tete = new Noeud(i);
    tete->setNext(ptr); taille++;
    return *this;
}

template<class T>
CPile<T>::CPile(){}

template<class T>
CPile<T>::~CPile(){
  cout<<"Appel du destructeur CPile"<<endl;
}
