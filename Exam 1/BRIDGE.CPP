#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#define maxn 1001

using namespace std;

int a[maxn], n;
stringstream ss;

void p1(int a) { ss << a << endl; }
void p2(int a, int b) { ss << a << " " << b << endl; }

int main() {
	ifstream in("BRIDGE.INP");
	ofstream out("BRIDGE.OUT");
	
	in >> n;
	for(int i = 1; i <= n; i++) in >> a[i];
	sort(a+1, a+n+1);
	
	int cost = 0, c = n, c1, c2;
	while (c >= 4) {
		c1 = a[2] + a[1] + a[c] + a[2];
		c2 = a[c] + a[1] + a[c-1] + a[1];
		if (c1 < c2) {
			cost += c1;
			p2(a[1], a[2]); p1(a[1]);
			p2(a[c-1], a[c]); p1(a[2]);
		} else {
			cost += c2;
			p2(a[1], a[c]); p1(a[1]);
			p2(a[1], a[c-1]); p1(a[1]);
		}
		c -= 2;
	}
	
	if (c == 3) {
		cost += a[2] + a[1] + a[3];
		p2(a[1], a[2]); p1(a[1]);
		p2(a[1], a[3]);
	} else if (c == 2) {
		cost += a[2];
		p2(a[1], a[2]);
	} else {
		cost += a[1];
		p1(a[1]);
	}
	
	out << cost << endl << ss.str();
	
	in.close();
	out.close();
}