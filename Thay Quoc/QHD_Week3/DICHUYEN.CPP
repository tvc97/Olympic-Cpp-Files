#include <iostream>
#include <fstream>
#include <queue>
#define maxn 10001

using namespace std;

int m[maxn][maxn];

int d[][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int n;

struct p {
    int x, y, d;
    p(){
        d = 0;
    }
    p(int a, int b) {
        x = a;
        y = b;
        d = 0;
    }
    p(int a, int b, int c) {
        x = a;
        y = b;
        d = c;
    }
};

int find_path(int i, int j) {
    int x, y;
    queue<p> Q;
    p a;
    Q.push(p(i, j, 0));
    m[i][j] = 1;
    while(!Q.empty()) {
        a = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            x = a.x + d[i][0];
            y = a.y + d[i][1];
            if(x >= 0 && y >= 0 && x < n && y < n) {
                if(m[x][y] == 0) {
                    Q.push(p(x, y, a.d+1));
                    m[x][y] = a.d+1;
                    if(x == 0 || y == 0 || x == n-1 || y == n-1) {
                        return m[x][y];
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ifstream in("DICHUYEN.INP");
    ofstream out("DUCHUYEN.OUT");

    int x, y;
    in >> n;
    in >> y >> x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            in >> m[i][j];
            m[i][j] = !m[i][j];
        }
    
    out << find_path(x, y);
    
    in.close();
    out.close();
}