#include <stdio.h>
#include <string.h>
///// Refer:https://alan23273850.github.io/Online-Judge-Problems/zerojudge/c073/         
#define COMPARE_STRING(x,y) strcmp(x,y) == 0

void replace_blocks( int *group, int size_of_group, int *next, int size_of_next,\
int *preV, int size_of_preV, int *last, int size_of_last, int x){
    int i = last[group[x]]; // i 等於 x 位在的積木堆的最後一個
    while( i != x ){ 
        int j = preV[i];  
        group[i] = i; // 將 i 放回第 i 個積木堆中
        preV[i] = last[i]; // 將 i 的下面一個積木變成 i 積木堆中的最後一個
        next[i] = -1;   // i 為 i 積木堆的最上面一個
        if( last[i] != -1 ){
            next[last[i]] = i; // 將原本位於 i 積木堆最上面的積木的下一個變成 i (意味著 i 為 i 積木堆的最上面)
        }
        last[i] = i; // i 積木堆的最上面為 i 
        i = j; // 將 i 變成在 x 積木堆時的下面一個積木 
    }
    next[x] = -1; // X 為 積木堆的結尾
    last[group[x]] = x; 
    return;
}

int main(){
    int size = 0;
    while(scanf("%d", &size) != EOF){
        int group[size], next[size], preV[size], last[size];
        for( int i = 0; i < size; i++ ){
            last[i] = i;
            group[i] = i;
            next[i] = -1;
            preV[i] = -1;
        }
        char str1[5], str2[5];
        while( scanf("%s", str1) && !COMPARE_STRING(str1, "quit") ){
            int a, b;
            scanf("%d %s %d", &a, str2, &b);
            if( group[a] == group[b] ){
                continue;
            }
            if( COMPARE_STRING(str1, "move") ){
                replace_blocks(group, size, next, size, preV, size, last, size, a);
            }   
            if( COMPARE_STRING(str2, "onto") ){
                replace_blocks(group, size, next, size, preV, size, last, size, b);
            }
            next[preV[a]] = -1; //直接把 a 和 preV[a] 分開
            next[last[group[b]]] = a; // 將目前b所在的積木堆中的最後一個的下一個存成a(意思就是將a以及a後面的積木直接放在b所在的積木堆後面)
            int temp = preV[a]; 
            preV[a] = last[group[b]]; // 把a的前一個變成 b 目前所在的積木堆的最後一個(目前b的最後一個還是原本的數值)
            last[group[b]] = last[group[a]]; // 將b的最後一個更改成 a 原本積木堆中的最後一個
            last[group[a]] = temp; //將 a 原本的前一個變成 a 原本積木堆的最後一個
            while(a != -1){
                group[a] = group[b]; // 將 a 上面的積木變成 b 積木堆
                a = next[a]; 
            }
        }
        for( int i = 0; i < size; i++ ){
            printf("%d:", i);
            int j = last[i];
            while( j != -1 && preV[j] != -1){
                j = preV[j];
            }
            while( j != -1 ){
                printf(" %d", j);
                j = next[j];
            }
            printf("\n");
        }
    }
    return 0;
}
