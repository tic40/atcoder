// https://abs.contest.atcoder.jp/tasks/abc086_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  a*b % 2 == 0 ? cout << "Even" : cout << "Odd";
  cout << endl;
}