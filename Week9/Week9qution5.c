int main() {
  int *a, *b;
  init(&a, &b);
  int sum;
  for(; a < b; a++ ){
  	sum += *a;
  }
  //add your code here
  printf("%d", sum);
  return 0;
}
