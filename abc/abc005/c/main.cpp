#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, m;
  cin >> t >> n;
  vector<int> arrA(n);
  for (int i = 0; i < n; i++) cin >> arrA.at(i);
  cin >> m;
  vector<int> arrB(m);
  for (int i = 0; i < m; i++) cin >> arrB.at(i);

  for (int i = 0; i < arrB.size(); i++) {
    bool bought = false;
    for (int j = 0; j < arrA.size(); j++) {
      if (arrA.at(j) <= arrB.at(i) && (arrB.at(i) - arrA.at(j)) <= t) {
        bought = true;
        arrA.erase(arrA.begin() + j);
        break;
      }
    }
    if (!bought) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}