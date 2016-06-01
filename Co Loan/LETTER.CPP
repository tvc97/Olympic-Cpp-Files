#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


string sDecode(string a, int k) {
	string st = a.substr(0, k);
	string ed = a.substr(k);
	reverse(st.begin(), st.end());
	reverse(ed.begin(), ed.end());
	return st + ed;
}

int main() {
	int k;
	string s;

	ifstream in;
	in.open("LETTER.INP");
	getline(in, s);
	in >> k;
	in.close();

	ofstream out;
	out.open("LETTER.OUT");
	out << sDecode(s, k);
	out.close();
}
