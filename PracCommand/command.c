#include <stdio.h>

//簡単な足し算

int main(int argc, char *argv[])
{
  int sum = 0;
  int count = 0;

  if (argc < 3) {
    printf("ERROR: invalid of arguments number\n");
    return 1;
  }

  /* argv[0]はコマンド自身なので、計算対象からは除外するため、count=1から開始 */
  for (count=1; count<argc; count++) {
    sum += atoi(argv[count]);
  }
  printf("%d\n", sum);

  return 0;
}
