using namespace std;
#include <iostream>
#include "CString.cpp"

class Definition{
private:
  CString clef;
  CString def;

public:
  Definition(const CString& _clef, const CString& _def): clef(_clef), def(_def){}

  Definition(string& clef, string& def){
    this->clef = CString(clef);
    this->def = CString(def);
  }

  char* getClef(){
    return this->clef.getString();
  }

  char* getDef(){
    return this->def.getString();
  }

  CString getSClef(){
    return this->clef;
  }

  CString getSDef(){
    return this->def;
  }

  void afficher(){
    cout<<this->clef.getString()<<" : "<<this->def.getString()<<endl;
  }
};
