#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> a(n),s(n+1);
  REP(i,n) cin >> a[i];
  REP(i,n) s[i+1] = s[i] + a[i];
  REP(i,q) {
    int l,r; cin >> l >> r;
    l--; r--;
    cout << s[r+1]-s[l] << endl;
  }
  return 0;
}