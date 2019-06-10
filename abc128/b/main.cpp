#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
int main() {
  int n;
  vector<pair<string, int>> data;
  cin >> n;
  vector<int> order(n);
  REP(i, n) {
    string s;
    int p;
    cin >> s >> p;
    data.push_back(make_pair(s, p));
  }
  REP(i, n) {
    int num = 0;
    auto target = data[i];
    REP(j, n) {
      if (i == j) continue;
      int comp = target.first.compare(data[j].first);
      if (comp < 0 || (comp == 0 && data[j].second < target.second)) continue;
      num++;
    }
    order[num] = i + 1;
  }
  REP(i, n) cout << order[i] << endl;
}