#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<int> cnt(26);
  for(auto c: s) cnt[c-'a']++;
  REP(i,26) if (cnt[i] == 0) { cout << char('a'+i) << endl; break; }
  return 0;
}