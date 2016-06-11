#include <iostream>
#include <fstream>
#define maxn 1001

using namespace std;

int a[maxn], b[maxn], sv[maxn], an, bn, sn = 0;
int graph[maxn][maxn], l[maxn][maxn];

void readFile() {
	ifstream in("xcc.inp");
	in >> an >> bn;
	for(int i = 1; i <= an; i++)
		in >> a[i];
	for(int i = 1; i <= bn; i++)
		in >> b[i];
	in.close();
}

void createGraph() {
	for(int i = 1; i <= an; i++)
		for(int j = 1; j <= bn; j++)
			if(a[i] == b[j])
				graph[i][j] = graph[i-1][j-1] + 1;
			else
				graph[i][j] = max(graph[i-1][j], graph[i][j-1]);
}

void findMaxPath() {
	int i = an, j = bn, m = graph[i][j];
		
	while(i > 0 && j > 0) {
		while(graph[i][j] == graph[i-1][j]) i--;
		while(graph[i][j] == graph[i][j-1]) j--;
		sv[sn++] = a[i];
		i--;
		j--;
	}
}

void out() {
	for(int i = sn-1; i >= 0; i--)
		cout << sv[i] << " ";
}

int main() {
	readFile();
	createGraph();
	findMaxPath();
	out();
}