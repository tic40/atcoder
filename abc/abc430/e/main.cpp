#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int solve() {
  string a,b; cin >> a >> b;
  int n = a.size();
  vector<int> z = z_algorithm(b+"$"+a+a);
  REP(i,n) if (z[n+1+i] == n) return i;
  return -1;
}

int main() {
  int t; cin >> t;
  REP(_,t) cout << solve() << endl;
  return 0;
}