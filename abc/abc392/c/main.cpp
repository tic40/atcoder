#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n),q(n);
  REP(i,n) cin >> p[i], p[i]--;
  REP(i,n) cin >> q[i], q[i]--;

  vector<int> a(n);
  REP(i,n) a[q[i]] = i;
  REP(i,n) cout << q[p[a[i]]]+1 << " ";
  return 0;
}
