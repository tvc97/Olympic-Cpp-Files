#include <iostream>
#include <fstream>
#define maxn 30000

int a[maxn], n;

using namespace std;

void readFile() {
	ifstream in("bai1.inp");
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
}

int findMax() {
	sort(a, a+n);
	int c1 = a[n-1]*a[n-2]*a[n-3];
	int c2 = a[n-1]*a[0]*a[1];
	return max(c1, c2);
}

int main() {
	readFile();
	
	ofstream out("bai1.out");
	out << findMax();
	out.close();
}