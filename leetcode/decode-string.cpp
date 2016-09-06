class Solution {
 public:
  string decodeString(string s) {
    stack<int> times_stack;
    stack<string> str_stack;
    string curr;
    for (int i = 0; i < s.length();) {
      if (isdigit(s[i])) {
        int k = 0;
        while (i < s.length() && isdigit(s[i])) {
          k = k * 10 + s[i] - '0';
          i++;
        }
        times_stack.push(k);
      } else if (s[i] == '[') {
        str_stack.push(curr);
        curr.clear();
        i++;

      } else if (s[i] == ']') {
        int times = times_stack.top();
        times_stack.pop();
        string temp = str_stack.top();
        str_stack.pop();
        for (int i = 0; i < times; i++) {
          temp.append(curr);
        }
        curr.swap(temp);
        i++;
      } else {
        curr += s[i];
        i++;
      }
    }
    return curr;
  }
};