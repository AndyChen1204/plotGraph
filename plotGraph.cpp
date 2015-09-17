#include"rec.h"
#include<list>
#include<math.h>
#include<cassert>

void parser(const char* fileName);

list<Rec*> recList;
list<Rec*>::iterator recIter;

double xmax = 0;
double xmin = 0; 
double ymax = 0;
double ymin = 0;

int main(int argc, const char* argv[])
{
  parser(argv[1]);  
  
  ofstream ofs;
  ofs.open(argv[2]);
  assert(ofs);

  for(recIter = recList.begin(); recIter != recList.end(); ++recIter)
  {
    (*recIter) -> plot(ofs);
  }
  
  ofs << "axis([" << xmin << ", " << xmax << ", " << ymin << ", " << ymax << "])" ;
}

void parser(const char* fileName)
{
  ifstream ifs;
  ifs.open(fileName);
  assert(ifs);

  string sTemp;
  getline(ifs, sTemp);  
  getline(ifs, sTemp);  
  getline(ifs, sTemp);  
  getline(ifs, sTemp);  
  getline(ifs, sTemp);  
  getline(ifs, sTemp);  

  ifs >> sTemp;
  assert(sTemp == "box");
  
  while(sTemp == "box")
  {
    getline(ifs, sTemp);
    getline(ifs, sTemp);
    getline(ifs, sTemp);
    
    ifs >> sTemp >> sTemp;
    assert(sTemp == "5");
    double x1,x2,x3,x4;
    double y1,y2,y3,y4;

    ifs >> x1 >> y1;
    if(xmin == 0)xmin = x1;
    else if(xmin > x1)xmin = x1;
    if(ymin == 0)ymin = y1;
    else if(ymin > y1)ymin = y1;

    ifs >> x2 >> y2;
    ifs >> x3 >> y3;
    if(xmax == 0)xmax = x3;
    else if(xmax < x1)xmax = x3;
    if(ymax == 0)ymax = y3;
    else if(ymax < y3)ymax = y3;
    ifs >> x4 >> y4;

    Rec* recTemp = new Rec(x1,y1,x2,y2,x3,y3,x4,y4);
    recList.push_back(recTemp);

    ifs >> sTemp >> sTemp;
    ifs >> sTemp >> sTemp;
  }
}
