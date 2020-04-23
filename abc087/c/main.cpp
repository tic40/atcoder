#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
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
  int a[2][n];
  REP(i,2) {
    REP(j,n) cin >> a[i][j];
  }

  int s1[n+1], s2[n+1];
  s1[0]=0; s2[0]=0;
  REP(i,n) {
    s1[i+1] = s1[i]+a[0][i];
    s2[i+1] = s2[i]+a[1][i];
  }

  ll ans = 0;
  REP(i,n) {
    ll x = s1[i+1] - s1[0] + s2[n] - s2[i];
    ans = max(ans,x);
  }
  COUT(ans);
  return 0;
}
