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
  vector<vector<int>> is(m);
  REP(i,n) is[a[i]].push_back(i);

  vector<int> d(m+1); // 累積和. 長さkごとの和
  // min_b までにするのは、min_bより先は調べる必要がないため
  REP(l,min_b+1) {
    // 累積和を取る
    d[mr-l+1]++;
    d[m-l+1]--;
    for(int i: is[l]) mr = max(mr, b[i]);
  }

  REP(i,m+1) d[i+1] += d[i];
  for(int i = 1; i <= m; i++) cout << d[i] << " ";
  cout << endl;
  return 0;
}