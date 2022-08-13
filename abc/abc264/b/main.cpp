#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int r,c; cin >> r >> c;
  cout << (max(abs(r-8), abs(c-8)) % 2 == 0 ? "white" : "black") << endl;
  return 0;
}