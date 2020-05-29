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
  int n; cin >> n;
  int a[n]; REP(i,n) cin >> a[i];
  int mini = INF;
  REP(i,n) mini = min(mini,a[i]);
  int ans = mini;

  while(1) {
    mini = ans;
    int ok = 1;
    REP(i,n) {
      if (a[i] == mini) continue;
      if (a[i] < mini) { a[i] = 0; break; }
      a[i]%=mini;
      if (a[i] > 0) {
        ok = 0;
        ans = min(ans, a[i]);
      }
    }
    if (ok) break;
  }

  COUT(ans);
  return 0;
}
