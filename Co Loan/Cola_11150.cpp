#include <iostream>

using namespace std;

struct bot {
	int num, empty;
};

bot bottle(int a) {
	int t = a;
	int empty_bot = a;
	int num_bot;
	while(empty_bot >= 3) {
		num_bot = empty_bot / 3;
		empty_bot -= num_bot * 3;
		empty_bot += num_bot;
		t += num_bot;
	}
	bot rs = {t, empty_bot};
	return rs;
}

void show(bot b) {
	cout << b.num << " " << b.empty << endl;
}

int main() {
	int n, m = 0;
	while(cin >> n) {
		bot b = bottle(n);
		m = b.num;

		for(int i = 1; i <= 3; i++) {
			b = bottle(n + i);
			if(b.empty >= i) {
				if(b.num - i > m) {
					m = b.num - i;
				}
			}
		}
		
		cout << m << endl;
	}
}