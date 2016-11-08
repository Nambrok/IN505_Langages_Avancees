using namespace std;

class CFile: public CList{
public:
  CFile();
  ~CFile();
  CFile& operator<(int i);
};

CFile& CFile::operator<(int i){
  if(tete != NULL){
    Noeud* act = tete;
    while(act->getNext() != NULL){
      act = act->getNext();
    }
    act->setNext(new Noeud(i));
    taille++;
    return *this;
  }
}
