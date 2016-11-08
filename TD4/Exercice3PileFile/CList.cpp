class Noeud{
private:
  int val;
  Noeud* next;
public:
  Noeud(int v);
  Noeud(const Noeud& n);
  ~Noeud();

  int getVal() const;
  Noeud* getNext() const;
  void setNext(Noeud* n);
};

Noeud::Noeud(int v){
  val= v;
  next = NULL;
}

Noeud::Noeud(const Noeud& n){
  val = n.getVal();
  Noeud* ptr = n.getNext();
  if(ptr == NULL)
    next = NULL;
  next = new Noeud(ptr->getVal());
  ptr = ptr->getNext();
  Noeud* tmp = next;
  while(ptr != NULL){
    tmp = new Noeud(ptr->getVal());
    ptr = ptr->getNext();
    tmp = tmp->getNext();
  }
}

Noeud::~Noeud(){
  delete next;
}

int Noeud::getVal() const{
  return val;
}

Noeud* Noeud::getNext() const{
  return next;
}

void Noeud::setNext(Noeud* n){
  next = n;
}

class CList{
protected:
  Noeud* tete;
  int taille;
public:
  CList();
  ~CList();

  virtual int getTop() = 0;

  Noeud* getTete();
  virtual CList& operator<(int i) = 0;
  virtual CList& operator>(int& i) = 0;
};

CList::CList(){
  tete = NULL;
}

CList::~CList(){
  delete tete;
}

Noeud* CList::getTete() const{
    return tete;
}

CList& CList::operator>(int& i){
  if(tete != NULL){
    i = tete->getVal();
    Noeud* tmp = tete->getNext();
    tete->setNext(NULL);
    delete tete;
    tete = tmp;
  }
  else{
    cerr<<"Liste vide"<<endl;
    return *this;
  }
}

ostream& operator<<(ostream& o, const CList& p){
  Noeud* ptr = p.getTete();
  while(ptr != NULL){
    o<<ptr->getVal()<<' ';
    ptr = ptr->getNext();
  }
  o<<endl;
  return o;
}
