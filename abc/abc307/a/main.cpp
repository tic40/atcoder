#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  REP(i,n) {
    int a, s = 0;
    REP(j,7) { cin >> a; s += a; }
    cout << s << " ";
  }
  return 0;
}