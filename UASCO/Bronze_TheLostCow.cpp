#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("lostcow.in");
    ofstream cout("lostcow.out");
    int x, y; cin >> x >> y;
    int ans = 0, by = 1, dir = 1;
    while (true){
        if ((dir == 1 && x <= y && y <= x + by)||(dir == -1 && x >= y && x - by <= y)){
            ans += abs(y-x);
            cout << ans << endl;
            break;
        }
        else {
            ans += by*2;
            by *= 2;
            dir *= -1;
        }
    }
}
//1 + 3 + 5 = 9
//1 + 2 + 4 = 7