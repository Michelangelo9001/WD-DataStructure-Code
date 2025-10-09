#include<stdio.h>
#include<string.h>

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
int main(){
    char pattern[100]="abcb";
    int next[100];
    getNext(pattern,next);
    int i,m;
    m=strlen(pattern);
    for(i=0;i<m;i++){
        printf("%d ",next[i]);
    }
    
}