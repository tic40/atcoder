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
  int n,m; cin >> n >> m;
  int x[m]; REP(i,m) cin >> x[i];
  sort(x,x+m);

  int ans = 0;
  vector<int> d(m+1,0);

  for(int i=1; i < m; i++) {
    d[i] = abs(x[i] - x[i-1]);
    ans += d[i];
  }

  sort(d.begin(),d.end(),greater<int>());
  REP(i,min(n-1,m)) ans -= d[i];

  COUT(ans);
  return 0;
}
