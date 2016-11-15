#include <string.h>
#include <iostream>

#define maxn (int) 1e6 + 10

using namespace std;

char A[maxn];
int P[maxn];

void KMPTable(char *A) {
	int i, j;
	P[0] = -1, i = 1, j = -1;
	while(A[i]) {
		while(j >= 0 && A[j+1] != A[i])
			j = P[j];
		if(A[j+1] == A[i])
			j++;
		P[i++] = j;
	}
}

int main() {
	
	freopen("PURE.INP", "r", stdin);
//	freopen("PURE.OUT", "w", stdout);
	
	int m; cin >> m;
	cin >> A;
	int l = strlen(A);
	
	KMPTable(A);
	
	int i = l - 1;
	while(i && P[i - 1] == P[i] - 1) i--;
	
	if(i + 1 <= m) {
		A[i + 1] = '\0';
		cout << A;
	} else {
		cout << "NO";
	}
}