int main() {
  init();
  int block;
  void *p = &block;
  int i = *(int *)p;
  p += 4;
  char c = *(char *)p;
  p += 1;
  float f = *(float *)p;
  printf("%d, %c, %f", i, c, f );
  return 0;
}
