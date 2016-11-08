using namespace std;

void main(){
CPile pile;
CFile file;
CList* ptList = &file;
* ptList < 0 < 1; //empiler deux valeurs dans la file
cout << * ptList;
int i;
* ptList > i; //récupérer une valeur de la file dans i
cout << * ptList << " i=" << i;
ptList = &pile;
* ptList < 0 < 1; //empiler deux valeurs dans la pile
cout << *ptPile;
* ptList > i; //récupérer une valeur de la pile dans i
cout << * ptList << " i=" << i;
}
