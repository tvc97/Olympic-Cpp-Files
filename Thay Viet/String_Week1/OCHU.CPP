#include <iostream>
#include <fstream>
#define maxn 10000

using namespace std;

char rs[maxn][maxn];

ofstream out("OCHU.OUT");

struct diem {
	int x1, x2;
	diem(){}
	diem(int a, int b) { x1 = a; x2 = b; }
	bool possible() { return x1 != -1 && x2 != -1; }
};

diem find(string a, string b) {
	int m = a.length(), n = b.length();
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(a[i] == b[j])
				return diem(i, j);
	return diem(-1, -1);
}

void fill_space(int m, int n) {
	bool fill;
	for(int i = 0; i < m; i++) {
		fill = false;
		for(int j = n-1; j >= 0; j--) {
			if(rs[i][j]) fill = true;
			else if(fill) rs[i][j] = ' ';
		}
	}
}

void print_rs(int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			if(rs[i][j]) out << rs[i][j];
			else break;
		out << endl;
	}
	out << endl;
}

void create(string a[]) {
	int l[4], m, n, mtop, mbtm;
	string s;
	diem p1, p2;
	
	p1 = find(a[0], a[1]);
	p2 = find(a[2], a[3]);
	
	if(!p1.possible() || !p2.possible())
		out << "Khong tao duoc o chu" << endl << endl;
	else {
		for(int i = 0; i < 4; i++) l[i] = a[i].length();

		s = a[0] + "   " + a[2];
		mtop = max(p1.x2, p2.x2);
		mbtm = max(l[1]-p1.x2, l[3]-p2.x2);
		m = mtop + mbtm;
		n = l[0] + l[2] + 3;
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				rs[i][j] = 0;
		
		for(int i = 0; i < n; i++) rs[mtop][i] = s[i];
		for(int i = 0; i < l[1]; i++) rs[mtop-p1.x2+i][p1.x1] = a[1][i];
		for(int i = 0; i < l[3]; i++) rs[mtop-p2.x2+i][l[0]+3+p2.x1] = a[3][i];
		
		fill_space(m, n);
		print_rs(m, n);
	}
}

int main() {

	ifstream in("OCHU.INP");
	string a[4];

	while(true) {
		in >> a[0];
		if(a[0] == "#") break;
		in >> a[1] >> a[2] >> a[3];
		create(a);
	}

	in.close();
	out.close();

}