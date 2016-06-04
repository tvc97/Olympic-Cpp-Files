#include <iostream>
#include <fstream>
#define maxn 30000

int a[maxn], n, k;

using namespace std;

void readFile() {
	ifstream in("bai3.inp");
	in >> n >> k;
	for(int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
}

void findPair() {
	sort(a, a+n);

	ofstream out("bai3.out");
	
	for(int i = 0; i < n - 1; i++) {
		if(a[i] > k) break;
		if(binary_search(a+i, a+n, k-a[i])) {
			out << a[i] << " " << k - a[i];
			break;
		}
	}

	out.close();
}

int main() {
	readFile();
	findPair();
}