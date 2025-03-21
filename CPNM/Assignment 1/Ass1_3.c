#include<stdio.h>
#include<math.h>

int main(){
float a,b,c,D,x1,x2;
//x1 and x2 are the roots of the quadratic equation
//a,b,c are the coefficients
//D is discriminant
printf("Enter the coefficients :");
scanf("%f %f %f",&a,&b,&c);

//D=sqrt (b*b-4*a*c);
x1=(-b+D)/(2*a);
x2=(-b-D)/(2*a);

//printf("The roots of the quadratic equation are %f, %f",x1,x2);
return 0;
}
