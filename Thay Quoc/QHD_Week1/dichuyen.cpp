#include <iostream>
#include <fstream>
#define maxn 1001

using namespace std;

int a[maxn][maxn], l[maxn][maxn], sv[maxn];
int m, n, sn = 0, mc;

int max(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

void readFile() {
	ifstream in("dichuyen.inp");
	in >> m >> n;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			in >> a[i][j];
	in.close();
}

void createGraph() {
	for(int i = 1; i <= n; i++) l[1][i] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			l[i][j] = max(l[i-1][j], l[i-1][j-1], l[i-1][j+1]) + a[i][j];
}

void findMaxPath() {
	int _m = 1, j = m;

	for(int i = 2; i <= n; i++)
		if(l[m][i] > l[m][_m]) _m = i;
	sv[sn++] = _m;
	mc = l[m][_m];
	
	while(j > 1) {
		for(int i = _m - 1; i <= m + 1; i++)
			if(l[j-1][i] == l[j][_m] - a[j][_m]) {
				sv[sn++] = i;
				_m = i;
				j--;
				break;
			}
	}
}

void out() {
	cout << "max: " << mc << endl;
	cout << "path: ";
	for(int i = sn-1; i >= 0; i--)
		cout << sv[i] << " ";
	cout << endl;
	cout << "cpath: ";
	for(int i = sn-1; i >= 0; i--)
		cout << a[sn-i][sv[i]] << " ";
}

int main() {
	readFile();
	createGraph();
	findMaxPath();
	out();
}