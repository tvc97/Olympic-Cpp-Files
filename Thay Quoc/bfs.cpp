#include <iostream>
#include <queue>
#include <fstream>

#define maxn 1000

int datham[maxn];
int matrix[maxn][maxn];
int n;

using namespace std;

void readFile() {
	ifstream in("matrix.inp");
	in >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			in >> matrix[i][j];
}

void tham(int a) {
	cout << a + 1 << " ";
}

void bfs(int s) {
	datham[s] = 1;
	queue<int> Q;
	Q.push(s);
	tham(s);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i = 0; i < n; i++)
			if(matrix[u][i] && !datham[i]) {
				tham(i);
				datham[i] = 1;
				Q.push(i);
			}
		datham[u] = 1;
	}
}

int main() {
	readFile();
	
	for(int i = 0; i < n; i++)
		if(!datham[i]) bfs(i);
}