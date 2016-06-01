#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

#define maxs 10000

using namespace std;

ofstream out;

int c, s, num = 0;
int vp[maxs];
float tb, bl;

float tbc() {
	float t = 0;
	for(int i = 0; i < s; i++)
		t += vp[i];
	return t / c;
}

float abs(float a) {
	return (a < 0 ? -a : a);
}

void divide() {
	tb = tbc();
	int m = c * 2, cs = 0;
	sort(vp, vp+m);
	for(int i = 0; i < m/2; i++) {
		
		out << setw(2) << cs++ << ": ";
		if(m - i <= s)
			out << vp[i] << " ";
		out << vp[m-i-1] << endl;
		
		bl += abs(tb - (vp[i] + vp[m-i-1]));
	}
}

int main() {
	ifstream in;
	in.open("BALANCE.INP");
	out.open("BALANCE.OUT");

	while(!in.eof()) {

		in >> c >> s;
		for(int i = 0; i < s; i++)
			in >> vp[i];
			
		if(num != 0)
			out << endl << endl;
		
		out << "Set #" << ++num << endl;
		bl = 0;
		divide();
		out << "IMBALANCE = ";
		out.precision(5);
		out << fixed << bl;
	}
	
}