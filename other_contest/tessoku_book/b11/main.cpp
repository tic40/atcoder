#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  int q; cin >> q;
  REP(i,q) {
    int x; cin >> x;
    int id = lower_bound(a.begin(),a.end(),x) - a.begin();
    cout << id << endl;
  }
  return 0;
}