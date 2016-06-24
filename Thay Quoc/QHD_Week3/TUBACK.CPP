#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("TUBACK.INP");
    ofstream out("TUBACK.OUT");

    int n, m = 0;
    string s;

    in >> n;
    while(n--) {
        in >> s;
        if(s.length() > m)
            m = s.length();
    }

    out << m;

    in.close();
    out.close();
}