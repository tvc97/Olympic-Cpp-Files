#include <iostream>
#include <fstream>

#define maxn 1001

using namespace std;

struct canh {
	int u, v, w;
};

int graph[maxn][maxn];
int cg[maxn][maxn];
int id[maxn*maxn];
int n, m, sn = 0, cnt = 0, cost = 0;
canh c[maxn], sv[maxn];

bool cmpr(canh a, canh b) { return a.w < b.w; }

void readFile() {
	ifstream in("matrix.inp");
	in >> n >> m;
	for(int i = 1; i <= m; i++) {
		in >> c[i].u >> c[i].v >> c[i].w;
		graph[c[i].u][c[i].v] = c[i].w;
		graph[c[i].v][c[i].u] = c[i].w;
	}
	in.close();
}

void writeFile() {
	ofstream out("kruskal.out");
	out << cost << endl;
	for(int i = 0; i < sn; i++) {
		out << sv[i].u << " " << sv[i].v << " " << sv[i].w << endl;
	}
	out.close();
}

void dfs(int u) {
	id[u] = cnt;
	for(int i = 1; i <= n; i++)
		if(id[i] == 0 && cg[u][i])
			dfs(i);
}

void update() {
	for(int i = 1; i <= n; i++) id[i] = 0;
	for(int i = 1; i <= n; i++)
		if(id[i] == 0) {
			cnt++;
			dfs(i);
		}
}

void kruskal() {
	sort(c+1, c+m+1, cmpr);
	for(int i = 1; i <= m; i++) {
		update();
		if(id[c[i].u] != id[c[i].v]) {
			sv[sn] = c[i];
			cg[c[i].u][c[i].v] = c[i].w;
			cg[c[i].v][c[i].u] = c[i].w;
			sn++; cost += c[i].w;
			if(sn == n-1) break;
		}
	}
}

int main() {
	readFile();
	kruskal();
	writeFile();
}