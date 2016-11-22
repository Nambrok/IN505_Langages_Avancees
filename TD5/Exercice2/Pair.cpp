using namespace std;
#include <typeinfo>
#include <string.h>

template<class T>
class Pair;

template<class T>
ostream& operator<<(ostream& o, Pair<T>& p);

template<class T>
class Pair{
private:
  T p1, p2;
public:
  Pair(T _p1, T _p2){
      p1 = _p1;
      p2 = _p2;
  }

  T getMax(){
    if(strcmp(typeid(p1), typeid(int)) || strcmp(typeid(p1), typeid(float))){
        return (p1>p2?p1:p2);
    }
    else{
      cerr<<"Fonction non encore implémenté pour ce type "<<typeid(p1).name()<<"."<<endl;
    }
  }

  T getP1(){
    return p1;
  }

  T getP2(){
    return p2;
  }

  ~Pair(){
    // cout<<"Destruction d'un Pair"<<endl;
  }

  friend ostream& operator<< <>(ostream& o, Pair<T>& p);

};

template<class T>
ostream& operator<<(ostream& o, Pair<T>& p){
  o<<p.getP1();
  o<<" ";
  o<<p.getP2();
  return o;
}
