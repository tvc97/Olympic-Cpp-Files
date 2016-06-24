#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream out("LANGGIENG.INP");
    out << "1000" << endl;
    for(int i = 0; i < 1000000; i++) out << "1 ";
}