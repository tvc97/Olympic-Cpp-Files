#include <iostream>

#define MAXLEN 10

using namespace std;

string s;
int pl = 0;

void insert(int a) {
	s += to_string(a);
	int cl = s.length() - MAXLEN;
	if(cl > 0){
		s = s.substr(cl);
		pl += cl;
	}
}

int main() {
	int n, ind;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		insert(i);
		int ind = s.find(to_string(n));
		if(ind != -1) {
			cout << ind + pl + 1 << endl;
			break;
		}
	}
}