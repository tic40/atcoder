#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  vector<bool> q(101);
  REP(i,n) cin >> p[i];
  REP(i,n) { int a; cin >> a; q[a] = true; }

  bool ok = false;
  REP(i,n) if (q[max(0, k-p[i])]) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}