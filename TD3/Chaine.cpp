using namespace std;
#include <iostream>

class Chaine{
private:
  int v;
  Chaine* suiv;
public:
  Chaine(int n){
    v = n;
    suiv = NULL;
  }

  void setVal(int n){
    v = n;
  }

  Chaine* getSuiv(){
    return suiv;
  }

  void setSuiv(Chaine* s){
    suiv = s;
  }

  int getVal(){
    return v;
  }

  ~Chaine(){

  }
};
