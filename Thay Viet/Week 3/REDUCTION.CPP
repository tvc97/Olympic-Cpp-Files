#include <iostream>
#include <fstream>
#include <algorithm>

#define maxl 100

using namespace std;

struct comp {
	string name;
	int a, b;
};

struct calculated {
	string name;
	int price;
};

bool cmpr (calculated a, calculated b){
	return a.price < b.price;
}

comp x[maxl];
calculated save[maxl];
int m, n, cn, sn, cas = 0;

ofstream out("REDUCTION.OUT");

int price(int a, int b, int m, int n) {
	int nb = 0, pra = 0, prb = 0;
	while(m > n) {
		nb = m/2;
		if(nb >= n && a*m/2 > b) {
			prb += b;
			m /= 2;
		} else {
			pra += a;
			m--;
		}
	}
	return pra + prb;
}

void writeFile() {
	out << "Case " << ++cas << endl;
	for(int i = 0; i < sn; i++)
		out << save[i].name << " " << save[i].price << endl;
}

void calc() {
	for(int i = 0; i < sn; i++) {
		save[i].name = x[i].name;
		save[i].price = price(x[i].a, x[i].b, m, n);
	}
	sort(save, save+sn, cmpr);
	writeFile();
}

void readFile() {
	ifstream in("REDUCTION.INP");
	in >> cn;
	char c;
	while(cn--) {
		in >> m >> n >> sn;
		for(int j = 0; j < sn; j++) {
			x[j].name = "";
			in >> c;
			while(c != ':') {
				x[j].name += c;
				in >> c;
			}
			in >> x[j].a >> c >> x[j].b;
		}
		calc();
	}
}

int main() {
	readFile();
}