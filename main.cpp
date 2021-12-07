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
  string key = "52A0F468C58D08C90D9B8AFEF7B5308C7A2B4587D48B266AAA9EE6";//54* 4 = 216 bit
  string ans;
  ans = addRoundKey(message,key);
  /*for(int a = 0;a<54;a++){
    ans.push_back(xor_hex(message[a],key[a]));
  }*/
  cout<<"XOR: "<<ans<<endl;
  ans = subBytes(ans);
  cout<<ans<<endl;


  Cube box;
  box.fillCube(ans);


  string text = box.getContent();
  cout<<text<<endl;
  box.scramble(message);
  text = box.getContent();
  cout<<text<<endl;
  box.solve(message);
  text = box.getContent();
  cout<<text<<endl;
}
