#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  REP(i,n) {
    int a; cin >> a;
    if (i >= k) cout << a << " ";
  }
  REP(i,min(n,k)) cout << 0 << " ";
  return 0;
}