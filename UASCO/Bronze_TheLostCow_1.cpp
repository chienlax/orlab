#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("lostcow.in");
    ofstream cout("lostcow.out");
    int x, y;
    cin >> x >> y;
    int m = 0;
    while (x != y && x < y)
    {  
            static int i = 0;
            m += x;
            x += pow(-2, i);
            i++;
    }


    cout << m << endl;
    return 0;
}
//1 + 3 + 5 = 9