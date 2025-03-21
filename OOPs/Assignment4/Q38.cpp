#include<iostream>
#include<complex>
#include<cmath>
using namespace std;
class Complex{
    double real;
    double img;
  public:
      Complex(double real=0,double img=0){
         this->real=real;
         this->img=img;
         }
   friend ostream& operator<<(ostream &os,const Complex ob){
        if(ob.img>=0){
           os<<ob.real<<"+"<<ob.img<<"i"<<endl;
          }
        else{
          os<<ob.real<<"-"<<ob.img<<"i"<<endl;
         }
      }
 };

class Quadratic{
  double a,b,c;
   public:
    Quadratic(double a=0,double b=0,double c=0){
        this->a=a;
        this->b=b;
        this->c=c;
      }
    double compute(double x){
      return a*x*x+b*x+c;
     }
    Quadratic operator+(Quadratic &ob){
        Quadratic t;
         t.a=a+ob.a;
         t.b=b+ob.b;
         t.c=c+ob.c;
       return t;
       }
    
friend ostream& operator<<(ostream &os,const Quadratic obj){
     os<<obj.a<<" ";
     os<<obj.b<<" ";
     os<<obj.c<<" ";
  return os;
  }




        

  
pair<Complex,Complex> roots()const{
         double discriminant=b*b-4*a*c;
         Complex root1,root2;
       if(discriminant>0){
         double r1=(-(b)+sqrt(discriminant))/(2*a);
         double r2=((-b)-sqrt(discriminant))/(2*a);
         root1=Complex(r1,0);
         root2=Complex(r2,0);
        }
      else if(discriminant==0){
         double r3=-b/(2*a);
         root1=root2=Complex(r3,0);
        }
       else{
        double r4=-b/(2*a);
        double r5=sqrt(-discriminant)/(2*a);
        root1=Complex(r4,r5);
        root2=Complex(r4,-r5);
         }
            return {root1,root2};
     }
};



 int main(){
       Quadratic q1(2,3,1);
       Quadratic q2(5,6,1);
       Quadratic sum=q1+q2;
       cout<<"Polynomial 1:"<<q1<<endl;
       cout<<"Polynomial 2:"<<q2<<endl;
       cout<<"Sum="<<sum<<endl;
       double x=1.0;
       cout<<"Value of polynomial at x="<<x<<" is "<<q1.compute(x)<<endl;
       auto [root1,root2]=q1.roots();
       cout<<"roots of polynomial:"<<root1<<" "<<root2;

  return 0;
}
