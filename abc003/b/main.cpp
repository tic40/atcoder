#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t, replace = "atcoder";
  cin >> s >> t;

  if (s == t) {
    cout << "You can win" << endl;
    return 0;
  }

  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == t.at(i)) continue;
    if (s.at(i) == '@' || t.at(i) == '@') {
      char c = (s.at(i) != '@') ? s.at(i) : t.at(i);
      if (replace.find(c) != string::npos) continue;
    }
    cout << "You will lose" << endl;
    return 0;
  }
  cout << "You can win" << endl;
}