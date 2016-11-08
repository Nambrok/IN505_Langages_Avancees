using namespace std;
#include <iostream>
#include "CString.cpp"

template<class T>
T GetMax(T i, T j){
  return (i>j?i:j);
}

int main(){
  int i=5, j=6, k;
  float l=10.0, m=5.0, n;
  k = GetMax(i, j); //retourne le plus grand entre i et j
  n = GetMax(l, m); //retourne le plus grand entre l et m
  cout << k << endl;
  cout << n << endl;
  CString S("Test");
  CString c = GetMax(S, CString("Abc"));
  cout<<S<<endl;
  return 0 ;
}
