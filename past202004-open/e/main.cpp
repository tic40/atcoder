#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  REP(i,n) {
    int cnt = 0, x = i;
    while(1) {
      x = a[x];
      cnt++;
      if (i == x) break;
    }
    cout << cnt << " ";
  }
  return 0;
}