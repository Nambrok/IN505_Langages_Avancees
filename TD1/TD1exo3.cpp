using namespace std;
#include <iostream>

void tableauEcriture(int tab[], const int taille);
void tableauLecture(const int tab[], const int taille);

int main(){

  int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  tableauLecture(tab, 10);
  tableauEcriture(tab, 10);
  tableauLecture(tab, 10);
}

//Question a:
void tableauEcriture(int tab[], const int taille){
  for(int i = 0; i<taille; i++){
    tab[i] = i;
  }
}

//Question b:
void tableauLecture(const int tab[], const int taille){
  for(int i = 0; i<taille; i++){
    cout<<tab[i]<<" ";
  }
  cout<<endl;
}
