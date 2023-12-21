int main() {
  int *a, *b;
  init(&a, &b);
  int sum = 0;
  for(; a < b; a++ ){
  	sum += *a;
  }
  printf("%d", sum);
  return 0;
}
