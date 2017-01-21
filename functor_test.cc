#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <string.h> // in case you want to use e.g. memset

using namespace std;

class functor{
  private:
    int x;

  public:
    functor(int _x){
      x = _x;
    }
    int operator()(int y){
      return x + y;
    }
};

class tester{
  public:
    typedef std::function<int(int)> add;
    void test(add&& _f){
      int y = 5;
      cout << _f(5) << endl;
    }
};

int main(int argc, char *argv[]){
  tester tester1;
  functor functorInstance = functor(10);
  cout << "Result of direct passing: ";
  tester1.test(functor(5));
  cout << "Result of instantiated passing: ";
  tester1.test(functorInstance);
  //cout << "Result of instantiated * pointer passing: ";
  //tester1.test(*functorInstance);
}


