#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    if(a+b>c && a+c>b && b+c>a)
    {
        if(a == b && b == c)
        {
            printf("(%.5f,%.5f,%.5f) la tam giac deu",a,b,c);
        }
        else if((a*a == b*b + c*c && b == c) || (b*b == a*a + c*c && a == c) || (c*c == a*a + b*b && a == b))
        {
            printf("(%.5f,%.5f,%.5f) la tam giac vuong can",a,b,c);
        }
        else if(a == b || b == c || a == c)
        {
            printf("(%.5f,%.5f,%.5f) la tam giac can",a,b,c);
        }
        else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        {
            printf("(%.5f,%.5f,%.5f) la tam giac vuong",a,b,c);
        }
        else
        {
            printf("(%.5f,%.5f,%.5f) la tam giac thuong",a,b,c);
        }
    }
    else{
        printf("3 canh tren khong phai la tam giac");
    }

}

