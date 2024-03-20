#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll k; cin >> k;
  vector<int> ans;
  while(k) {
    ans.push_back(k%2 == 0 ? 0 : 2);
    k /= 2;
  }
  reverse(ans.begin(),ans.end());
  for(auto v: ans) cout << v;
  return 0;
}