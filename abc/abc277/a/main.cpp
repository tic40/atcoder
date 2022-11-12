#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,x; cin >> n >> x;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  REP(i,n) if (p[i] == x) cout << i+1 << endl;
  return 0;
}