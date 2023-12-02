#include <stdio.h>
#include <stdbool.h>
#define BURYING(i, j, m) ((i) + (j)) % (m)

int main(){
    int size, round;
    while(1){
        scanf("%d %d",&size, &round);
        if(size == 0 && round == 0){
            break;
        }
        int survive[size];
        for( int l = 0; l < size; l++ ){
            for( int i = 0; i < size; i++ ){
                survive[i] = i + 1;
            }
            int kill_counter = 0, round_count = 0, killed = 0, index = l;
            while(kill_counter != size - 1){
                if(survive[index]){
                    round_count++;
                    if(round_count == round){
                        int k = round, j = 1;
                        if(survive[index] == 1){
                            killed = 1;
                            break;
                        }
                        while(k){
                            if( survive[BURYING(index, j, size)] && BURYING(index, j, size) != index){
                                k--;
                            }
                            j++;
                        }

                        if( BURYING(index, j, size) ){
                            survive[index] = survive[BURYING(index, j, size) - 1 ];
                            survive[(index + j) % size - 1] = false;
                        }else{
                            survive[index] = survive[size - 1];
                            survive[size - 1] = false;
                        }
                        round_count = 0;
                        kill_counter++;
                    }
                }
                index = (index + 1)%size;
            }
            if(!killed ){
                printf("%d\n", l + 1);
                break;
            }
        }
    }
    return 0;
}