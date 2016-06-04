#include <iostream>
#include <fstream>
#include <algorithm>

#define maxn 20000

using namespace std;

int a[maxn], n, nt;
ofstream out("SHOP.OUT");

void calc() {
	sort(a, a+n);
	int t = n, save = 0;
	while(t-3 >= 0) {
		t -= 3;
		save += a[t];
	}
	out << save << endl;
}

void readFile() {
	ifstream in("SHOP.INP");
	in >> nt;

	for(int i = 0; i < nt; i++) {
		in >> n;
		for(int j = 0; j < n; j++)
			in >> a[j];
		calc();
	}
	
	in.close();
}

int main() {
	readFile();
}