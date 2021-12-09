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
  //Key Generation
  vector<string>roundKeys;
  roundKeys.push_back(key);
  for(int a = 1;a<=10;a++){
    Cube keyBox;
    keyBox.fillCube(key);
    keyBox.scramble(roundKeys[a-1]);
    string roundKey = keyBox.getContent();
    roundKey = subBytes(roundKey);
    roundKeys.push_back(roundKey);
  }

  for(int a = 0;a<roundKeys.size();a++){
    cout<<a<<": "<<roundKeys[a]<<endl;
  }
  string text;
  text = addRoundKey(message,key);
  /*for(int a = 0;a<54;a++){
    text.push_back(xor_hex(message[a],key[a]));
  }*/
  cout<<"XOR: "<<text<<endl;
  text = subBytes(text);
  cout<<"S-box: "<<text<<endl;

  for(int a = 1;a<=10;a++){
    Cube box;
    box.fillCube(text);
    box.scramble(roundKeys[a-1]);
    text = box.getContent();
  }
  cout<<"scrambled: "<<text<<endl;

  for(int a = 10;a>=1;a--){
    Cube box;
    box.fillCube(text);
    box.solve(roundKeys[a-1]);
    text = box.getContent();
  }
  cout<<"solved: "<<text<<endl;
  /*box.scramble(message);
  box.rotateDown90();
  text = box.getContent();
  cout<<"scrambled: "<<text<<endl;
  //box.solve(message);
  box.rotateDown270();
  text = box.getContent();
  cout<<"Solved: "<<text<<endl;*/
}
