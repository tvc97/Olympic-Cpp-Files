#include <iostream>
#include <map>

#define maxn (int) 1e5 + 1

using namespace std;

int a[maxn], kq[maxn][3], nkq;

int main() {
	
	freopen("CERAMIC.INP", "r", stdin);
	//freopen("CERAMIC.OUT", "w", stdout);
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	bool f;
	int cnta, cntb;
	map<int, int> t, ta, tb;
	
	for(int i = 1, li = n / 2; i <= li; i++) {
		if(n % i == 0) {
			cnta = cntb = 0;
			f = true;
			ta.clear(); tb.clear();
			for(int j = 0; j < n; j += i) {

				t.clear();
				for(int k = j, lk = j + i; k < lk; k++)
					t[a[k]]++;

				if(ta.empty()) {
					ta = t;
					cnta = 1;
				} else if(t == ta) {
					cnta++;
				} else if(tb.empty()) {
					tb = t;
					cntb = 1;
				} else if(t == tb) {
					cntb++;
				} else {
					f = false;
					break;
				}
			}

			if(cnta && cntb && f) {
				kq[nkq][0] = i;
				kq[nkq][1] = max(cnta, cntb);
				kq[nkq][2] = min(cnta, cntb);
				nkq++;
			}
		}
	}
	
	if(nkq) {
		cout << nkq << endl;
		for(int i = 0; i < nkq; i++)
			printf("%d %d %d\n", kq[i][0], kq[i][1], kq[i][2]);
	} else {
		cout << -1;
	}
}
