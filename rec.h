#ifndef REC_H
#define REC_H
#include<iostream>
#include<fstream>
#include<list>
#include<math.h>

using namespace std;

class Rec
{
  public:
    Rec(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);
    void plot(ofstream&);
  private:
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
};

#endif
