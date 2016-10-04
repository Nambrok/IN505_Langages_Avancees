using namespace std;
#include <iostream>
#include "CString.cpp"

int main(){
  CString a("a");
  CString b("bien");
  cout<<a.getString()<<endl;
  cout<<b.getString()<<endl;
  if(a>b){
    cout<<"a>b"<<endl;
  }
  if(a<=b){
    cout<<"a<=b"<<endl;
  }
  else{
    cout<<"a>b"<<endl;
  }
  cout<<(a+b).getString()<<endl;
  b = a;
  cout<<b.getString()<<endl;

}
