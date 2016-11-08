class Triangle:public Forme{
private:
  PointColor p1, p2, p3;
public:
  Triangle(const PointColor& pc1, const PointColor& pc2, const PointColor& pc3);
  virtual ~Triangle();

  void deplacer(int dx, int dy);
  void afficher();
};

Triangle::~Triangle(){
  cout<<"Destruction du triangle"<<endl;
}

Triangle::Triangle(const PointColor& pc1, const PointColor& pc2, const PointColor& pc3){
  
}
