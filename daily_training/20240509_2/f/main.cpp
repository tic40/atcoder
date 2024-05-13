#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  unordered_map<string,int> mp;
  REP(i,n) {
    string s; cin >> s;
    int cnt = mp[s]++;
    if (cnt) printf("%s(%d)\n",s.c_str(),cnt);
    else cout << s << endl;
  }

  return 0;
}