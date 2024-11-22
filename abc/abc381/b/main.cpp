#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;

  auto solve = [&]() {
    int n = s.size();
    if (n%2) return false;
    REP(i,n/2) if (s[2*(i+1)-1-1] != s[2*(i+1)-1]) return false;
    vector<int> cnt(26);
    for(auto c: s) cnt[c-'a']++;
    for(auto v: cnt) if (v != 0 && v != 2) return false;
    return true;
  };

  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}