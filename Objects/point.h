//211 - Kikteva Veronika
//Zadacha 1

#ifndef point_h
#define point_h

#include <stdio.h>
class Canvas;
// interface dlya raznyh geometricheskih objectov, podderzhivausch`ih bazovye operacii (otrisovku)
class IGeom{
public:
    //eto abstractnyi class
    // virtual - realizacia polimorfizma v cpp (declariruet nalichie etoi funcii u naslednikov)
    virtual
    // metod draw vozvrasch'aet stroku - mi zhe risuem v gnuplot (logichnim obrazom ne menyaa ekzemplyar, poetomu const)
    char * draw() const
    { return 0; }
    int type = 0;
    virtual double getX() const { return 0;}
    virtual double getY() const { return 0;}
    virtual ~IGeom(){}
};

//klass Point eto geometricheskaya figura - nasleduet Geom Inteface
class Point :public IGeom{
protected:
    //ego coordinati
    double mX;
    double mY;
public:
    Point(double=0, double=0);
    bool operator==(const Point& rhs) const;
    double getX() const override;
    double getY() const override;
    void   setX(double x){ mX = x; }
    void   setY(double y){ mY = y; }
    double distanceTo(const Point &) const;
    bool operator<(const Point& rhs) const {
        return mX < rhs.mX || mY < rhs.mY;
    }
    //realizuet funciu draw is IGeom (pereopredel'aet ee dl'a tochki)
    char * draw() const override;
    ~Point() override{}
};

#endif /* point_hpp */
