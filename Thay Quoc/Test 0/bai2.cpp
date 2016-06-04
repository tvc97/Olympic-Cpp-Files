#include <iostream>
#include <fstream>

#define maxn 10000
#define maxs 30000

using namespace std;

bool mrk[maxn+maxn];
int x[maxs], a[4], n;

void calc() {
	int t = 0;
	for(int i = 1; i <= 3; i++) {
		t += x[a[i]];
	}
	if(t/3.0 - t/3 == 0.0)
		mrk[10000+t/3] = true;
}

void tinh(int i) {
	for(int j = a[i-1]+1; j < n-3+i; j++) {
		a[i] = j;
		if(i == 3) calc();
		else tinh(i+1);
	}
}

int stbc() {
	int s = 0;
	for(int i = 0; i < n; i++)
		if(mrk[10000+x[i]]) {
			s++;
			mrk[10000+x[i]] = false;
		}
	return s;
}

int main() {
	ifstream in("bai2.inp");
	in >> n;
	for(int i = 0; i < n; i++)
		in >> x[i];
	in.close();

	a[0] = -1;
	tinh(1);
	
	ofstream out("bai2.out");
	out << stbc();
	out.close();
}