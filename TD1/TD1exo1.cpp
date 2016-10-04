using namespace std;
#include <iostream>
#include <string.h>

int main(){
  //std::cout<<std::endl;

  //Question a :
  int tab[10] = {1,2,3,4,5,6,7,8,9,10};
  int* p = tab;
  for(int i = 0; i<10; i++){
    cout<<p[i];
    cout<<" ";
  }
  cout<<endl;


  //Question b :
  const char* tabC[3] = {"truc", "machin", "chose"};
  //{"truc", "machin", "chose"};
  /*strcpy(tabC[0], "truc");
  strcpy(tabC[1], "machin"); //Y'a un core dumped ici si tabC n'est pas initialisé, mais j'ai un warning si j'initialise.
  strcpy(tabC[2], "chose");*/ //Il manquait un const avant tabC.

   for(int i = 0; i<3; i++){
     cout<<tabC[i] <<endl;
   }
   char* tabC2[3];
   for(int i = 0; i<3; i++){
      tabC2[i] = new char[strlen(tabC[i])+1];
      strcpy(tabC2[i], tabC[i]);
   }

   for(int i = 0; i<3; i++){
     cout<<tabC2[i] <<endl;
     delete tabC2[i];
   }



}
