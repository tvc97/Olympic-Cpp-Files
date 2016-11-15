#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int a[10001], tmp[10001];

int bin_search(int k, int l, int r) {
	int mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(a[mid] == k) break;
		if(a[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return mid;
}

int main() {
	
	ifstream in("MUSEQ.INP");
	ofstream out("MUSEQ.OUT");

	map<int, bool> mark;
	int tc, n, an, t;
	in >> tc;
	
	while(tc--) {
		in >> n;

		an = 0;
		mark.clear();
		for(int i = 0; i < n; i++) {
 			in >> t;
			tmp[i] = t;
			if(!mark[t]) {
				mark[t] = 1;
				a[an++] = t;
			}
		}

		sort(a, a + an);
		for(int i = 0; i < n; i++)
			out << bin_search(tmp[i], 0, an) + 1 << " ";
		out << endl;
	}
	
	in.close();
	out.close();
}