#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, last = 0, min = 0;
  char white = '.', black = '#';
  string s;
  cin >> n >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == white) last++;
  }
  min = last;
  for (int i = 1; i <= s.size(); i++) {
    s.at(i - 1) == black ? last++ : last--;
    if (min > last) min = last;
  }
  cout << min << endl;
}