#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include "../utils.h"

using namespace std;

class Point3D{
  public:
    double x, y, z;

    Point3D(double _x, double _y, double _z){
      this->x = _x;
      this->y = _y;
      this->z = _z;
    }

    bool operator< (const Point3D& right) const{
      if(this->x < right.x)
        return true;
      else if(this->x > right.x)
        return false;
      else{
        if(this->y < right.y)
          return true;
        else if(this->y > right.y)
          return false;
        else if(this->y == right.y){
          if(this->z < right.z)
            return true;
          else
            return false;
        }
      }
    }

    void print() const{
      cout << "(" << this->x << ", "
        << this->y << ", "
        << this->z << ")" << endl;
    }
};

void printSet(const set<Point3D>& _pSet){
  for(auto itr = _pSet.begin(); itr != _pSet.end(); itr ++){
    Point3D p = *itr;
    p.print();
  }
}

int main(int argc, char *argv[]){
  set<Point3D> pSet;
  // initialize
  for(int i = 0; i < 10; i++){
    double x = fRand(0, 100), y = fRand(0, 100), z = fRand(0, 100);
    Point3D point(x, y, z);
    pSet.insert(point);
  }
  // iterate
  cout << "traverse after initialization:" << endl;
  printSet(pSet);
  // erase
  cout << "traverse after erasing begin itr:" << endl;
  pSet.erase(pSet.begin());
  printSet(pSet);

  Point3D tmp = *(pSet.begin()), newTmp(tmp.x, tmp.y, tmp.z);
  pSet.emplace(newTmp);
  cout << "After emplace the same second:" << endl;
  printSet(pSet);

  pSet.insert(newTmp);
  cout << "After insert the same second:" << endl;
  printSet(pSet);

  //pSet.unique();
  //cout << "After unique the set:" << endl;
  //printSet(pSet);

  cout << "do we have ("
    << tmp.x << ", " << tmp.y << ", " << tmp.z
    << ") in set?: " << pSet.count(newTmp) << endl;
  cout << "traverse after erasing 2nd itr's value:" << endl;
  pSet.erase(newTmp);
  printSet(pSet);
}
