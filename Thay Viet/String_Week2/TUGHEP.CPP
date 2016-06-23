#include <fstream>
#include <iostream>
#include <map>

using namespace std;

map<string,bool> m;
map<string,bool>::iterator it;

int n = 0;

int main() {
	string tmp;
	ifstream in("TUGHEP.INP");
	while(in >> tmp) {
		m[tmp] = 1;
	}
	in.close();
	
	ofstream out("TUGHEP.OUT");
	for(it = m.begin(); it != m.end(); it++) {
		tmp = it->first;
		for(int j = 1, l = tmp.length(); j < l; j++) {
			if(m.find(tmp.substr(0, j)) != m.end() && m.find(tmp.substr(j)) != m.end()) {
				out << tmp << endl;
				break;
			}
		}
	}
	out.close();
		
}
