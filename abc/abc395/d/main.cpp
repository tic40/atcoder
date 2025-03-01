#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> bi(n);
  REP(i,n) bi[i] = i;
  vector<int> box(n);
  REP(i,n) box[i] = i;
  vector<int> box2(n);
  REP(i,n) box2[i] = i;

  REP(i,q) {
    int t; cin >> t;
    if (t == 1) {
      int a,b; cin >> a >> b; a--; b--;
      bi[a] = box[b];
    }
    if (t == 2) {
      int a,b; cin >> a >> b; a--; b--;
      swap(box[a],box[b]);
      swap(box2[box[a]],box2[box[b]]);
    }
    if (t == 3) {
      int a; cin >> a; a--;
      cout << box2[bi[a]]+1 << endl;
    }
  }
  return 0;
}
