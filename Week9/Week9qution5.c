int main() {
  int *a, *b;
  init(&a, &b);
  int sum;
  for(; a < b; a++ ){
  	sum += *a;
  }
  printf("%d", sum);
  return 0;
}
