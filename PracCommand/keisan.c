#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int sum = 1;
    int num = atoi(argv[1]);
  for(int i=num;i>0;i--){
    sum=sum*i;
  printf("%d\n", sum);  
  }
  
  printf("%d\n", sum);
   printf("%d\n", num);
   printf("%d\n", argc);

  return 0;
}
