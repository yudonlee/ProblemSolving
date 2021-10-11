#include <iostream>
int main(){
 int number, n, m, i, j, result;
 scanf("%d", &number);
 for (i = 0; i < number; i++) {
   scanf("%d %d", &n, &m);
   result = 1;
   for (j = 0; j < n; j++) {
     //calculated in parts, the remainder may occur and it propagates an error in the result value 
     //result *= (m - j) / (j + 1)
     result = result * (m - j) / (j + 1);
   }
   printf("%d\n", result);
 }
 return 0;
}
