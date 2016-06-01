#include <iostream>
#include <fstream>

#define maxd 100000

using namespace std;

struct doan {
	int l, r;
};

doan d[maxd], sv[maxd];

bool isCovered(int n, int ns) {
	return (sv[0].l <= 0 && sv[ns-1].r >= n);
}

bool cmpr(doan a, doan b) {
	if(a.l <= 0 && b.l <= 0) {
		return a.r > b.r;
	}
	if(a.l < b.l) return true;
	else if(a.l > b.l) return false;
	else {
		return a.r < b.r;
	}
}

int main() {
	int n, m, tl, tr, nd, cr, ns;

	ifstream in;
	ofstream out;

	in.open("COVERAGE.INP");
	out.open("COVERAGE.OUT");

	in >> n;

	for(int i = 0; i < n; i++) {
		nd = cr = ns = 0;
		in >> m;
		in >> tl >> tr;
		while(tl != 0 || tr != 0) {
			if(tr > 0) {
				d[nd].l = tl;
				d[nd].r = tr;
				nd++;
			}
			in >> tl >> tr;
		}
		
		sort(d, d+nd, cmpr);

		sv[ns++] = d[0];
		
		for(int i = 1; i < nd; i++) {
			if(isCovered(m, ns)) break;
			if(ns == 1) sv[ns++] = d[i];
			else if(d[i].l <= sv[ns-2].r && d[i].r > sv[ns-1].r)
				sv[ns-1] = d[i];
			else if(d[i].l <= sv[ns-1].r && d[i].r > sv[ns-1].r)
				sv[ns++] = d[i];
		}
		
		if(isCovered(m, ns)) {
			out << ns << endl;
			for(int i = 0; i < ns; i++)
				out << sv[i].l << " " << sv[i].r << endl;
			out << endl;
		} else {
			out << 0 << endl << endl;
		}
	}
	
	out.close();
}