#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  auto solve1 = [&]() -> void {
    auto f = [&](string& s) {
      int n = s.size();
      vector<int> pi(n);
      for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
      }
      return pi;
    };

    auto sr = s;
    reverse(sr.begin(),sr.end());
    auto t = sr + "_" + s;
    auto pi = f(t);
    int r = pi[t.size()-1];
    auto ans = s;
    auto add = s.substr(0,n-r);
    reverse(add.begin(),add.end());
    ans += add;
    cout << ans << endl;
  };

  // 解説放送解
  auto solve2 = [&]() -> void {
    auto t = s;
    reverse(t.begin(),t.end());
    t += s;
    vector<int> z = z_algorithm(t);

    REP(i,n) {
      if (z[n+i] == n-i) {
        string ans = s;
        ans += t.substr(n-i,i);
        cout << ans << endl;
        return;
      }
    }
  };

  // solve1();
  solve2();
  return 0;
}
