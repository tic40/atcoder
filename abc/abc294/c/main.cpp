#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  vector<int> c;
  REP(i,n) c.push_back(a[i]);
  REP(i,m) c.push_back(b[i]);
  sort(c.begin(),c.end());

  REP(i,n) {
    auto it = lower_bound(c.begin(), c.end(), a[i]);
    cout << it - c.begin() + 1 << " ";
  }
  cout << endl;
  REP(i,m) {
    auto it = lower_bound(c.begin(), c.end(), b[i]);
    cout << it - c.begin() + 1 << " ";
  }
  cout << endl;
  return 0;
}