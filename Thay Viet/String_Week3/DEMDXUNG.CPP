#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	string s, sub;
	map<string, bool> m;
	int l, dem;

	ifstream in("DEMDXUNG.INP");
	ofstream out("DEMDXUNG.OUT");

	while(in >> s) {
		m.clear();
		l = s.length();
		for(int i = 1; i <= l; i++)
			for(int j = 0; j < l; j++) {
				sub = s.substr(j, i);
				if(sub == string(sub.rbegin(), sub.rend()))
					m[sub] = 1;
			}
		out << "The string '" << s << "' contains " << m.size() << " palindromes." << endl; 
	}
	
	in.close();
	out.close();
}