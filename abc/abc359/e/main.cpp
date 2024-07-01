#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  vector<P> pa;
  ll ans = 0;
  REP(i,n) {
    int len = 1;
    while(pa.size() && pa.back().first < h[i]) {
      len += pa.back().second;
      ans -= (ll)pa.back().first * pa.back().second;
      pa.pop_back();
    }
    ans += (ll)h[i] * len;
    pa.emplace_back(h[i],len);
    cout << ans+1 << " ";
  }
  return 0;
}