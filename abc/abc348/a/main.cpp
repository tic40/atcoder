#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  REP(i,n) cout << ((i+1) % 3 ? "o" : "x");
  return 0;
}