using namespace std;
#include <iostream>
#include "CList.cpp"
#include "CPile.cpp"
#include "CFile.cpp"

int main(){
CPile<int> pile;
CFile<int> file;
CList<int>* ptList = &file;
// * ptList < 0 < 1; //empiler deux valeurs dans la file
// cout << * ptList;
// int i;
// * ptList > i; //récupérer une valeur de la file dans i
// cout << * ptList << " i=" << i;
// ptList = &pile;
// * ptList < 0 < 1; //empiler deux valeurs dans la pile
// cout << *ptList;
// * ptList > i; //récupérer une valeur de la pile dans i
// cout << * ptList << " i=" << i;
return 0;
}
