#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9+5;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());
  vector b(2,vector<int>());
  REP(i,n) b[ a[i]%2 ].push_back(a[i]);
  b[0].push_back(-INF);
  b[1].push_back(-INF);

  int ans = max(b[0][0]+b[0][1], b[1][0]+b[1][1]);
  cout << (ans < 0 ? -1 : ans) << endl;
  return 0;
}