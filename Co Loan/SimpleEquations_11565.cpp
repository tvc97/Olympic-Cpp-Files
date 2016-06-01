#include <iostream>

using namespace std;

int main() {
	int n, a, b, c, x, y, z;
	cin >> n;
	bool brk;
	for(int i = 0; i < n; i++) {
		brk = false;
		cin >> a >> b >> c;
		for(int x = -22; x <= 22 && !brk; x++)
			for(int y = x+1; y <= 100 && !brk; y++) {
				z = a - x - y;
				if(z > y && z > x) {
					if(x*y*z == b && x*x+y*y+z*z == c) {
						cout << x << " " << y << " " << z << endl;
						brk = true;
					}
				}
			} 
		if(!brk) {
			cout << "No solution." << endl;
		}
	}
}