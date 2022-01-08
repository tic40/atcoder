#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k,s;
  cin >> n >> k >> s;

  int r = 1e9 <= s ? 1 : s+1;
  REP(i,n) {
    if (0 < i) cout << " ";
    cout << (i < k ? s : r);
  }
  return 0;
}