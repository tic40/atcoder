#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i], a[i]--;

  const int m = 20;
  vector<vector<int>> is(m);
  REP(i,n) is[a[i]].push_back(i);

  auto getNext = [&](int c, int i, int k) {
    if (k == 0) return i;
    auto& vec = is[c];
    int j = lower_bound(vec.begin(),vec.end(),i) - vec.begin();
    j += k-1;
    return j < (int)vec.size() ? vec[j]+1 : INF;
  };

  // dp[bit] := 今まで使った数の集合が bit のとき
  // 貪欲に取ったときの添字の min
  vector<int> dp(1<<m,INF);
  dp[0] = 0;

  int ans = 0;
  REP(bit,1<<m) {
    if (dp[bit] != INF) ans = max(ans, __builtin_popcount(bit));
    REP(c,m) {
      if (bit >> c & 1) continue;
      chmin(dp[bit | 1<<c], getNext(c,dp[bit],2));
    }
  }

  cout << ans*2 << endl;
  return 0;
}