#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  int cnt = 0;
  REP(i,n) if (s[i] == '1') cnt++;
  int d = cnt - k;
  cout << ((d % 2 + 2) % 2 == 0 ? "Yes" : "No") << endl;
  return 0;
}