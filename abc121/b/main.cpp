#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
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
  int n,m,c; cin >> n >> m >> c;
  int b[m]; REP(i,m) cin >> b[i];
  int a[n][m]; REP(i,n) REP(j,m) cin >> a[i][j];

  int ans = 0;
  REP(i,n) {
    int tot = c;
    REP(j,m) { tot += a[i][j] * b[j]; }
    if (tot > 0) ans++;
  }

  COUT(ans);
  return 0;
}
