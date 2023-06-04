#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int now = 1e3, x = 1;
  while(1) {
    if (n < now) { cout << n/x*x; return 0; }
    now *= 10; x *= 10;
  }
}