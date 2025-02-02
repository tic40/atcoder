#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> box(n,1);
  vector<int> bird(n);
  iota(bird.begin(),bird.end(),0);

  int cnt = 0;
  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int p,h; cin >> p >> h; p--; h--;
      int now = bird[p];
      box[now]--;
      box[h]++;
      if (box[now] == 1) cnt--;
      if (box[h] == 2) cnt++;
      bird[p] = h;
    }
    if (t == 2) cout << cnt << endl;
  }
  return 0;
}