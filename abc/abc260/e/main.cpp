#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(n);
  REP(i,n) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  int mr = *max_element(a.begin(),a.end());
  int min_b = *min_element(b.begin(),b.end());

  vector<vector<int>> g(m);
  REP(i,n) g[a[i]].push_back(b[i]);

  // 長さkの数列の数の累積和を取る
  vector<int> d(m+1);
  REP(i,m) {
    if (min_b < i) break;
    d[mr-i+1]++;
    d[m-i+1]--;
    for(int v: g[i]) mr = max(mr,v);
  }

  REP(i,m) d[i+1] += d[i];
  for(int i = 1; i <= m; i++) cout << d[i] << " ";
  cout << endl;
  return 0;
}