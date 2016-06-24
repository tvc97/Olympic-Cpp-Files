#include <iostream>
#include <fstream>
#define maxn 30000

using namespace std;

int a[maxn];

int main() {
    int n;
    ifstream in("SOKHONGLAP.INP");
    ofstream out("SOKHONGLAP.OUT");

    in >> n;

    for(int i = 0; i < n; i++) in >> a[i];
    
    int l, r, t = 0, m = 0;
    for(int i = 0; i < n; i++) {
        t = 0;
        l = i;
        r = i;
        while(--l >= 0 && a[l] != a[i]) t++;
        while(++r < n && a[r] != a[i]) t++;
        
        if(t > m) m = t;
    }
    
    out << m;
    
    in.close();
    out.close();
}