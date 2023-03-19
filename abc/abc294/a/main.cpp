#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  REP(i,n) {
    int a; cin >> a;
    if (a % 2 == 0) cout << a << " ";
  }
  return 0;
}