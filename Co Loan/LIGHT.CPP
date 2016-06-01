#include <iostream>
#include <fstream>

bool light[10][10];

using namespace std;

void change(int i, int j, int m, int n) {
	for(int k = 0; k < m; k++)
		light[i][k] = !light[i][k];
	for(int k = 0; k < n; k++)
		light[k][j] = !light[k][j];
}

int sum(int m, int n) {
	int t = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			t += light[i][j];
	return t;
}

int main() {
	
	int m, n, _max = INT_MIN, t;
	
	ifstream in;
	in.open("LIGHT.INP");
	
	in >> m >> n;
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			in >> light[i][j];
		}
	in.close();
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			change(i, j, m, n);
			t = sum(m, n);
			if(t > _max)
				_max = t;
			change(i, j, m, n);
		}

	ofstream out;
	out.open("LIGHT.OUT");
	out << _max;
}