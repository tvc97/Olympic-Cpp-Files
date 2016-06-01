#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

bool mark['z'-'a'];

int charAppear(const char *c) {
	int _c = 0;
	for(int i = 0, j = strlen(c); i < j; i++)
		if(!mark[c[i]-'a']) {
			_c++;
			mark[c[i]-'a'] = true;
		}
	return _c;
}

int main() {
	string s;

	ifstream in;
	in.open("STRING2.INP");
	getline(in, s);
	in.close();
	
	ofstream out;
	out.open("STRING2.OUT");
	out << charAppear(s.c_str());
	out.close();
	
}