#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
using namespace std;
#include "Formes.cpp"

class Rectangle: public Formes{
private:
  Point c1;
  int l, c;
public:
  Rectangle(int x, int y, int l, int c);
  void afficher();
  void deplacer(int x, int y);
  ~Rectangle();
};

Rectangle::Rectangle(int x, int y, int l, int c){
  c1 = Point(x, y);
  this->l = l;
  this->c = c;
}

void Rectangle::afficher(){
  cout<<"Rectangle \n Point p: "<<c1<<"\nlongueur: "<<l<<"\nlargeur: "<<c;
}

void Rectangle::deplacer(int dx, int dy){
    c1.moveTo(c1.getX()+dx, c1.getY()+dy);
}

Rectangle::~Rectangle(){
  cout<<"destruction du Rectangle";
}
