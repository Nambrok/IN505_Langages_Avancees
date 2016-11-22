template<class T>
class Noeud{
private:
  T val;
  Noeud<T>* next;
public:
  Noeud(T v);
  Noeud(const Noeud& n);
  ~Noeud();

  T getVal() const;
  Noeud<T>* getNext() const;
  void setNext(Noeud<T>* n);
};

template<class T>
Noeud<T>::Noeud(T v){
  val= v;
  next = NULL;
}

template<Class T>
Noeud<T>::Noeud(const Noeud& n){
  val = n.getVal();
  Noeud<T>* ptr = n.getNext();
  if(ptr == NULL)
    next = NULL;
  next = new Noeud(ptr->getVal());
  ptr = ptr->getNext();
  Noeud<T>* tmp = next;
  while(ptr != NULL){
    tmp = new Noeud(ptr->getVal());
    ptr = ptr->getNext();
    tmp = tmp->getNext();
  }
}

template<class T>
Noeud<T>::~Noeud(){
  delete next;
}

template<class T>
T Noeud<T>::getVal() const{
  return val;
}

template<class T>
Noeud<T>* Noeud<T>::getNext() const{
  return next;
}

template<class T>
void Noeud<T>::setNext(Noeud* n){
  next = n;
}

template<class T>
class CList{
protected:
  Noeud<T>* tete;
  int taille;
public:
  CList();
  ~CList();

  virtual T getTop() = 0;

  Noeud<T>* getTete();
  virtual CList& operator<(int i) = 0;
  virtual CList& operator>(int& i) = 0;
};

template<class T>
CList<T>::CList(){
  tete = NULL;
}

template<class T>
CList<T>::~CList(){
  delete tete;
}

template<class T>
Noeud<T>* CList<T>::getTete() const{
    return tete;
}

template<class T>
CList& CList<T>::operator>(T& i){
  if(tete != NULL){
    i = tete->getVal();
    Noeud<T>* tmp = tete->getNext();
    tete->setNext(NULL);
    delete tete;
    tete = tmp;
  }
  else{
    cerr<<"Liste vide"<<endl;
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
  o<<endl;
  return o;
}
