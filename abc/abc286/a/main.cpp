#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,p,q,r,s;
  cin >> n >> p >> q >> r >> s;
  p--,q--,r--,s--;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,q-p+1) swap(a[p+i],a[r+i]);
  REP(i,n) cout << a[i] << " ";
  cout << endl;

  return 0;
}