#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<string> s(k);
  REP(i,n) if (i < k) cin >> s[i];
  sort(s.begin(),s.end());
  for(auto v: s) cout << v << endl;
  return 0;
}