#include <iostream>
#include <fstream>
#define maxn 100000

using namespace std;

int n;
int a[maxn];

ofstream out("TRADING.OUT");

int calc() {
	int cost = 0, bor = 0;
	for(int i = 0; i < n; i++) {
		cost += abs(bor);
		bor += a[i];
	}
	return cost;
}

void docFile() {
	ifstream in("TRADING.INP");
	in >> n;
	while(n) {
		for(int i = 0; i < n; i++)
			in >> a[i];
		out << calc() << endl;
		in >> n;
	}
}

int main() {
	docFile();
	out.close();
}