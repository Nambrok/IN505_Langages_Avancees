using namespace std;
#include <iostream>
#include "PointColor.cpp"

int main(int argc, char* argv[]){
  cout<<"Exercice1PointsColores/MainTest.cpp | "<<argv[0]<<endl;
  Point p(10, 10);
  p.afficher();
  PointColor c(12, 11, Bleu);
  c.afficher();
  PointColor d;
  d.afficher();
  d.cloner(c);
  d.afficher();
}
