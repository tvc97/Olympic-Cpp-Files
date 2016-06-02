/*
 * Trường hợp sai: a[i] > a[0..i-1] + t*2
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n, t, m, tg, lst, num, nt = 0;
	
	ifstream in;
	in.open("FERRY.INP");
	in >> n >> t >> m;
	int a[m], tim[m];
	for(int i = 0; i < m; i++)
		in >> a[i];
	in.close();
	
	num = m / n;
		
	tg = lst = a[m-1];

	int i = m - 1;
	for(; i > 0; i -= n) {
		tim[nt++] = a[i];
	}
	
	if(i >= 0) {
		num++;
		tim[nt++] = a[i];
	}
	
	for(int i = nt - 1; i > 0; i--) {
		if(tim[i] + t*2 > tim[i-1])
			tim[i-1] += tim[i] + t*2 - tim[i-1];
	}
	
	ofstream out;
	out.open("FERRY.OUT");
	out << tim[0] + t << " " << num;
	out.close();
}