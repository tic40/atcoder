#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> idx(1e6+1,-1);
  int ans = INF;
  REP(i,n) {
    if (idx[a[i]] != -1) ans = min(ans, i - idx[a[i]] + 1);
    idx[a[i]] = i;
  }
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}
