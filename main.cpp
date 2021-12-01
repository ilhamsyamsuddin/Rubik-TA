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
  string key = "7416D123471D5030AA649817EE091FE8";
  string pt = hex2bin(message);//96 bit plaintext
  string bit_key = hex2bin("F");//128 bit key
  string face_key = hex2bin("A");
    string ans = "";
  for(short i =0; i<4;i++){
    ans+= "1";
  }
  string bit = xor_hex("A","F");
  cout<<bit<<endl;
  
  /*Mcube.printAllFaces();
  Key_cube.printAllFaces();
  Mcube.xorCube(Key_cube);
  Mcube.printAllFaces();*/
}
