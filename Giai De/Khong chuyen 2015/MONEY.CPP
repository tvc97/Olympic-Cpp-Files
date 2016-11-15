#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned long long ull;

int main() {
	
	ifstream in("MONEY.INP");
	ofstream out("MONEY.OUT");
	
	ull t, n, s = 0, a, cnt = 0;
	
	in >> t >> n;
	for(int i = 0; i < n; i++) {
		in >> a;
		s += a;
		if(s >= t) {
			cnt++;
			s %= t;
		}
	}
	
	out << cnt;
	
	in.close();
	out.close();
}