#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  REP(i,m) {
    int b; cin >> b;
    auto it = upper_bound(a.begin(), a.end(), b);
    cout << it - a.begin() << endl;
  }
  return 0;
}