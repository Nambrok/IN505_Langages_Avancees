using namespace std;
#include <iostream>

void echange(int& t, int& d);
int main(){
  int i = 10;
  int j = 22;

  cout<<i<<j<<endl;
  echange(i, j);
  cout<<i<<j<<endl;
}

void echange(int& t, int& d){
  int tmp = t;
  t = d;
  d = tmp;
}
