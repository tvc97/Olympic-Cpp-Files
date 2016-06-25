#include <iostream>
#include <fstream>
#define maxn 1000

using namespace std;

int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int n, k;

void calcHorizontal() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) b[i][0] += a[i][j];

		for(int j = 1, l = n-k; j <= l; j++)
			b[i][j] = b[i][j-1] - a[i][j-1] + a[i][j+k-1];
	}
}

void calcVertical() {
	for(int j = 0, l = n-k; j <= l; j++) {
		for(int i = 0; i < k; i++) c[0][j] += b[i][j];
		
		for(int i = 1; i <= l; i++)
			c[i][j] = c[i-1][j] - b[i-1][j] + b[i+k-1][j];
	}
}

int findMax() {
	int m = 0;
	for(int i = 0, l = n-k; i <= l; i++)
		for(int j = 0; j <= l; j++)
			if(m < c[i][j]) m = c[i][j];
	return m;
}

int main() {
	ifstream in("BONUS.INP");
	ofstream out("BONUS.OUT");

	in >> n >> k;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> a[i][j];

	calcHorizontal();
	calcVertical();
	
	out << findMax();
	
	in.close();
	out.close();
	
	return 0;
}