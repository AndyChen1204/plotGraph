#include"rec.h"

Rec::Rec(double _x1, double _y1, double _x2, double _y2,
         double _x3, double _y3, double _x4, double _y4)
{
  x1 = _x1;
  y1 = _y1;
  x2 = _x2;
  y2 = _y2;
  x3 = _x3;
  y3 = _y3;
  x4 = _x4;
  y4 = _y4;
}

void Rec::plot(ofstream& ofs)
{
  ofs << "rectangle('Position', [";
  ofs << x1 << " ";
  ofs << y1 << " ";
  ofs << x3 - x1 << " ";
  ofs << y3 - y1 << " ";
  ofs << "], 'FaceColor', [0 0 0])";
  ofs << endl;
}
