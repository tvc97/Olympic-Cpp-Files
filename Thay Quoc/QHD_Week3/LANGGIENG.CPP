#include <iostream>
#include <fstream>
#include <queue>

#define maxn 1001
using namespace std;

bool m[maxn][maxn];

int d[][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int n;

struct p {
    int x, y;
    p(){}
    p(int a, int b) {
        x = a;
        y = b;
    }
};

int dem(int i, int j) {
    int c = 0, x, y;
    queue<p> Q;
    p a;
    Q.push(p(i, j));
    while(!Q.empty()) {
        a = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            x = a.x + d[i][0];
            y = a.y + d[i][1];

            if(x >= 0 && y >= 0 && x < n && y < n)
                if(m[x][y]) {
                    Q.push(p(x, y));
                    m[x][y] = 0;
                    c++;
                }
        }
    }
    return c;
}

int main() {
    ifstream in("LANGGIENG.INP");
    in >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            in >> m[i][j];
    
    int ma = 0, t;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(m[i][j]) {
                if((t = dem(i, j)) > ma) ma = t;
            }
    
    ofstream out("LANGGIENG.OUT");
    out << ma;

    in.close();
    out.close();

}