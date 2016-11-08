#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
using namespace std;
#include "Formes.cpp"

class Segment: public Formes{
private:
  Point p1, p2;
public:
  Segment(Point& _p1, Point& _p2){
    p1 = Point(_p1);
    p2 = Point(_p2);
  }
  Segment(int x1, int y1, int x2, int y2){
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
  }

  void deplacer(int dx, int dy){
    p1.setX(p1.getX()+dx); p1.setY(p1.getY()+dy);
    p2.setX(p2.getX()+dx); p2.setY(p2.getY()+dy);
  }

  void afficher(){
    cout<<"Segment:\nPoint n1: "<<p1.getX()<<" "<<p1.getY()<<"\nPoint n2: "<<p2.getX()<<" "<<p2.getY();
  }

};
