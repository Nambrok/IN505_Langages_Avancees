#include "CList.cpp"

class CPile: public CList{
public:
  CPile();
  ~CPile();
  CPile& operator<(int i);
};

CPile& CPile::operator<(int i){
    Noeud* ptr =tete;
    tete = new Noeud(i);
    tete->setNext(ptr); taille++;
    return *this;
}

CPile::CPile(){}

CPile::~CPile(){
  cout<<"Appel du destructeur CPile"<<endl;
}
