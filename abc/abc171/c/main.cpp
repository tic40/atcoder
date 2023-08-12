#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  ll n; cin >> n;
  vector<int> ans;
  while(n > 0) {
    n -= 1;
    ans.push_back(n % 26);
    n /= 26;
  }
  for(auto v: ans) cout << char('a'+v);
  return 0;
}