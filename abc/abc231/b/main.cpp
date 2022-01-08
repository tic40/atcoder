#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n;
  cin >> n;
  map<string,int> mp;
  REP(i,n) {
    string s; cin >> s;
    mp[s]++;
  }
  string ans = "";
  int mx = 0;
  for(auto v: mp) {
    if (mx < v.second) {
      mx = v.second;
      ans = v.first;
    }
  }
  cout << ans << endl;
  return 0;
}