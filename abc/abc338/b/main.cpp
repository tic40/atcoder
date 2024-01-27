#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<int> cnt(26);
  for(auto c: s) cnt[(int)(c-'a')]++;
  pair<int,int> mx = {0,0};
  REP(i,26) if (mx.second < cnt[i]) mx = { i, cnt[i] };
  cout << (char)('a' + mx.first) << endl;
  return 0;
}