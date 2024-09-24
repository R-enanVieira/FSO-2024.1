#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q, n;
  cin >> q >> n;

  vector<bool> P(M + 1, false);
  queue<int> pages;
  int pages_fault = 0;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    if (!P[p]) {
      if (pages.size() >= q) {
        int oldest = pages.front();
        pages.pop();
        P[oldest] = false;
      }
      P[p] = true;
      pages.push(p);
      pages_fault++;
    }
  }

  cout << pages_fault << "\n";

  return 0;
}
