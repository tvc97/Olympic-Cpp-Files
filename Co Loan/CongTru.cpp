#include <iostream>
#include <fstream>
#define maxn 1000

using namespace std;

long long a[maxn], k, tar, cur = 0, n = 0, c = 0;

void split() {
	int t = tar;
	while(t > 0) {
		a[n++] = t % 10;
		t /= 10;
	}
}

void back(int i) {
	int t;
	for(int j = -1; j < 2; j += 2) {
		t = a[i] * j;
		cur += t;
		if(i == n-1) {
			if(cur == k)
				c++;
		} else if(cur + 9 * (n-i) >= k)
			back(i+1);
		cur -= t;
	}
}

int main() {
	ifstream in;
	in.open("SO.INP");
	in >> k;
	in >> tar;
	split();
	in.close();
	
	back(0);

	ofstream out;
	out.open("SO.OUT");
	out << c;
	in.close();
}