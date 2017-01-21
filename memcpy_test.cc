#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // in case you want to use e.g. memset

using namespace std;

class test{
  public:
    int array[10];

    test(){
      cout << "test constructor init:" << endl;
      memset(array, 0, sizeof(array));
      print();
    }

    void print(){
      int i = 0;
      for (i = 0; i < 10; i++){
        cout << array[i] << " ";
      }
      cout << endl;
    }

    void shift_int(int number){
      int tmp_array[10] = {10};
      memcpy(tmp_array, array, sizeof(array));

      memcpy((array + 1), tmp_array, (sizeof(array) - sizeof(int)));
      array[0] = number;
      cout << "after shifting int:" << endl;
      print();
    }
};

int main(int argc, char *argv[]){
  test tmp;
  int array[10] = {0};
  int i = 0;
  for (i = 0; i < 10; i++){
    array[i] = i;
  }

  memcpy(tmp.array, array, sizeof(array));
  cout << "value of class array after memcpy:" << endl;
  tmp.print();

  //memcpy((tmp.array + 1), array, (sizeof(array) - sizeof(int)));
  //tmp.array[0] = -1;
  //cout << "value of class array after specific memcpy:" << endl;
  //tmp.print();
  tmp.shift_int(-1);
  tmp.shift_int(-2);

  //int j = 0;
  //for (j = 10 - 1; j > 0; j--){
  //  array[j] = array[j-1];
  //}
  //int* tmp_array = array;
  //array = {0};
  //memcpy((array + 1), tmp_array, (sizeof(array) - sizeof(int)));
  //delete [] tmp_array;

  //array[0] = -1;
  //    for (i = 0; i < 10; i++){
  //      cout << array[i] << " ";
  //    }
  //    cout << endl;
}
