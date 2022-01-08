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
  int a[n+2];
  a[0] = 0; a[n+1] = 0;
  REP(i,n) cin >> a[i+1];

  ll s = 0;
  REP(i,n+1) s+=abs(a[i] - a[i+1]);

  for (int i = 1; i <= n; i++) {
    ll ans = s;
    ans += abs(a[i-1] - a[i+1]) - (abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]));
    COUT(ans);
  }
  return 0;
}
