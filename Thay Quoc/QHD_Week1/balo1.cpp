#include <iostream>
#include <fstream>
#define maxn 1001

using namespace std;

int n, w, sn = 0;
int a[maxn];
int wa[maxn][maxn];
int sv[maxn];

void readFile() {
	ifstream in("balo1.inp");
	in >> n >> w;
	for(int i = 1; i <= n; i++)
		in >> a[i];
	in.close();
}

void out_matrix() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++)
			cout << wa[i][j] << "\t";
		cout << endl;
	}
}

void gen_matrix() {
	for(int i = 1; i <= w; i++)
		if(i >= a[1]) wa[1][i] = a[1];
		else wa[1][i] = 0;

	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= w; j++)
			if(j >= a[i])
				wa[i][j] = max(wa[i-1][j-a[i]] + a[i], wa[i-1][j]);
			else
				wa[i][j] = wa[i-1][j];
}

void compute() {
	int i = n, j = w, m = wa[i][j];
	
	while(i && j) {
		if(wa[i-1][j] == wa[i][j])
			i--;
		else {
			sv[sn++] = a[i];
			j -= a[i];
			i--;
		}
	}
}

void out() {
	for(int i = sn-1; i >= 0; i--)
		cout << sv[i] << " ";
	cout << endl;
}

int main() {
	readFile();
	gen_matrix();
	out_matrix();
	compute();
	out();
}