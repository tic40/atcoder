#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;

int n;
int a[15][15];
int ans = -INF;
vector<vector<int>> g(3);

void dfs(int cur = 0, int tot = 0) {
  if (cur == n) {
    ans = max(ans,tot);
    return;
  }

  REP(i,3) {
    int d = 0;
    for(int v: g[i]) d += a[v][cur];
    g[i].push_back(cur);
    dfs(cur+1, tot+d);
    g[i].pop_back();
  }
  return;
}

// 3bit全探索
void solve2() {
  int ans = -INF;
  for (int mask = 0; mask < pow(3,n); mask++){
    int tmp = mask;
    vector<int> s;
    vector<vector<int>> g(3);
    int d = 0;
    REP(i,n) {
      g[tmp % 3].push_back(i);
      for(int v: g[tmp % 3]) d += a[v][i];
      tmp /= 3;
    }
    ans = max(ans,d);
  }

  cout << ans << endl;
}

int main() {
  cin >> n;
  REP(i,n-1) {
    for(int j = i+1; j < n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }

  int n = 5;
  for (int bit = 0; bit < (1<<n); bit++) {
    vector<int> s;
    REP(i,n) {
      s.push_back(bit >> i & 1);
      // if (bit >> i & 1) s.push_back(i);
    }
    for(auto v: s) cout << v << " ";
    cout << endl;
  }
  return 0;

  // dfs();
  // cout << ans << endl;
  solve2();
  return 0;
}