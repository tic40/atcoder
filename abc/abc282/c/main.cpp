#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s;
  cin >> n >> s;

  queue<int> q;
  auto replace = [&]() {
    while(q.size()) { s[q.front()] = '.'; q.pop(); }
  };

  int cnt = 0;
  REP(i,n) {
    if (s[i] == ',') q.push(i);
    if (s[i] != '"') continue;
    cnt++;
    if (cnt % 2) replace();
    else q = queue<int>();
  }
  replace();

  cout << s << endl;
  return 0;
}