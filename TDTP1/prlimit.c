#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>

int main(){
  long var1,var2;
  var1=NAME_MAX;
  var2=PATH_MAX;
  printf("%d %d\n",var1,var2);

  return 0;

}
