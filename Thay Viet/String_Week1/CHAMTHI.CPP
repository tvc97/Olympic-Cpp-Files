#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n;
	string a, b;

	ifstream in("CHAMTHI.INP");
	ofstream out("CHAMTHI.OUT");
	in >> n; in.ignore();
	
	for(int i = 0; i < n; i++) {
		getline(in, a);
		getline(in, b);

		if((int)a.find(" ") != -1) out << "Loi Dinh dang" << endl;
		else out << (a != b ? "Tra loi Sai" : "Dung") << endl;
	}
	
	in.close();
	out.close();
}