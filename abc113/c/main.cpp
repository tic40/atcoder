#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m; cin >> n >> m;
  int p[m],y[m];
  Graph g(100005);
  REP(i,m) {
    cin >> p[i] >> y[i];
    p[i]--;
    g[p[i]].push_back(y[i]);
  }

  REP(i,n) sort(g[i].begin(), g[i].end());
  REP(i,m) {
    auto it = lower_bound(g[p[i]].begin(), g[p[i]].end(), y[i]);
    int order = it - g[p[i]].begin() + 1;
    printf("%06d%06d\n", p[i]+1, order);
  }
  return 0;
}
