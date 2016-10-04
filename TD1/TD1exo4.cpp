using namespace std;
#include <iostream>

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

  void setX(int _x){
    this->x = _x;
  }

  void setY(int _y){
    this->y = _y;
  }

  void setCoords(int _x, int _y){
    this->x = _x;
    this->y = _y;
  }

  int getX() const{
    return this->x;
  }

  int getY() const{
    return this->y;
  }

  void afficher() const{
    cout<<getX()<<"."<<getY()<<endl;
  }

  void cloner(const Point& p){
    this->x = p.getX();
    this->y = p.getY();
  }

  ~Point(){
    cout<<"Appel au destructeur\n";
  }

};

int main(){

  Point p;
  p.afficher();
  Point *y = new Point(10, 10);
  y->afficher();
  Point *x = new Point(*y);
  x->afficher();
  x->cloner(p);
  x->afficher();

  delete y;
  delete x;
}
