#include <iostream>
#include <fstream>

#define maxn 50

using namespace std;

void lwr(string &s) {
	for(int i = 0, j = s.length(); i < j; i++)
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
}

int m, n;
string s[maxn];
int d[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ifstream in("BANGCHU.INP");
ofstream out("BANGCHU.OUT");

void find(string t) {
	int x, y, l = t.length();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < 8; k++) {
				x = i, y = j;
				for(int o = 0; o < l; o++) {
					if(t[o] != s[x][y]) break;
					if(o == l-1) {
						out << i+1 << " " << j+1 << endl;
						return;
					}
					x += d[k][0];
					y += d[k][1];
					if(x < 0 || y < 0 || x >= n || y >= m) break;
				}
			}
		}
	}
}

int main() {
	int x;
	string t;

	in >> n >> m;
	for(int i = 0; i < n; i++) {
		in >> s[i];
		lwr(s[i]);
	}
	
	in >> x;
	while(x--) {
		in >> t;
		lwr(t);
		find(t);
	}
	
	in.close();
	out.close();
}
