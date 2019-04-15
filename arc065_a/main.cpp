// https://abs.contest.atcoder.jp/tasks/arc065_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> data = {
    "eraser",
    "erase",
    "dreamer",
    "dream"
  };
  for (string str: data) {
    int pos = 0;
    while( (pos = s.find(str, pos)) != -1) s.replace(pos, str.size(), "");
  }
  cout << (s.size() == 0 ? "YES" : "NO") << endl;
}