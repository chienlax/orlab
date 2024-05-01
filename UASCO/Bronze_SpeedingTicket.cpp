#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("speeding.in");
    ofstream cout("speeding.out");
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> road;
    vector<pair<int, int>> bessie;

    for (int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        road.push_back({a, b});
    }

    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        bessie.push_back({a, b});
    }
    int i = 0, j = 0, ans = 0;
    while (bessie[bessie.size()-1].first != 0){
        int less = min(road[i].first, bessie[j].first);
        ans = max(ans, bessie[j].second - road[i].second);
        road[i].first -= less;
        bessie[j].first -= less;
        if (road[i].first == 0) i++;
        if (bessie[j].first == 0) j++;
    }
    cout << ans;
}