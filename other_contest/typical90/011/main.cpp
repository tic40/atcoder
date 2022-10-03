#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

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
  sort(w.begin(),w.end()); // 締切日の昇順
  int maxd = w.back().d;
  vector<ll> dp(maxd+1,-1); // dp[i日目] = i日目で最大の報酬
  dp[0] = 0;

  REP(i,n) {
    vector<ll> p(maxd+1, -1);
    swap(dp,p);

    REP(j,w[i].d+1) {
      dp[j] = p[j];
      if (j - w[i].c < 0) continue;
      if (p[j - w[i].c] == -1) continue;
      dp[j] = max(dp[j], p[j - w[i].c] + w[i].s);
    }
  }

  ll ans = *max_element(dp.begin(),dp.end());
  cout << ans << endl;
  return 0;
}