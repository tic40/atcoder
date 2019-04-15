// https://abs.contest.atcoder.jp/tasks/abc081_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int count = 0;
  for (int i = 0; i < str.size(); i++) if (str[i] == '1') count++;
  cout << count << endl;
}