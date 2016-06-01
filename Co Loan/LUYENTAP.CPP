#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct bai {
	ll min, exp;
	bai(ll m, ll e) {
		min = m;
		exp = e;
	}
};

bool cmpr(bai *a, bai *b) { return a->min < b->min; }

int main() {
	int n, sb = 0;
	vector<bai*> v;
	ll cur_exp, t_min, t_exp;

	ifstream in;
	in.open("LUYENTAP.INP");
	in >> n >> cur_exp;
	for(int i = 0; i < n; i++) {
		in >> t_min >> t_exp;
		bai *const b = new bai(t_min, t_exp);
		v.push_back(b);
	}
	in.close();
	
	sort(v.begin(), v.end(), cmpr);
	
	while(cur_exp >= v[sb]->min) {
		cur_exp += v[sb]->exp;
		sb++;
		if(sb == n)
			break;
	}
	
	ofstream out;
	out.open("LUYENTAP.OUT");
	out << sb;
	out.close();
}
