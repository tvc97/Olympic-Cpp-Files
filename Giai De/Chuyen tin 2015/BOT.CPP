#include <iostream>
#define oo (int) 1e9 + 1

using namespace std;

typedef long long ll;

int main() {

	freopen("BOT.INP", "r", stdin);
//	freopen("BOT.OUT", "w", stdout);
	
	int n, t; cin >> n;
	int Start = 0, End, MaxStart, MaxEnd, MaxElement = -oo, MaxElementIndex;
	ll Max = -oo, Sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		if(t > MaxElement) {
			MaxElement = t;
			MaxElementIndex = i;
		}
		Sum += t;
		if(Sum < 0) {
			Start = i + 1;
			Sum = 0;
		} else if(Sum > Max) {
			Max = Sum;
			MaxStart = Start;
			MaxEnd = i;
		}
	}
	
	if(Max != -oo)
		cout << MaxStart << " " << MaxEnd << " " << Max;
	else
		cout << MaxElementIndex << " " << MaxElementIndex << " " << MaxElement;
}