#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

char group(int n) {
  if (n==2) return 'c';
  if (n==4 || n==6 || n==9 || n==11) return 'b';
  return 'a';
}

int main() {
  int x,y; cin >> x >> y;
  cout << (group(x) == group(y) ? "Yes" : "No") << endl;
  return 0;
}
