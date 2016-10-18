#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
using namespace std;

class Formes{
  virtual void afficher()=0;
  virtual void deplacer(int dx, int dy)=0;
  ~Formes(){}
};
