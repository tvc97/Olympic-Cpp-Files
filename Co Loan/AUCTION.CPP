#include <iostream>
#include <fstream>
#define maxn 100001

using namespace std;

bool nt[maxn];

bool dx(int a) {
	int b = 0, t = a;
	while(a > 0) {
		b = b*10 + (a%10);
		a /= 10;
	}
	return t == b;
}


int main() {
	int a, b, c = 0;

	ifstream in;
	in.open("AUCTION.INP");
	
	in >> a >> b;
	
	in.close();

	for(long i = 2; i < maxn; i++)
		if(!nt[i]) for(long j = i * i; j < maxn; j += i)
			nt[j] = 1;
			
	for(int i = a; i <= b; i++)
		if(!nt[i] && dx(i))
			c++;
			
	ofstream out;
	out.open("AUCTION.OUT");
	out << c;
	
	out.close();
}