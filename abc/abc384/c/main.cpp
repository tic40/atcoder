#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int n = 5;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<pair<int,string>> ans;
  REP(bit,1<<n) {
    int score = 0;
    string s;
    REP(i,n) if (bit >> i & 1) {
      score -= a[i];
      s += char('A'+i);
    }
    ans.emplace_back(score,s);
  }
  sort(ans.begin(),ans.end());
  for(auto [_,s]: ans) cout << s << endl;
  return 0;
}