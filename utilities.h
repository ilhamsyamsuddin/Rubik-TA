#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include "kubus.h"

using namespace std;

string hex2bin(string s)
{
	// hexadecimal to binary conversion
	unordered_map<char,string>mp;
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";
	string bin = "";
	for (int i = 0; i < s.size(); i++) {
		bin += mp[s[i]];
	}
	return bin;
}

string bin2hex(string s)
{
	// binary to hexadecimal conversion
	unordered_map<string, string> mp;
	mp["0000"] = "0";
	mp["0001"] = "1";
	mp["0010"] = "2";
	mp["0011"] = "3";
	mp["0100"] = "4";
	mp["0101"] = "5";
	mp["0110"] = "6";
	mp["0111"] = "7";
	mp["1000"] = "8";
	mp["1001"] = "9";
	mp["1010"] = "A";
	mp["1011"] = "B";
	mp["1100"] = "C";
	mp["1101"] = "D";
	mp["1110"] = "E";
	mp["1111"] = "F";
	string hex = "";
	for (int i = 0; i < s.length(); i += 4) {
		string ch = "";
		ch += s[i];
		ch += s[i + 1];
		ch += s[i + 2];
		ch += s[i + 3];
		hex += mp[ch];
	}
	return hex;
}

int hex2dec(char hex){
  unordered_map<char,int>mp;
	mp['0'] = 0;
	mp['1'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	mp['A'] = 10;
	mp['B'] = 11;
	mp['C'] = 12;
	mp['D'] = 13;
	mp['E'] = 14;
	mp['F'] = 15;
  return mp[hex];
}

char xor_bit(char bit1, char bit2){
  if(bit1 == bit2) return '0';
  return '1';
}

string xor_hex(string hex1, string hex2){
  string bin1 = hex2bin(hex1);
  string bin2 = hex2bin(hex2);
  string ans = "";
  for(short i =0; i<4;i++){
    ans+= xor_bit(bin1[i], bin2[i]);
  }
  cout<<hex
  return bin2hex(ans);
}
string permute(string k, int* arr, int n)
{
    string permuted = "";
    for (int i = 0; i < n; i++) {
        permuted += k[arr[i]];
    }
    return permuted;
}

string encrypt(string pt){
	string left = pt.substr(0, 48);
	string right = pt.substr(48, 48);

  int expand[54] = 
  { 0,1,2,3,4,5,6,7,7,
    8,9,10,11,12,13,14,15,15,
    16,17,18,19,20,21,22,23,23,
    24,25,26,27,28,29,30,31,31,
    32,33,34,35,36,37,38,39,39,
    40,41,42,43,44,45,46,47,47
  };

  string right_expanded = permute(right,expand,54);
    cout<<right<<"yes"<<endl;
  cout<<right_expanded<<endl;
  swap(left,right);
  Cube pt_box;
  pt_box.fillCube(right_expanded);
  //pt_box.printAllFaces();
  return bin2hex(left + right);
}

