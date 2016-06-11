#include <iostream>
#include <fstream>

#define maxn 20001

using namespace std;

int matrix[maxn][maxn];
bool daxet[maxn];
int path[maxn];
int n, pn, u, v, pc;

void readFile() {
	ifstream in("matrix.inp");
	in >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			in >> matrix[i][j];
	in.close();
}

void out() {
	cout << "path " << ++pc << ": ";
	for(int i = 1; i <= pn; i++)
		cout << path[i] << " ";
	cout << endl;
}

void dfs(int s) {
	for(int i = 1; i <= n; i++)
		if(matrix[s][i] && !daxet[i]) {
			daxet[i] = 1;
			path[++pn] = i;
			if(i == v) out();
			else dfs(i);
			pn--;
			daxet[i] = 0;
		}
}

int main() {
	readFile();

	cin >> u >> v;
	daxet[u] = 1;
	
	pn = 1;
	pc = 0;
	path[pn] = u;

	dfs(u);
}