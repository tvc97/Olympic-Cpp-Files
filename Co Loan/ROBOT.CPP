#include <iostream>
#include <fstream>

#define U 1
#define D 2
#define L 3
#define R 4

using namespace std;

struct td {
	int x, y;
};

void direction(int x1, int y1, int x2, int y2, int &d) {
	if(x2 > x1) d = R;
	if(x2 < x1) d = L;
	if(y2 > y1) d = U;
	if(y2 < y1) d = D;
}

int main() {
	ifstream in;
	in.open("ROBOT.INP");

	int n, c = 0, dir, ld;
	td pre, now;
	in >> n;
	in >> pre.x >> pre.y >> now.x >> now.y;
	direction(pre.x, pre.y, now.x, now.y, ld);
	for(int i = 0; i < n-2; i++) {
		in >> now.x >> now.y;
		direction(pre.x, pre.y, now.x, now.y, dir);
		if(ld == U && dir == R) c++;
		if(ld == D && dir == L) c++;
		if(ld == L && dir == U) c++;
		if(ld == R && dir == D) c++;
		ld = dir;
		pre = now;
	}
	in.close();

	ofstream out;
	out.open("ROBOT.OUT");
	out << c;
	out.close();
}