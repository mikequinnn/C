#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c;
    double d,e,f;
    scanf("%lf%lf%lf",&a,&b,&c);
    scanf("%lf%lf%lf",&d,&e,&f);
    /*
    ax + by = c
    dx + ey = f
    */
    double D,Dx,Dy;
    D = a*e - b*d;
    Dx = c*e - b*f;
    Dy = a*f - c*d;
    if(D == 0)
    {
        if (Dx ==0 && Dy == 0)
            printf("He phuong trinh cos vo so nghiem ");
        else
            printf("He phuong trinh vo nghiem");
    }
    else
    {
        printf("He phuong trinh co nghiem duy nhat\n");
        printf("x = %.5lf\n",Dx/D);
        printf("y = %.5lf",Dy/D);

    }
}

