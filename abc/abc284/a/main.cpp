#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  REP(i,n) cout << s[n-i-1] << endl;
  return 0;
}