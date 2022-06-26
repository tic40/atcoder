#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k,q; cin >> n >> k >> q;
  vector<int> a(k+1);
  REP(i,k) cin >> a[i];
  a.back() = n+1;

  REP(i,q) {
    int l; cin >> l; l--;
    if (a[l+1]-a[l] > 1) a[l]++;
  }

  REP(i,k) cout << a[i] << " ";
  cout << endl;
  return 0;
}
