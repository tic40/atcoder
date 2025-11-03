#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> cnt(2e5+1);
  REP(i,n) {
    int a; cin >> a;
    cnt[a]++;
  }

  ll ans = 0;
  for(auto v: cnt) if (v >= 2) {
    ans += (ll)v*(v-1) / 2 * (n - v);
  }
  cout << ans << endl;
  return 0;
}