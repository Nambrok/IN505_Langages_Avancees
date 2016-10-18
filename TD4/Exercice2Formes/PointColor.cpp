using namespace std;
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#include "Point.cpp"

enum COLOR{
  Blanc, Bleu, Rouge, Vert, Orange, Noir, Jaune, Violet, Rose, Marron, Gris
};

class PointColor : Point{
private:
  COLOR color;
public:
  PointColor():Point(0,0){
    color = Blanc;
  }

  PointColor(int x, int y, COLOR c): Point(x, y){
    color = c;
  }

  virtual void afficher();
  virtual void cloner(const PointColor& p);
  const char* getColor();
  COLOR getColorE() const;

  ~PointColor(){
  }
};

void PointColor::afficher(){
  cout<<getX()<<"."<<getY()<<" "<<getColor()<<endl;
}

void PointColor::cloner(const PointColor& p){
  setX(p.getX());
  setY(p.getY());
  color = p.getColorE();
}

const char* PointColor::getColor(){
  switch(color){
      case Blanc: return "Blanc";
      case Bleu: return "Bleu";
      case Rouge: return "Rouge";
      case Vert: return "Vert";
      case Orange: return "Orange";
      case Noir: return "Noir";
      case Jaune: return "Jaune";
      case Violet: return "Violet";
      case Rose: return "Rose";
      case Marron: return "Marron";
      case Gris: return "Gris";
  };
  // Blanc, Bleu, Rouge, Vert, Orange, Noir, Jaune, Violet, Rose, Marron, Gris
}

COLOR PointColor::getColorE() const{
  return color;
}
