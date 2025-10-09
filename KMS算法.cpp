#include <stdio.h>
#include <string.h>

// 计算 next 数组 (next[0] = 0 定义)
void getNext(const char *pattern, int *next) {
    int m = strlen(pattern);
    next[0] = 0;  // 第一个位置没有前后缀，设为0
    int j = 0;    // 当前已匹配的前缀长度

    for (int i = 1; i < m; i++) {
        // 如果失配，往前回溯
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        // 如果匹配，前缀长度+1
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
}

int KMP(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0) return 0; // 空模式串默认匹配

    int next[m];
    getNext(pattern, next);

    int j = 0; // 模式串指针
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1]; // 失配，回退
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) { // 匹配成功
            return i - m + 1; // 返回起始下标
        }
    }
    return -1; // 没找到
}

int BF(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0) return 0; // 空模式串，默认匹配成功

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; // 匹配成功，返回起始下标
        }
    }
    return -1; // 未找到
}

int main() {
    char text[100]="1234";
    char pattern[100]="abacabacababcab";

    

    int pos1 = KMP(text, pattern);
    int pos2 = BF(text, pattern);
    printf("position 1=%d,position 2=%d",pos1,pos2);
    return 0;
}
