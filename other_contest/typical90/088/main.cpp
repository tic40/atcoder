#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,q;
bool found = false;
vector<vector<int>> g(88);
vector<vector<int>> memo(8889);
vector<int> a(88), cnt(88);
vector<int> vec;

void dfs(int pos, int sum) {
  if (found) return; // 答えが見つかっていたら打ち切る
  if (pos == n) {
    if (memo[sum].size()) {
      found = true;
      for(auto ans: { memo[sum], vec }) {
        cout << ans.size() << endl;
        for(auto v: ans) cout << v+1 << " ";
        cout << endl;
      }
    }
    memo[sum] = vec;
    return;
  }

  dfs(pos+1, sum);
  if (cnt[pos] == 0) {
    vec.push_back(pos);
    for(int i: g[pos]) cnt[i]++;
    dfs(pos+1, sum+a[pos]);
    for(int i: g[pos]) cnt[i]--;
    vec.pop_back();
  }
  return;
}

int main() {
  cin >> n >> q;
  REP(i,n) cin >> a[i];
  REP(_,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].push_back(y); // x[i] < y[i] の制約があるので双方向じゃなくて良い
  }

  dfs(0,0);
  return 0;
}