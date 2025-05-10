#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int r,x; cin >> r >> x;
  bool yes = false;
  if (x == 1 && r >= 1600 && r <= 2999) yes = true;
  if (x == 2 && r >= 1200 && r <= 2399) yes = true;
  cout << (yes ? "Yes" : "No") << endl;
  return 0;
}