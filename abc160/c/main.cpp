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
  int k; cin >> k;
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll ans = LINF;
  REP(i,n) {
    ll pos = 0, neg = 0;
    int next = i-1;
    if (next < 0) next = n-1;
    if (a[i] < a[next]) {
      pos = a[next] - a[i];
    } else {
      pos = k - (a[i] - a[next]);
    }

    next = i+1;
    if (next >= (n-1)) next % (n-1);
    if (a[i] < a[next]) {
      neg = k - (a[next] - a[i]);
    } else {
      neg = a[i] - a[next];
    }
    ans = min(ans, min(neg, pos ));
  }
  cout << ans << endl;
  return 0;
}
