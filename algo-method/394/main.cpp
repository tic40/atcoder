#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  vector<int> d(2020); // d[位置] = 番号
  map<int,int> mp; // { 番号, 位置 }
  REP(i,n) {
    int x; cin >> x;
    d[x] = i+1;
    mp[i+1] = x;
  }
  int m; cin >> m;
  REP(i,m) {
    int a; cin >> a;
    int pos = mp[a];
    if (pos < 2019 && !d[pos+1]) {
      d[pos+1] = a;
      d[pos] = 0;
      mp[a] = pos+1;
    }

  }
  REP(i,2020) if (d[i]) cout << i << endl;
  return 0;
}