#include <iostream>
#include <fstream>
#define maxn 1000

using namespace std;

struct BAI {
	int a, b, c, d;
};
BAI bai[maxn];

int abs(int a) {
	return (a < 0 ? -a : a);
}

bool cmpr(BAI b1, BAI b2) {
	return (b1.a + b1.b) / 2.0 <= (b2.a + b2.b) / 2.0 && abs(b1.a - b1.b) <= abs(b2.a - b2.b);
}

int main() {
	ifstream in;
	in.open("SVOI.INP");
	
	int n, tex, cex, sn = 0;
	
	in >> n >> tex >> cex;
	
	for(int i = 0; i < n; i++) {
		in >> bai[sn].a >> bai[sn].b >> bai[sn].c >> bai[sn].d;
		sn++;
	}
	in.close();
	
	sort(bai, bai+sn, cmpr);
	
	int i = 0;
	while(bai[i].a <= tex && bai[i].b <= cex && i < n) {
		tex += bai[i].c;
		cex += bai[i].d;
		i++;
	}
	
	ofstream out;
	out.open("SVOI.OUT");
	out << i;
	out.close();
}