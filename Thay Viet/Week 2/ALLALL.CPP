#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool isSub(string a, string b) {
	int la = a.length(), lb = b.length();

	if(la > lb) return 0;

	int j = 0;
	for(int i = 0; i < lb; i++)
		if(b[i] == a[j])
			if(++j >= la) return 1;

	return 0;
}

int main() {
	ifstream in;
	in.open("ALLALL.INP");
	ofstream out;
	out.open("ALLALL.OUT");

	string a, b;
	while(!in.eof()) {
		in >> a >> b;
		out << (isSub(a, b) ? "Yes" : "No") << endl;
	}

	in.close();
	out.close();
}