#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

// Cach 1
/*
bool check(string c) {
	stack<char> ck;
	int l = c.length();
	for(int i = 0; i < l; i++) {
		if(c[i] == '(' || c[i] == '[')
			ck.push(c[i]);
		else {
			if(ck.empty()) return false;
			if((ck.top() == '(' && c[i] == ')') || (ck.top() == '[' && c[i] == ']')) {
				ck.pop();
			} else {
				return false;
			}
		}
	}
	return ck.empty();
}
*/
// Cach 2

bool ck(string c) {
	int cv = 0, ct = 0;
	string sv;
	int l = c.length();
	for(int i = 0; i < l; i++) {
		if(c[i] == '[') {
			sv += '[';
			cv++;
		} else if(c[i] == '(') {
			sv += '(';
			ct++;
		} else if(c[i] == ')') {
			if(sv[sv.length() - 1] != '(')
				return false;
			if(ct < 1)
				return false;
			sv = sv.substr(0, sv.length() - 1);
			ct--;
		} else if(c[i] == ']') {
			if(sv[sv.length() - 1] != '[')
				return false;
			if(cv < 1)
				return false;
			sv = sv.substr(0, sv.length() - 1);
			cv--;
		}
	}
	if(cv || ct) return false;
	return true;
}

int main() {
	int n;
	string str;
	cin >> n;
	getline(cin, str);
	for(int i = 0; i < n; i++) {
		getline(str);
		if(ck(cin, str)) 
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}