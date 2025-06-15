#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  for(int x = 100; x >= 0; x--) {
    int idx = lower_bound(a.begin(),a.end(),x) - a.begin();
    if (n-idx >= x) { cout << x << endl; return 0; }
  }
  return 0;
}