#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

ll solve(int i, ll left, ll sum) {
  return s[i] == '\0'
    ? left+sum
    : solve(i+1, left*10 + (s[i]-'0'), sum) + solve(i+1, s[i]-'0', sum + left);
}

int main() {
  cin >> s;
  cout << solve(1, s[0]-'0', 0) << endl;
}