#include <iostream>
#include <string.h>

#define maxl 1001
#define maxn 101
#define maxs 40001

using namespace std;

struct node {
	int ind, min, type;
	node *left, *right, *ansc;
	int f[20];
};

const int oo = (int) 1e9;

typedef node *tree;
char pro[maxn][maxl];
char poli[maxs];

char sam[20] = {'A', 'R', 'N', 'D', 'C', 'Q', 'E', 'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V'};

void calc(tree a, int k) {
	if(a -> left -> type == 0) calc(a -> left, k);
	if(a -> right -> type == 0) calc(a -> right, k);
	if(a -> left -> type == a -> right -> type && a -> left -> type == 1) {
		int mi = oo, cnt;
		for(int i = 0; i < 20; i++) {
			cnt = 0;
			if(pro[a -> left -> ind][k] != sam[i]) cnt++;
			if(pro[a -> right -> ind][k] != sam[i]) cnt++;
			a -> f[i] = cnt;
			if(cnt < mi) mi = cnt;
		}
		a -> min = mi;
	}
	if(a -> left -> type == a -> right -> type && a -> left -> type == 0) {
		int mi = oo;
		for(int i = 0; i < 20; i++) {
			a -> f[i] = min(a -> left -> f[i], a -> left -> min + 1)
						+ min(a -> right -> f[i], a -> right -> min + 1);
			if(a -> f[i] < mi) mi = a -> f[i];
		}
		a -> min = mi;
	}
	if(a -> left -> type != a -> right -> type) {
		if(a -> left -> type == 0) {
			int mi = oo;
			for(int i = 0; i < 20; i++) {
				a -> f[i] = min(a -> left -> f[i], a -> left -> min + 1)
							 + (pro[a -> right -> ind][k] != sam[i]);
				if(a -> f[i] < mi) mi = a -> f[i];
			}
			a -> min = mi;
		} else {
			int mi = oo;
			for(int i = 0; i < 20; i++) {
				a -> f[i] = min(a -> right -> f[i], a -> right -> min + 1)
							 + (pro[a -> left -> ind][k] != sam[i]);
				if(a -> f[i] < mi) mi = a -> f[i];
			}
			a -> min = mi;
		}
	}
	
}

int main() {
	
	freopen("EVOLUTION.INP", "r", stdin);
//	freopen("EVOLUTION.OUT", "W", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie();
	
	int n, k, l, side;
	cin >> n >> k;
	cin.ignore();
 	
	for(int i = 0; i < n; i++)
		cin >> pro[i];

	cin >> poli;
	l = strlen(poli);
	
	tree orig = new node;
	orig -> type = 0;
	node *cur = orig;
	cur -> left = cur -> right = NULL;
	for(int i = 1; i < l - 1; i++) {
		if(poli[i] == '(') {
			if(cur -> left == NULL) {
				cur -> left = new node;
				cur -> left -> ansc = cur;
				cur = cur -> left;
				cur -> left = cur -> right = NULL;
				cur -> type = 0;
			} else {
				cur -> right = new node;
				cur -> right -> ansc = cur;
				cur = cur -> right;
				cur -> left = cur -> right = NULL;
				cur -> type = 0;
			}
		} else if(poli[i] == ')') {
			cur = cur -> ansc;
		} else if(poli[i] == 'S') {
			int t = 0;
			while(poli[i + 1] >= '0' && poli[i + 1] <= '9') {
				i++;
				t = t * 10 + poli[i] - '0';
			}
			if(cur -> left ==  NULL) {
				cur -> left = new node;
				cur -> left -> ind = t - 1;
				cur -> left -> type = 1;
			} else {
				cur -> right = new node;
				cur -> right -> ind = t - 1;
				cur -> right -> type = 1;
			}
		}
	}
	
	int rs = 0;
	for(int i = 0; i < k; i++) {
		calc(orig, i);
		rs += orig -> min;
	}
	
//	show(orig, 0);
	
	cout << rs;
}
