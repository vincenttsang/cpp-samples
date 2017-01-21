#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main(int argc, char *argv[]){
  stack<int> test;
  int i = 0;
  for(i = 0; i < 10; i++){
    test.push(i);
  }
  cout << "stack pop:" << endl;
  while(!test.empty()){
    int temp = test.top();
    cout << temp << endl;
    test.pop();
  }
  return 0;
}
