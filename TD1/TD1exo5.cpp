using namespace std;
#include <iostream>
#include <valarray>
#include "Point.cpp"

class Segment{

private:
  Point* p1;
  Point* p2;

public:
  Segment(){
    this->p1 = new Point();
    this->p2 = new Point();
  }

  Segment(Point& _p1, Point& _p2):p1(p1),p2(p2){

  }

  Segment(int x1, int y1, int x2, int y2){
    this->p1 = new Point(x1, y1);
    this->p2 = new Point(x2, y2);
  }

  int longueur() const{
    return sqrt(((p2->getX()-p1->getX())*(p2->getX()-p1->getX()))+((p2->getY()-p1->getY())*(p2->getY()-p1->getY())));
    //Corrigé en enlevant ^2 et le remplacant par son équivalent (p2->getY()-p1->getY()).
  }

  int estVertical() const{
    if(p1->getX() == p2->getX()){
      return 1;
    }
    else return 0;
  }

  int estHorizontal() const{
    if(p1->getY() == p2->getY()){
      return 1;
    }
    else return 0;
  }

  int estSurDiagonale() const{
    if(!(this->estHorizontal()) && !(this->estVertical())){
      return 1;
    }
    else return 0;
  }

  void afficher() const{
    p1->afficher();
    p2->afficher();
  }

  int estCroise(const Segment& s) const{

  }

  ~Segment(){
    delete p1;
    delete p2;
  }
};

int main(){
  Segment* s = new Segment(10, 0, 0, 10);
  cout<<s->longueur()<<endl;
  cout<<"Est Vertical"<<s->estVertical()<<endl;
  cout<<"Est Horizontal"<<s->estHorizontal()<<endl;
  cout<<"estSurDiagonale"<<s->estSurDiagonale()<<endl;
  delete s;
}
