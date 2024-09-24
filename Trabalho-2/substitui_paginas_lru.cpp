#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q, n;
  cin >> q >> n;

  unordered_map<int, list<int>::iterator> page_map;
  list<int> pages;
  int pages_fault = 0;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    if (page_map.find(p) == page_map.end()) {  // page fault
      if (pages.size() >= q) {
        int lru_page = pages.back();
        pages.pop_back();
        page_map.erase(lru_page);
      }
      pages.push_front(p);
      page_map[p] = pages.begin();
      pages_fault++;
    } else {  // page hit
      pages.erase(page_map[p]);
      pages.push_front(p);
      page_map[p] = pages.begin();
    }
  }

  cout << pages_fault << "\n";

  return 0;
}
