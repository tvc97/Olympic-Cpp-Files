#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	int n, k, c = 0;
	int a[10];
	
	ifstream in("PERMUTE.INP");
	ofstream out("PERMUTE.OUT");

	in >> n >> k;

	for(int i = 0; i < n; i++) a[i] = i+1;
	while(++c < k) next_permutation(a, a+n);
	
	for(int i = 0; i < n; i++)
		out << a[i] << " ";

	in.close();
	out.close();
}