#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

string s;

ll dfs(int i, ll left, ll sum) {
  if (i == s.size()) return left + sum;

  int cur = s[i]-'0';
  ll res1 = dfs(i+1, left*10+cur, sum);
  ll res2 = dfs(i+1, cur, sum+left);
  return res1 + res2;
}

int main() {
  cin >> s;
  cout << dfs(1,s[0]-'0',0) << endl;
  return 0;
}