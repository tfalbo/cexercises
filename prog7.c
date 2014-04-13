# include <stdio.h>

/* Tip Calculator */

int main (){

float total;

printf("Tip Calculator\n");
printf("Insert your bill total\n");
scanf("%f", &total);
printf("Total including the 10 percent tip: %f\n", total*1.1 );


}
