#include <iostream>
#include <fstream>

typedef long long ll;
using namespace std;

bool a[30001];

int main() {
	int n;
	ll tmp;
	
	ifstream in;
	in.open("SN.INP");
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> tmp;
		if(tmp < 30001)
			a[tmp] = true;
	}
	in.close();
	
	int min = -1;
	for(int i = 0; i < 30001; i++) {
		if(!a[i]) {
			min = i;
			break;
		}
	}

	ofstream out;
	out.open("SN.OUT");
	out << min;
	out.close();

}