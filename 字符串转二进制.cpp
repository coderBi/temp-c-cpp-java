#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

string getBinary(char c){
	string toReturn = "";
	while(c != 0){
		int bit = c % 2;
		toReturn = bit == 1 ? "1" + toReturn : "0" + toReturn;
		c /= 2;
	}
	while(toReturn.length() < 8){
		toReturn = "0" + toReturn;
	}
	return toReturn;
}

int main(int argc, char ** args){
	string s1 = "s1....", s2 = "s2...";
	string v = s1 + s2;
	fstream f("text.dat", ios::out | ios:: binary);
	string toWrite = "";
	for(int i = 0; i < v.length(); ++i){
		toWrite += getBinary(v[i]);
	}
	if(f == NULL){
		cerr << "打开出错" << endl;
		return 0;
	}
	f.write(toWrite.c_str(), toWrite.length());
	return 0;
}