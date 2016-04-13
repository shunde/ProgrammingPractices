/**
 * 枚举法
 * 先插入字符，再 Reduce
 */


#include <stdio.h>
#include <string.h>


int eliminateStrOnce(char* str) {
    if (strlen(str) <= 1) return 0;
    int start, end;
    int n = strlen(str);
    start = 0;
    end = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[start]) {
            str[i] = '.';
            end++;
        } else {
            if (end > start) {
                str[start] = '.';
            }
            end = start = i;
        }
    }
    if (end > start) {
        str[start] = '.';
    }

    int remain = 0;
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != '.')
            str[remain++] = str[i];
        else
            score++;
    }

    str[remain] = '\0';
    return score;
}

int reduce(char* str) {
    int totalScore = 0;
    int score = 0;
    while ((score = eliminateStrOnce(str)) > 0)
        totalScore += score;

    return totalScore;
}



int solve(char *str) {
    char buf[102];
    int len = strlen(str);
    int maxScore = 0;
    char arr[] = "ABC";
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 0)
                strncpy(buf, str, i);
            buf[i] = arr[j];
            if (i < len)
                strncpy(buf + i + 1, str + i, len - i);
            buf[len + 1] = '\0';

            int score = reduce(buf);
            if (maxScore < score)
                maxScore = score;
        }
    }
    return maxScore;
}

int main(int argc, char* argv[]) {
    char buf[102];
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", buf);
        int score = solve(buf);
        printf("%d\n", score);
    }
    return 0;
}