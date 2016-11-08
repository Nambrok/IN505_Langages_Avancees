using namespace std;
#include <iostream>
#include "Pair.cpp"

int main(){
 int i=5, j=6;
 float l=10.0, m=5.0;
 Pair<int> myInts (i,j); //créer une paire d’entiers
 Pair<float> myFloats (l,m); //créer une paire de flottants
 cout << myInts.getMax()<< endl; //affiche le plus grand des 2 entiers
 cout << myFloats.getMax()<<endl;//affiche le plus grand des 2 flottants

 char c1='c', c2='d';
 Pair<char> myChars(c1,c2);//creer un objet qui contient une paire d’entiers
 cout << myChars.getMax()<< endl;
 return 0 ;
 }
