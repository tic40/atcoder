#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string ans;
  int len = 0;
  REP(i,n) {
    char c; int l;
    cin >> c >> l;
    len += l;
    if (len > 100) { cout << "Too Long"; return 0; }
    REP(j,l) ans += c;
  }
  cout << ans << endl;
  return 0;
}