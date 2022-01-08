#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  REP(i,n) {
    int a; cin >> a;
    mp[a] = 1;
  }
  REP(i,m) {
    int b; cin >> b;
    mp[b]++;
  }

  for(auto v: mp) if (1 < v.second) cout << v.first << " ";
  cout << endl;

  return 0;
}