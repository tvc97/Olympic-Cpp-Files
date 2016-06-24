#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream out("SOKHONGLAP.INP");
    out << "30000" << endl;
    for(int i = 0; i < 30000; i++)
        out << abs(rand() % 99999) << " ";
}