using namespace std;
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif


class Point{

private:
  int x;
  int y;

public:

  Point(){
    this->x = 0;
    this->y = 0;
  }
  Point(int x, int y){
    this->x = x;
    this->y = y;
  }

  Point(const Point& p){
    this->x = p.getX();
    this->y = p.getY();
  }

  void setX(int _x);
  void setY(int _y);
  void setCoords(int _x, int _y);
  int getX() const;
  int getY() const;
  virtual void afficher() const;
  virtual void cloner(const Point& p);

  void moveTo(int x, int y){

  ~Point(){
    // afficher();
    // cout<<"Appel au destructeur\n";
  }

};

void Point::setX(int _x){
  this->x = _x;
}

void Point::setY(int _y){
  this->y = _y;
}

void Point::setCoords(int _x, int _y){
  this->x = _x;
  this->y = _y;
}

int Point::getX() const{
  return this->x;
}

int Point::getY() const{
  return this->y;
}

void Point::afficher() const{
  cout<<getX()<<"."<<getY()<<endl;
}

void Point::moveTo(int x, int y){
  this->x = x;
  this->y = y;
}
void Point::cloner(const Point& p){
  this->x = p.getX();
  this->y = p.getY();
}
