#include<stdio.h>
#include<iostream>
#include<string.h>
#include <unordered_map>
#include <map>
//#include "kubus.h"
#include "utilities.h"
using namespace std;


int main(){
  
  string message = "0123456789ABBA9876543210";
  string key = "AABBCDEF09182736CCDD";
  string pt = hex2bin(message);//96 bit plaintext
  string bit_key = hex2bin(key);
  cout<<bit_key<<endl;
  
  /*Mcube.printAllFaces();
  Key_cube.printAllFaces();
  Mcube.xorCube(Key_cube);
  Mcube.printAllFaces();*/
}
