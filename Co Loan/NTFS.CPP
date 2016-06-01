#include <iostream>
#include <fstream>

using namespace std;

int ntfs(int n) {
	int kb = 0;
	for(;n > 0; n -= 4096)
		kb += 4;
	return kb;
}

int main() {
	int n;
	ifstream in;
	in.open("NTFS.INP");
	in >> n;
	in.close();

	ofstream out;
	out.open("NTFS.OUT");
	out << ntfs(n);
	out.close();
}