#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string t; cin >> t;

  vector<int> ans;
  REP(i,n) {
    string s; cin >> s;

    // 条件 1,4
    auto f1 = [&]() {
      if (s.size() != t.size()) return false;
      int d = 0;
      REP(i,(int)t.size()) if (s[i] != t[i]) d++;
      return d <= 1;
    };

    // 条件 2,3
    auto f2 = [&]() {
      if (abs((int)t.size() - (int)s.size()) != 1) return false;
      bool flag = false;
      if (t.size() < s.size()) { flag = true; swap(t,s); }
      int p = 0;
      REP(i,(int)t.size()) {
        if (p < (int)s.size() && t[i] == s[p]) p++;
      }
      bool res = p >= (int)t.size()-1;
      if (flag) swap(t,s);
      return res;
    };
    if (f1() || f2()) ans.push_back(i+1);
  }

  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}