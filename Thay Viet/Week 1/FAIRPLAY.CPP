#include <iostream>
#include <fstream>
#include <algorithm>

#define maxn 100000

using namespace std;

int a[maxn], b[maxn], n;

int main() {
	ifstream in;
	in.open("FAIRPLAY.INP");
	
	in >> n;
	for(int i = 0; i < n; i++)
		in >> a[i];
	for(int i = 0; i < n; i++)
		in >> b[i];
	
	in.close();
	
	sort(a, a+n);
	sort(b, b+n);
	
	int diem = 0;
	int bpos = 0;
	for(int i = 0; i < n; i++) {
		while(a[i] > b[bpos]) bpos++;
		if(bpos >= n) break;
		diem++;
	}
	
	ofstream out;
	out.open("FAIRPLAY.OUT");
	out << diem;
	out.close();
}