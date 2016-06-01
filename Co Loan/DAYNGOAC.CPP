#include <iostream>
#include <fstream>

bool brk[32];
int cd = 0, n, k, ngc = 0;

using namespace std;

void check() {
	int deep = 0, md = 0;
	for(int i = 0; i < n; i++) {
		if(brk[i]) {
			deep++;
			if(deep > md) md = deep;
		} else {
			deep--;
			if(deep < 0) return;
		}
	}
	if(md == k && !deep) ngc++;
}

void back(int i) {
	for(int j = 0; j < 2; j++) {
		brk[i] = j;
		if(j) cd++;
		else cd--;
		if(i == n-1) check();
		else if(cd >= 0 && cd <= k) back(i+1);
		brk[i] = 0;
		if(j) cd--;
		else cd++;
	}
}

int main() {
	ifstream in;
	in.open("DAYNGOAC.INP");
	in >> n >> k;
	in.close();
	back(0);
	
	ofstream out;
	out.open("DAYNGOAC.OUT");
	out << ngc;
	out.close();
}