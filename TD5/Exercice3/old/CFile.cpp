using namespace std;

template<class T>
class CFile: public CList{
public:
  CFile();
  ~CFile();
  CFile& operator<(T i);
};

template<class T>
CFile& CFile<T>::operator<(T i){
  if(tete != NULL){
    Noeud<T>* act = tete;
    while(act->getNext() != NULL){
      act = act->getNext();
    }
    act->setNext(new Noeud(i));
    taille++;
    return *this;
  }
}


template<class T>
CFile<T>::CFile(){}

template<class T>
CFile<T>::~CFile(){
  cout<<"Appel du destructeur CFile."<<endl;
}
