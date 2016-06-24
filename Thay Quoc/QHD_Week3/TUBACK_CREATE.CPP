#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

string rand_string(int length) {
	int l = a.length();
	string rs;
	for(int i = 0; i < length; i++) {
		rs += a[abs(rand() % l)];
	}
	return rs;
}

int main() {
	
	int n;
	
	ofstream out("TUBACK.INP");

	srand(time(NULL));
	n = abs(rand() % 99);
	out << n << endl;
	while(n--) {
		out << rand_string(abs(rand() % 999)) << " ";
	}
	
}
