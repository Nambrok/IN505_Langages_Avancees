using namespace std;
#include <iostream>

#include <string.h>

class CString{
private:
  char* s;
  int taille;
//  static int _nbrChaines;

public:
  //Constructeur
  CString(){
    this->s = new char;
    this->s[0] = '\0';
    this->taille = 0;
//    _nbrChaines += 1;
  }

  CString(const char* c){
    this->taille = strlen(c);
    this->s = new char[this->taille];
    strcpy(this->s, c);
//    _nbrChaines += 1;
  }

  CString(const char c){
    this->taille = 1;
    this->s = new char[2];
    this->s[0] = c;
    this->s[1] = '\0';
//    _nbrChaines += 1;
  }

  //Surcharge des opérateurs
  bool operator<=(CString& b){
    return infOuEgale(b);
  }

  bool operator>(CString& b){
    return plusGrandQue(b);
  }

  CString operator+(CString& b){
    return plus(b);
  }

  bool operator==(CString& b){
    return egal(b);
  }

  void operator=(CString &a)
  {
    this->taille = a.getTaille();
    this->s = a.getString();
  }

  //Getter
  char* getString(){
    return this->s;
  }

  int getTaille() const{
    return this->taille;
  }

//  static int nbrChaines();

  //Méthodes
  CString plus(CString& c) const{
    char buf[this->taille + c.getTaille()];
    strcpy(buf, this->s);
    return CString(strcat(buf, c.getString()));
  }

  CString plus(const char* c) const{
    // return CString(strcat(this->s, c)); //Ne marche pas et fais : *** Error in `./a.out': double free or corruption (fasttop): 0x000000000187e070 ***
    //Abandon (core dumped)
    char buf[this->taille+strlen(c)];
    strcpy(buf, this->s);
    return CString(strcat(buf, c));
  }

  CString plus(const char c) const{
    char buf[this->taille+1];
    strcpy(buf, this->s);
    buf[this->taille] = c;
    buf[this->taille+1] = '\0';
    return CString(buf);
  }

  bool egal(CString& ch){
    if(strcmp(this->s, ch.getString()) == 0){
      return true;
    }
    else return false;
  }

  bool plusGrandQue(CString& ch){
      if(strcmp(this->s, ch.getString())>0){
        return true;
      }
      else return false;
  }

  bool infOuEgale(CString& ch){
    if(strcmp(this->s, ch.getString())<= 0){
      return true;
    }
    else return false;
  }

  CString plusGrand(CString s2){
      if(this->plusGrandQue(s2)){
        return *this;
      }
      else return s2;
  }

  ~CString(){
    // delete this->s; //Crée un problème car la chaine de caractère n'est pas dupliqué et il cherche à la delete plusieurs fois.
    //Celà crée des problèmes car on ne libère pas la mémoire que l'on a alloué dynamiquement.
    //FUITE DE MEMOIRE rgb(255, 0, 0);
//    _nbrChaines--;
  }
};

//int CString::_nbrChaines = 0;
//
//int CString::nbrChaines(){
//  return _nbrChaines;
//}
