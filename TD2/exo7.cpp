using namespace std;
#include <iostream>
#include "CString.cpp"

class Definition{
private:
  CString clef;
  CString def;

public:
  Definition(const CString& clef, const CString& def){
    this->clef = clef;
    this->def = def;
  }

  Definition(const char* clef, const char* def){
    this->clef = CString(clef);
    this->def = CString(def);
  }

  char* getClef(){
    return this->clef.getString();
  }

  char* getDef(){
    return this->def.getString();
  }

  void afficher(){
    cout<<this->clef.getString()<<" : "<<this->def.getString()<<endl;
  }
};

int main(){
  Definition homer("Homer", "Buveur de bière");
  homer.afficher();
}
