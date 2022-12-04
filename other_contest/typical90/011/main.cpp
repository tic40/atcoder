#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

struct Work {
  int d,c,s;
  Work(int d, int c, int s) : d(d),c(c),s(s) {}
  bool operator<(const Work& a) const { return d < a.d; }
};

int main() {
  int n; cin >> n;
  vector<Work> w;
  REP(i,n) {
    int d,c,s; cin >> d >> c >> s;
    w.emplace_back(d,c,s);
  }
  sort(w.begin(),w.end());
  int mxd = w.back().d;

  // dp[i] := i日目までで最大の報酬
  vector<ll> dp(mxd+1, -1);
  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(mxd+1, -1);
    swap(dp,p);
    REP(j,w[i].d+1) {
      dp[j] = p[j];
      if (j - w[i].c < 0) continue;
      if (p[j - w[i].c] == -1) continue;
      chmax(dp[j], p[j-w[i].c] + w[i].s);
    }
  }

  ll ans = *max_element(dp.begin(),dp.end());
  cout << ans << endl;
  return 0;
}