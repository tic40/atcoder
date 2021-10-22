#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int q; cin >> q;
  deque<pair<char,int>> que;

  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      char c; int x;
      cin >> c >> x;
      que.push_back({c,x});
    } else {
      int x; cin >> x;
      map<char,int> del;

      while(0 < x) {
        if (que.size() == 0) break;
        auto [q_char, q_cnt] = que.front();
        que.pop_front();

        int mn = min(x, q_cnt);
        del[q_char] += mn;
        q_cnt -= mn;
        x -= mn;
        if (0 < q_cnt) que.push_front({ q_char, q_cnt });
      }

      ll sum = 0;
      for (auto v: del) sum += pow(v.second,2);
      cout << sum << endl;
    }
  }

  return 0;
}