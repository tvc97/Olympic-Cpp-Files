#include <iostream>
#include <fstream>
#include <map>

#define maxn 1000

using namespace std;

int main() {
	map<string,int> sv;
	
	int n, l, fm;
	string s, m;

	ifstream in("MATKHAU.INP");
	in >> n >> s;
	in.close();
	
	l = s.length();

	fm = 0;
	for(int i = 0; i < l-n+1; i++) {
		string sub = s.substr(i, n);
		sv[sub]++;

		if(sv[sub] > fm) {
			fm = sv[sub];
			m = sub;
		}
	}
	
	ofstream out("MATKHAU.OUT");
	out << m;
	out.close();
}