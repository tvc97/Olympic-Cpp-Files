#include <iostream>
#define maxn 30

using namespace std;

int a[maxn], nt, dur, cl, n, md;
bool b[maxn], save[maxn];

void cpArr() {
	for(int i = 0; i < nt; i++)
		save[i] = b[i];
}

void out() {
	int dur = 0;
	for(int i = 0; i < nt; i++) {
		if(save[i]) {
			cout << a[i] << " ";
			dur += a[i];
		}
	}
	cout << "sum:" << dur << endl;
}

void calc() {
	cl = 0;
	for(int i = 0; i < nt; i++) {
		if(b[i])
			cl += a[i];
	}
	if(cl > md && cl <= dur) {
		md = cl;
		cpArr();
	}
}

void browse(int i) {
	for(int j = 0; j < 2; j++) {
		b[i] = j;
		if(i == nt-1)
			calc();
		else browse(i+1);
	}
}

int main() {
	while(cin >> dur >> nt) {
		for(int i = 0; i < nt; i++) {
			cin >> a[i];
			b[i] = save[i] = false;
		}
		cl = md = 0;
		browse(0);
		out();
	}
}