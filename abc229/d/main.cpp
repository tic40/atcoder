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
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  vector<int> cnt(n+1);
  REP(i,n) cnt[i+1] = (s[i] == '.') ? cnt[i]+1 : cnt[i];

  int ans = 0, r = 0;
  REP(l,n) {
    while(r < n) {
      if (cnt[r+1] - cnt[l] > k) break;
      r++;
    }
    ans = max(ans,r-l);
  }

  cout << ans << endl;
  return 0;
}