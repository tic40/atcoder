#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = 1e9;

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  map<char,vector<int>> mp;
  REP(i,n) mp[s[i]].push_back(i);

  auto getNext = [&](char c, int i, int k) {
    if (k == 0) return i;
    auto& vec = mp[c];
    int j = lower_bound(vec.begin(),vec.end(),i) - vec.begin();
    j += k-1;
    return j < (int)vec.size() ? vec[j]+1 : INF;
  };

  REP(qi,q) {
    int l,r; cin >> l >> r;
    l--;

    auto f = [&](int k) {
      int i = l;
      i = getNext('1',i,k);
      i = getNext('/',i,1);
      i = getNext('2',i,k);
      return i <= r;
    };

    int ok = -1, ng = n;
    while(ng-ok>1) {
      int mid = (ok+ng)/2;
      if (f(mid)) ok = mid;
      else ng = mid;
    }
    cout << (ok == -1 ? 0 : ok*2+1) << endl;
  }
  return 0;
}