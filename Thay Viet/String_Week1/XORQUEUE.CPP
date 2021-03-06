#include <iostream>
#include <fstream>

#define maxn 200000

typedef long long ll;

using namespace std;

struct queue {
	ll x[maxn];
	int front, rear;

	queue() { front = rear = -1; }
	
	bool empty() {
		return front == -1;
	}

	void push(ll a) {
		if(front == -1) {
			front = rear = 0;
			x[front] = a;
		} else x[++rear] = a;
	}
	
	ll pop() { return x[front++]; }

	int dem(ll u, ll v) {
		int t = 0;
		for(int i = front; i <= rear; i++)
			if(x[i] >= u && x[i] <= v) t++;
		return t;
	}
};

void push(ll x, queue &a, queue &b) {
	a.push(x);
	if(b.empty()) b.push(x);
	else b.push(b.x[b.rear] ^ x);
}

void pop(queue &a, queue &b) {
	a.pop(); b.pop();
	b.x[b.front] = a.x[a.front];
	for(int i = b.front+1; i <= b.rear; i++)
		b.x[i] = b.x[i-1] ^ a.x[i];
}

int main() {
	int n, m;
	ll t, u, v;
	string s;
	queue a, b;
	
	ifstream in("XORQUEUE.INP");
	ofstream out("XORQUEUE.OUT");
	
	a.push(0);
	b.push(0);

	in >> n;
	for(int i = 0; i < n; i++) {
		in >> t;
		push(t, a, b);
	}
	
	in >> m;
	for(int i = 0; i < m; i++) {
		in >> s;
		if(s == "PUSH") {
			in >> t;
			push(t, a, b);
		} else if(s == "POP") {
			pop(a, b);
		} else if(s == "COUNT") {
			in >> u >> v;
			out << b.dem(u, v) << endl;
		}
	}
	
	in.close();
	out.close();
}