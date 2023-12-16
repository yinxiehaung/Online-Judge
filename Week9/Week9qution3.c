int main() {
  //init();
  char *str = "banana";
  char *key = "ana";
  int count = 0;
  for( int i = 0; i <= strlen(str) - strlen(key); i++ ){
  	int time = 0;
    for( int j = 0; j <= strlen(key); j++ ){
    	if( str[i + j] == key[j] ){
        	time++;
        }
      	if( time == strlen(key) ){
        	count++;
          	break;
        } 
    }
  }
  printf("%d", count);
  return 0;
}