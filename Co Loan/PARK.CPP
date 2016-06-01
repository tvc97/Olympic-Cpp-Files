#include <iostream>
#include <fstream>

#define maxn 7990

using namespace std;

int sv[maxn], c[maxn], sn = 0;

int inArray(int a) {
	for(int i = 0; i < sn; i++)
		if(sv[i] == a) return i;
	return -1;
}

int main() {
	int n, t, ind, m = 0;

	ifstream in;
	in.open("PARK.INP");
	
	in >> n;
	
	for(int i = 0 ; i < n; i++) {
		in >> t;
		t %= 10000;
		ind = inArray(t);
		if(ind == -1) {
			sv[sn] = t;
			c[sn] = 1;
			sn++;
		} else {
			c[ind]++;
		}
	}
	in.close();
	
	for(int i = 0; i < sn; i++) {
		m += 100;
		if(c[i] > 5) m += (c[i] - 5);
	}
	
	ofstream out;
	out.open("PARK.OUT");
	out << m;
	out.close();

}