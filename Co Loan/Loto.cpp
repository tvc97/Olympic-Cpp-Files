#include <iostream>
#include <algorithm>
#define maxn 13

using namespace std;

int so[maxn], x[maxn], n;

void out() {
	for(int i = 1; i <= 6; i++)
		cout << so[x[i]] << (i == 6 ? "" : " ");
	cout << endl;
}

void browse(int i) {
	for(int j = x[i-1]+1; j < n-6+i; j++) {
		x[i] = j;
		if(i == 6) out();
		else browse(i+1);
	}
}

int main() {
	cin >> n;
	while (n != 0) {
		for(int i = 0; i < n; i++) {
			cin >> so[i];
			x[i] = 0;
		}
		x[0] = -1;
		browse(1);
		cin >> n;
		if(n != 0)
			cout << endl;
	}
}
