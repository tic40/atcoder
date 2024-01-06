#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  REP(i,n+1) REP(j,n+1) REP(k,n+1) {
    int s = i + j + k;
    if (s <= n) cout << i << " " << j << " " << k << endl;
  }
  return 0;
}