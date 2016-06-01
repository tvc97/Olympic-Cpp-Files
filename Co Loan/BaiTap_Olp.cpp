#include <iostream>
#include <algorithm>

using namespace std;

int c = 0;

bool check(int a, int b) {
	bool x[10];
	int so;

	for(int i = 0; i < 10; i++)
		x[i] = 0;

	if(a < 10000) x[0] = 1;
	if(b < 10000) x[0] = 1;

	while(a > 0) {
		so = a%10;
		if(x[so])
			return 0;
		x[so] = 1;
		a /= 10;
	}
	while(b > 0) {
		int so = b%10;
		if(x[so])
			return 0;
		x[so] = 1;
		b /= 10;
	}

	for(int i = 0; i < 10; i++)
		if(!x[i])
			return false;
	return true;
	
}

void tim(int n) {
	for(int i = 1234; i*n < 100000; i++)
		if(check(i, i*n)) {
			cout << i*n << "/" << i << endl;
			c++;
		}
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;
	tim(n);
	cout << c;
}