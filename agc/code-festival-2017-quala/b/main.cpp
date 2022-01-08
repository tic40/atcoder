#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,m,k;
string solve() {
  bool ok = false;
  REP(i,n+1) REP(j,m+1) {
    if (i*(m-j) + j*(n-i) == k) ok = true;
  }

  return ok ? "Yes" : "No";
}

int main() {
  cin >> n >> m >> k;
  cout << solve() << endl;
  return 0;
}