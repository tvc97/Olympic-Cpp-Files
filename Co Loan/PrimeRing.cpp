#include <iostream>
#include <math.h>
#define maxn 17

using namespace std;

int x[maxn], n, co = 0;
bool a[maxn];
bool nt[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};

void out() {
	if(nt[x[n-1]+1]) {
		for(int i = 0; i < n; i++)
			cout << x[i] << (i == n - 1 ? "" : " ");
		cout << endl;
	}
}

void back(int i) {
	if(i == n)
		out();
	else
	for(int j = 2; j <= n; j++) {
		if(!a[j] && nt[j + x[i-1]]){
			a[j] = 1;
			x[i] = j;
			back(i+1);
			a[j] = 0;
		}
	}
}

int main() {
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			a[i] = 0;
		a[0] = 1;
		x[0] = 1;
		if(co > 0)
			cout << endl;
		cout << "Case " << ++co << ":" << endl;
		back(1);
	}
}