#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  int n = s.size();

  deque<char> t;
  bool rev = 0; // 1のとき反転を表す
  REP(i,n) {
    if (s[i] == 'R') { rev = !rev; continue; }

    if (t.size() == 0) {
      t.push_back(s[i]);
    } else if (rev == 0) {
      if (t.back() == s[i]) t.pop_back();
      else t.push_back(s[i]);
    } else {
      if (t.front() == s[i]) t.pop_front();
      else t.push_front(s[i]);
    }
  }

  if (rev) reverse(t.begin(), t.end());

  for(char c: t) cout << c;
  return 0;
}