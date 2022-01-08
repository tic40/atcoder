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
  ll ans=0;
  int n; cin >> n;
  int a[n],b[n],c[n];
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) cin >> c[i];
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  REP(i,n) {
    ll A = lower_bound(a, a+n, b[i]) - a;
    ll C = n - (upper_bound(c, c+n, b[i]) - c);
    ans+=A*C;
  }
  COUT(ans);
  return 0;
}