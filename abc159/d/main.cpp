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

ll m[200005];
vector<ll> memo(200005, -1);

ll choose(ll n, ll a) {
  ll x = 1, y = 1;
  REP(i,a) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) {
    cin >> a[i];
    m[a[i]]++;
  }
  ll ans = 0;
  ll max = 0;

  REP(i, n) {
    if (memo[a[i]] >= 0) continue;
    memo[a[i]] = choose(m[a[i]], 2);
    max+=memo[a[i]];
  }

  REP(i,n) {
    ll x = memo[a[i]];
    if (x <= 0) ans = max;
    else ans = max - x + choose(m[a[i]]-1, 2);
    COUT(ans);
  }
  return 0;
}