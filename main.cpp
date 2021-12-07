#include<stdio.h>
#include<iostream>
#include<string.h>
#include <unordered_map>
#include<vector>
#include <map>
//#include "kubus.h"
#include "utilities.h"
using namespace std;


int main(){
  
  string message = "0D901B8FF4EE3A118FD61297E8BAE6DFF15F63C571D7EC7B3B861C";//54x4 = 216 bit
  string try_key = "52A0F468C58D08C90D9B8AFEF7B5308C7A2B4587D48B266AAA9EE6";//54* 4 = 216 bit
  string ans = "";
  for(int a = 0;a<54;a++){
    ans.push_back(xor_hex(message[a],try_key[a]));
  }
  cout<<ans<<endl;
  //char bit = xor_hex('A','F');
  //cout<<bit<<"yes"<<endl;
  Cube box;
  box.fillCube(ans);
  //box.printAllFaces();
  //char a = box.getCell(0,0,2);
  //cout<<a<<endl;
  //box.rotateFace90(0);
  string text = box.getContent();
  cout<<text<<endl;
  box.scramble(message);
  text = box.getContent();
  cout<<text<<endl;
  cout<<S_box[0][0]<<endl;
  /*Mcube.printAllFaces();
  Key_cube.printAllFaces();
  Mcube.xorCube(Key_cube);
  Mcube.printAllFaces();*/
}
