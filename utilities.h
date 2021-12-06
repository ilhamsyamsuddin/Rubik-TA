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
  cout<<hex;
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

string S_box[16][16] = {
  {"63","7c","77","7b","f2","6b","6f","c5","30","01","67","2b","fe","d7","ab","76"},
  {"ca","82","c9","7d","fa","59","47","f0","ad","d4","a2","af","9c","a4","72","c0"},
  {"b7","fd","93","26","36","3f","f7","cc","34","a5","e5","f1","71","d8","31","15"},
  {"04","c7","23","c3","18","96","05","9a","07","12","80","e2","eb","27","b2","75"},
  {"09","83","2c","1a","1b","6e","5a","a0","52","3b","d6","b3","29","e3","2f","84"},
  {"53","d1","00","ed","20","fc","b1","5b","6a","cb","be","39","4a","4c","58","cf"},
  {"d0","ef","aa","fb","43","4d","33","85","45","f9","02","7f","50","3c","9f","a8"},
  {"51","a3","40","8f","92","9d","38","f5","bc","b6","da","21","10","ff","f3","d2"},
  {"cd","0c","13","ec","5f","97","44","17","c4","a7","7e","3d","64","5d","19","73"},
  {"60","81","4f","dc","22","2a","90","88","46","ee","b8","14","de","5e","0b","db"},
  {"e0","32","3a","0a","49","06","24","5c","c2","d3","ac","62","91","95","e4","79"},
  {"e7","c8","37","6d","8d","d5","4e","a9","6c","56","f4","ea","65","7a","ae","08"},
  {"ba","78","25","2e","1c","a6","b4","c6","e8","dd","74","1f","4b","bd","8b","8a"},
  {"70","3e","b5","66","48","03","f6","0e","61","35","57","b9","86","c1","1d","9e"},
  {"e1","f8","98","11","69","d9","8e","94","9b","1e","87","e9","ce","55","28","df"},
  {"8c","a1","89","0d","bf","e6","42","68","41","99","2d","0f","b0","54","bb","16"}
};
