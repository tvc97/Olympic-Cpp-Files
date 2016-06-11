#include <iostream>
#include <fstream>
#define maxn 1000

using namespace std;

string sv[maxn];
int sn = 0, dem[maxn];

int inArray(string a) {
	for(int i = 0; i < sn; i++)
		if(a == sv[i])
			return i;
	return -1;
}

int main() {
	int n, l;
	string s;

	ifstream in("MATKHAU.INP");
	in >> n >> s;
	in.close();
	
	l = s.length();
	
	for(int i = 0; i < l-n+1; i++) {
		string sub = s.substr(i, n);
		int ind = inArray(sub);
		if(ind != -1) dem[ind]++;
		else sv[sn++] = sub;
	}
	
	int m = 0;
	for(int i = 1; i < sn; i++)
		if(dem[i] > dem[m]) m = i;
		
	ofstream out("MATKHAU.OUT");
	out << sv[m];
	out.close();
}