#include<stdio.h>
#include<math.h>

struct term{
   int coeff;
   int exp;
};

double evaluatePolynomial(struct term poly[],int n,double x){
	double result=0.0;
        int i=0;
   for(i=0;i<n;i++){
	result+=poly[i].coeff*( pow (x,poly[i].exp));
   }
  return result;
}

int main(){
  //f(x)=5x^3+4x^2+2
  struct term poly[]={{5,3},{4,2},{2,0}};
  int n=sizeof(poly)/sizeof(poly[0]);
  double x;
  printf("Enter the value of x");
  scanf("%lf",&x);
  double result=evaluatePolynomial(poly,n,x);
  printf("The value of the polynomial at x=%2lf is :%2lf\n",x,result);

return 0;
}
