#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int soTang(int a) {
	int t[10] = {0};
	while(a > 0) {
		t[a%10]++;
		a /= 10;
	}
	int rs = 0;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < t[i]; j++) {
			rs *= 10;
			rs += i;
		}
	return rs;
}

int soGiam(int a) {
	int t[10] = {0};
	while(a > 0) {
		t[a%10]++;
		a /= 10;
	}
	int rs = 0;
	for(int i = 9; i >= 0; i--)
		for(int j = 0; j < t[i]; j++) {
			rs *= 10;
			rs += i;
		}
	return rs;
}

int main() {
	int so, st, sg, dem, d;
	map<int,bool> m;

	ifstream in("CHUOISO.INP");
	ofstream out("CHUOISO.OUT");

	while(true) {
		in >> so;
		if(so == 0) break;

		dem = 0;
		m.clear();

		out << "So ban dau " << so << endl;
		while(true) {
			st = soTang(so);
			sg = soGiam(so);
			
			d = sg - st;
			out << sg << " - " << st << " = " << d << endl;
			
			dem++;
			
			if(m.find(d) != m.end()) {
				out << "Chieu dai chuoi " << dem << endl << endl;
				break;
			}
			
			so = d;
			m[d] = 1;
		}
	}
	
}