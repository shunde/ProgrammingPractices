#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
  int day;
  int height;
  Record(int d = 0, int h = 0) : day(d), height(h) {}
};
int maxHeight(vector<Record>& records, int n) {
  auto comp =
      [](const Record& lhs, const Record& rhs) { return lhs.day < rhs.day; };
  sort(records.begin(), records.end(), comp);
  int maxSofar = records[0].height + records[0].day - 1;
  for (int i = 1; i < records.size(); i++) {
    int hdiff = abs(records[i].height - records[i - 1].height);
    int ddiff = abs(records[i].day - records[i - 1].day);

    if (hdiff > ddiff) return -1;
    int h = min(records[i].height, records[i - 1].height) + (ddiff + hdiff) / 2;
    maxSofar = max(maxSofar, h);
  }
  maxSofar = max(maxSofar, records[records.size() - 1].height + n -
                               records[records.size() - 1].day);
  return maxSofar;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<Record> records(m);
    for (int i = 0; i < m; i++) {
      Record r;
      cin >> r.day >> r.height;
      records[i] = r;
    }
    int result = maxHeight(records, n);
    if (result != -1)
      cout << result << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}