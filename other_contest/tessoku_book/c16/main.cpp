#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using T = tuple<int,int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> a(m),s(m),b(m),t(m);
  REP(i,m) {
    cin >> a[i] >> s[i] >> b[i] >> t[i];
    a[i]--; b[i]--;
    t[i] += k;
  }

  // { 時間, type(0: 最初と最後, 1: 到着, 2: 出発), id }
  vector<T> list;
  REP(i,m) list.emplace_back(s[i],2,i);
  REP(i,m) list.emplace_back(t[i],1,i);
  REP(i,n) list.emplace_back(-1,0,i);
  REP(i,n) list.emplace_back(INF,0,i);
  sort(list.begin(),list.end());
  int lsz = list.size();

  vector<int> vs(m),vt(m);
  REP(i,lsz) {
    auto [_,type,ni] = list[i];
    if (type == 2) vs[ni] = i+1;
    if (type == 1) vt[ni] = i+1;
  }

  vector airport(n,vector<int>());
  REP(i,lsz) {
    auto [_,type,ni] = list[i];
    if (type == 0) airport[ni].push_back(i+1);
    if (type == 1) airport[b[ni]].push_back(i+1);
    if (type == 2) airport[a[ni]].push_back(i+1);
  }

  // { idx, 飛行機に乗るかどうか }
  vector g(lsz+2,vector<P>());
  REP(i,m) g[vt[i]].emplace_back(vs[i],1);
  REP(i,n) REP(j,(int)airport[i].size()-1) {
    int idx1 = airport[i][j];
    int idx2 = airport[i][j+1];
    g[idx2].emplace_back(idx1,0);
  }

  REP(i,n) {
    g[airport[i][0]].emplace_back(0,0);
    g[lsz+1].emplace_back(airport[i].back(),0);
  }

  vector<int> dp(lsz+2);
  REP(i,lsz+2) for(auto [to,add]: g[i]) {
    dp[i] = max(dp[i], dp[to] + add);
  }
  cout << dp.back() << endl;
  return 0;
}