#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  int x; string y; cin >> x >> y;
  x--;
  cout << (s[x] == y ? "Yes" : "No") << endl;
  return 0;
}