int main() {
  int *p;
  init(&p);
  printf("%d, %d", *(p+4), *(p + 4 * 7 + 3));
  return 0;
}