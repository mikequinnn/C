#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a==0)
    {
        if(b==0)
        {
            if(c==0)
            {
                printf("Phuong trinh vo so nghiem\n");
            }
            else
            {
                printf("Phuong trinh vo nghiem\n");
            }
        }

        else
        {
            double x = -c/b;
            printf("Phuong trinh co nghiem don\nx = %.5lf",x);
        }
    }
    else
    {
        double delta = (b*b) - (4*a*c);
        if(delta < 0)
        {
            printf("Phuong trinh vo nghiem");
        }
        else if(delta == 0)
        {
            double x = -b/(2*a);
            printf("Phuong trinh co nghiem kep \nx1 = x2 = %.5lf",x);
        }
        else
        {
            double x1 = (-b + sqrt(delta))/(2*a);
            double x2 = (-b - sqrt(delta))/(2*a);
            printf("Phuong trinh co 2 nghiem phan biet\nx1 = %.5lf\nx2 = %.5lf",x1,x2);
        }
    }
}

