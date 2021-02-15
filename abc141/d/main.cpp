#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m; cin >> n >> m;
  priority_queue<int> q;

  int a;
  REP(i,n) {
    cin >> a;
    q.push(a);
  }

  REP(i,m) {
    q.push(q.top()/2);
    q.pop();
  }

  ll ans = 0;
  REP(i,n) {
    ans += q.top();
    q.pop();
  }

  cout << ans << endl;
  return 0;
}