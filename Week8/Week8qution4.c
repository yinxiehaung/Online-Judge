#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    //sid student_id coures_id
    //sid score
    int coures[1000][2] = {}, score[1000] = {}, sid, time[1000] = {}, num = 0, student_id;
    for( int i = 0; i < m; i++ ){
        scanf("%d", &sid);
        scanf("%d %d", &student_id, &coures[sid][1]);//student_id coures_id
        num++;
        for( int j = 0; j < 1000; j++ ){
            if(student_id == coures[j][0]){
                num--;
                break;
            }
        }
        coures[sid][0]= student_id;
    }
    int temp, fail = 0;
    for( int i =0; i < n; i++ ){
        scanf("%d %d", &sid, &temp);
        score[sid] += temp;
        time[sid]++;
    }
    for( int i = 0; i < m; i++ ){
        if(time[i] != 0){
            double avg = score[i]/(double)time[i];
            if(avg < 60.0 ){
                fail++;
            }
        }
    }
    printf("%d %d\n", num, fail);
    return 0;
}