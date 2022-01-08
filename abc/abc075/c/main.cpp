#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;

int n,m;
vector<int> a(50),b(50);
vector<vector<int>> g(50);
bool visited[50];
int ca,cb;

void dfs(int x = 0) {
  if (visited[x]) return;

  visited[x] = 1;
  for(int v: g[x]) {
    if (x == ca && v == cb) continue;
    if (x == cb && v == ca) continue;
    dfs(v);
  }
}

void solve() {
  int ans = 0;

  REP(i,m) {
    ca=a[i],cb=b[i];
    REP(j,n) visited[j]=0;

    dfs();

    int ok = true;
    REP(j,n) if (!visited[j]) ok = false;
    if (!ok) ans++;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  solve();
  return 0;
}