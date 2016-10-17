using namespace std;
#include <iostream>
#include "Definition.cpp"

int main(){
    cout<<"Debut :"<<endl;
  Definition n(CString("Damien"), CString("L'asperger original."));
  cout<<n.getClef()<<" "<<n.getDef()<<endl;
}
