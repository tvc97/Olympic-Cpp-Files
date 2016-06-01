#include <iostream>
#include <fstream>

using namespace std;

int S(int m, int n, int t) {
	int tien = 0, cur = 0;
	for(int i = 0; i < n; i++) {
		tien += t;
		cur++;
		if(cur == m) {
			cur = 0;
			i++;
		}
	}
	return tien;
}

int main() {
	int m, n, t;
	ifstream in;
	in.open("KM.INP");
	in >> m >> n >> t;
	in.close();

	ofstream out;
	out.open("KM.OUT");
	out << S(m, n, t);
	out.close();
}