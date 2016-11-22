using namespace std;
#include <iostream>

template<class T>
class Noeud{
private:
  T val;
  Noeud<T>* next;
public:
  Noeud(T x){
    val = x;
    next = NULL;
  }

  T getVal() const{
    return val;
  }

  Noeud<T>* getNext() const{
    return next;
  }

  void setNext(Noeud<T>* x){
    next = x;
  }

  ~Noeud(){
    
  }
};
