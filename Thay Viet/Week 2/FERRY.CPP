/*
 * Trường hợp sai: a[i] > a[0..i-1] + t*2
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n, t, m, tg, lst, num;
	
	ifstream in;
	in.open("FERRY.INP");
	cin >> n >> t >> m;
	int a[m];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	in.close();
	
	num = m / n;
		
	tg = lst = a[m-1];

	int i = m - n - 1;
	for(; i > 0; i -= n) {
		if(a[i] + t * 2 > lst) 
			tg += a[i] + t * 2 - lst;
		lst = a[i];
	}
	
	if(i >= 0) {
		num++;
		if(a[i] + t * 2 > lst) 
			tg += a[i] + t * 2 - lst;
	}
	
	ofstream out;
	out.open("FERRY.OUT");
	cout << tg + t << " " << num;
	out.close();
}