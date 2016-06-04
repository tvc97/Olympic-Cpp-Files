#include <iostream>
#include <fstream>
#include <algorithm>

#define maxn 1000000

using namespace std;

int a[maxn], n;

void readFile() {
	ifstream in("HIGHWAY.INP");
	in >> n;
	for(int i = 0; i < n; i++)
		in >> a[i];
	in.close();
}

int doLech() {
	sort(a, a+n);
	int _min = INT_MAX, lech;
	for(int i = 0; i < n - 1; i++) {
		lech = a[i+1] - a[i];
		if(lech < _min)
			_min = lech;
	}
	return _min;
}

int main() {
	readFile();
	
	ofstream out("HIGHWAY.OUT");
	out << doLech();
	out.close();
}