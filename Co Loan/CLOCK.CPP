#include <iostream>
#include <fstream>

using namespace std;

void _1s(int &h, int &p, int &s) {
	s++;
	if(s > 59) {
		s = 0;
		p++;
	}
	if(p > 59) {
		p = 0;
		h++;
	}
	if(h > 23) {
		h = 0;
	}
}

int main() {
	int h, p, s;
	ifstream in;
	in.open("CLOCK.INP");
	in >> h >> p >> s;
	in.close();

	_1s(h, p, s);
	ofstream out;
	out.open("CLOCK.OUT");
	out << h << " " << p << " " << s;
	out.close();
}