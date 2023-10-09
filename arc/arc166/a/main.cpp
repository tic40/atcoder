#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t; cin >> t;
  REP(_,t) {
    int n; string x,y;
    cin >> n >> x >> y;
    x += 'C'; y += 'C'; // 番兵
    n++; // 番兵分を +1
    map<char,vector<int>> mx,my;

    auto check = [&]() -> bool {
      int diff = my['A'].size() - mx['A'].size();
      // X の A の数が多ければ false
      // Y の A の数が多いときは X の C のよりも差分多ければ false
      if (diff < 0 || (int)mx['C'].size() < diff) return false;

      // X の C を早く出現するものから A に置き換える
      REP(i,diff) mx['A'].push_back(mx['C'][i]);
      sort(mx['A'].begin(),mx['A'].end());
      // 両者の A の出現位置を調べる
      REP(i,(int)my['A'].size()) if (my['A'][i] < mx['A'][i]) return false;
      return true;
    };

    bool ok = true;
    REP(i,n) {
      mx[x[i]].push_back(i);
      my[y[i]].push_back(i);
      if (y[i] == 'C') {
        ok = ok && x[i] == 'C' && check();
        mx.clear(); my.clear();
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}