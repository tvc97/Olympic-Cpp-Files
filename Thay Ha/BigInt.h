#include <iostream>
#include <string.h>

using namespace std;

typedef string BigInt;

ostream& operator<<(ostream& os, const BigInt bi)
{
	for(int i = 0, j = bi.length(); i < j; i++)
		os << bi[i];
	return os;
}

void removeZero(BigInt &a) {
	while(a.at(0) == '0' && a.length() > 1) a = a.substr(1);
}

void addZeroBack(BigInt &a, int l) {
	while(l--)
		a += '0';
}

void balance(BigInt &a, BigInt &b) {
	int al = a.length();
	int bl = b.length();
	if(al < bl)
		for(int i = bl; i > al; i--)
			a = '0' + a;
	if(bl < al)
		for(int i = al; i > bl; i--)
			b = '0' + b;
}

bool operator<(BigInt a, BigInt b) {
	balance(a, b);
	return a.compare(b) < 0;
}

bool operator>(BigInt a, BigInt b) {
	balance(a, b);
	return a.compare(b) > 0;
}

bool operator==(BigInt a, BigInt b) {
	balance(a, b);
	return a.compare(b) == 0;
}

bool operator<=(BigInt a, BigInt b) {
	return a < b || a == b;
}

bool operator>=(BigInt a, BigInt b) {
	return !(a < b);
}

BigInt itob(int a) {
	if(a == 0) return "0";
	BigInt b;
	while(a > 0) {
		b = (char)((a%10)+'0') + b;
		a /= 10;
	}
	return b;
}

BigInt operator+(BigInt val, BigInt add) {
	int al = val.length();
	int bl = add.length();
	
	int nho = 0, kq;
	string rs;
	
	for(int i = al - 1, j = bl - 1; i >= -1 || j >= -1; i--, j--) {
		kq = 0;
		if(i >= 0) kq += val.at(i) - '0';
		if(j >= 0) kq += add.at(j) - '0';
		
		kq += nho;
		nho = kq/10;
		kq %= 10;
		rs = (char)(kq + '0') + rs;
	}
	
	removeZero(rs);
	return rs;
}

BigInt operator+(BigInt val, int add) {
	return val + itob(add);
}

BigInt operator-(BigInt val, BigInt sub) {
	int al = val.length();
	int bl = sub.length();
	
	int a, b, muon = 0, kq;
	string rs;
	
	for(int i = al - 1, j = bl - 1; i >= -1 || j >= -1; i--, j--) {
		a = 0, b = 0;

		if(i >= 0) a = val.at(i) - '0';
		if(j >= 0) b = sub.at(j) - '0';
		
		kq = a - muon - b;
		if(kq < 0) {
			kq += 10;
			muon = 1;
		} else {
			muon = 0;
		}

		rs = (char)(kq + '0') + rs;
	}
	
	removeZero(rs);
	return rs;
}

BigInt operator-(BigInt val, int sub) {
	return val - itob(sub);
}

BigInt operator*(BigInt val, BigInt mul) {
	int al = val.length();
	int bl = mul.length();
	
	if(val == "0" || mul == "0") return "0";
	
	string rs = "0", line;
	int a, b, kq, nho;
	
	for(int i = bl - 1; i >= 0; i--) {
		int b = mul.at(i) - '0';
		line = ""; kq = 0, nho = 0;
		for(int j = al - 1; j >= 0; j--) {
			int a = val.at(j) - '0';
			
			kq = a * b + nho;
			nho = kq / 10;
			kq %= 10;
			line = (char)(kq + '0') + line;
		}
		if(nho > 0)
			line = (char)(nho + '0') + line;
		addZeroBack(line, bl - i - 1);
		rs = (BigInt)rs + (BigInt)line;
	}
	removeZero(rs);
	return rs;
}

BigInt operator*(BigInt val, int mul) {
	return val * itob(mul);
}

BigInt operator/(BigInt a, BigInt b) {
	if(a < b) return "0";
	if(a == b) return "1";
	if(b == "1") return a;
	
	int bl = b.length();
	int al = a.length();
	
	string rs = "";
	string cur = "";
	int kq;

	for(int i = 0; i < al; i++) {
		cur += a.at(i);
		removeZero(cur);
		kq = 0;
		while(cur >= b) {
			kq++;
			cur = cur - b;
		}
		rs += (string)itob(kq);
	}
	
	removeZero(rs);
	return rs;
}

BigInt operator/(BigInt a, int b) {
	return a / itob(b);
}

BigInt operator%(BigInt a, BigInt b) {
	return a - b*(a/b);
}