#include <iostream>
#include <fstream>

#define maxn 1001

using namespace std;

struct canh {
	int u, v, w;
};

int graph[maxn][maxn];
int cg[maxn][maxn];
int id[maxn], daxet[maxn], xetcanh[maxn*maxn];
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
	ofstream out("prim.out");
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

void prim() {
	daxet[1] = 1;
	c[0].w = INT_MAX;
	int cmin, u, v;
	while(sn != n-1) {
		update();
		cmin = 0;
		for(int i = 1; i <= n; i++)
			if(daxet[i]) for(int j = 1; j <= m; j++)
				if(!xetcanh[j] && (c[j].u == i || c[j].v == i))
					if(c[j].w < c[cmin].w && id[c[j].u] != id[c[j].v]) cmin = j;
		u = c[cmin].u; v = c[cmin].v;
		xetcanh[cmin] = 1;
		daxet[u] = daxet[v] = 1;
		cg[u][v] = cg[v][u] = c[cmin].w;
		sv[sn++] = c[cmin];
		cost += c[cmin].w;
	}
}

int main() {
	readFile();
	prim();
	writeFile();
}