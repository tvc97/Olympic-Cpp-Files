#include <iostream>
using namespace std;

char c[4][4];
char na[] = "abcd";
int cou = 0;

void out() {
    cou++;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool check(int k, int l, char a) {
    for(int i = 0; i < 4; i++) {
        if(c[k][i] == a)
            return 0;
        if(c[i][l] == a)
            return 0;
    }
    return 1;
}

void back(int i, int j) {
    for(int k = 0; k < 4; k++) {
        if(check(i, j, na[k])) {
            c[i][j] = na[k];
            if(i == 3 && j == 3) out();
            else
                if(i < 3 && j == 3)
                    back(i+1, 0);
                else
                    back(i, j+1);
            c[i][j] = 0;
        }
    }
}

int main() {
    back(0, 0);
    cout << cou;
}