#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

char encode(int c, int k) {
	c += k;
	if(c > 'z') c = c - 'z' + 'a' - 1;
	return c;
}

char key(string a, string b) {
	int k = 0;
	char c = a[0];
	while(c != b[0]) {
		k++;
		c++;
		if(c > 'z') c = 'a';
	}
	
	for(int i = 1, j = a.length(); i < j; i++)
		if(encode(a[i], k) != b[i])
			return 0;
	return 'a' + k;
}

int main() {
	int n;
	string s, w, tmp, rs;
	char c;
	
	ifstream in("BEKHOA.INP");
	ofstream out("BEKHOA.OUT");
	
	in >> n; in.ignore();
	while(n--) {
		rs = "";
		getline(in, s);
		stringstream si(s);
		in >> w; in.ignore();
		while(si >> tmp) {
			if(tmp.length() == w.length()) {
				if((c = key(w, tmp)) != 0)
					rs += c;
			}
		}
		sort(rs.begin(), rs.end());
		out << rs << endl;

	}
	
	in.close();
	out.close();
}