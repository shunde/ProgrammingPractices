#include <iostream>
#include <string>


using namespace std;

void get_next(string pat, int* next) {
    if (next == NULL) return;
    
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < pat.length()-1) {
        if (j == -1 || pat[i] == pat[j]) {
            ++i;
            ++j;
            next[i] = j;            
        } else {
            j = next[j];
        }
    }
}


int kmp(string s, string pat, int pos) {

    if (s.length() < pos + pat.length()) return -1;

    int i = pos;
    int j = 0;
    
    int *next = new int[pat.length()];
    get_next(pat, next);

    while (i < s.length() && j < pat.length()) {
        if (j == -1 || s[i] == pat[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == pat.length()) return (i - pat.length());
    else
        return -1;
}


int main(int argc, char *argv[]) {
    string str1 = "abababaabab";
    string str2 = "ababaa";
    cout << kmp(str1, str2, 0) << endl;
    return 0;
}