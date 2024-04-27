#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  REP(i,n) REP(j,n) if (a[i][j] != b[i][j]) {
    cout << i+1 << " " << j+1 << endl;
  }
  return 0;
}