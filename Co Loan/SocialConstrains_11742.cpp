#include <iostream>
#include <algorithm>

using namespace std;

int pos(int a[], int n, int k) {
	for(int i = 0; i < n; i++)
		if(a[i] == k)
			return i;
	return -1;
}

int main() {
	
	int n, m, ta, tb;
	int a[] = {0,1,2,3,4,5,6,7};
	int b[20][3], sit;
	bool valid;
	
	cin >> n >> m;
	
	while(n || m) {
		
		for(int i = 0; i < m; i++)
			cin >> b[i][0] >> b[i][1] >> b[i][2];
			
		for(int i = 0; i < n; i++)
			a[i] = i;
			
		sit = 0;
		
		do {
			
			valid = true;

			for(int i = 0; i < m; i++) {
				ta = pos(a, n, b[i][0]);
				tb = pos(a, n, b[i][1]);
				
				if(b[i][2] > 0)
					if(abs(ta - tb) > b[i][2])
						valid = false;
				
				if(b[i][2] < 0)
					if(abs(ta - tb) < -b[i][2])
						valid = false;
			}
			
			if(valid) sit++;
			
		} while (next_permutation(a, a+n));
		
		cout << sit << endl;
		
		cin >> n >> m;

	}
	
}