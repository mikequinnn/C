#include<stdio.h>

int main()
{
    int nam = 2014;
    float GDP,GDP_2014;
    float toc_do_tang_truong;

    printf("Nhap GDP nam 2014: ");
    scanf("%f",&GDP_2014);
    GDP = GDP_2014;

    printf("Nhap toc do tang truong (%%): ");
    scanf("%f",&toc_do_tang_truong);
    printf("    NAM     GDP\n");
    printf("%8d%8.1f\n",nam++,GDP);

    while(1)
    {
        printf("%8d%8.1f\n",nam++,GDP *= toc_do_tang_truong);
        if(GDP >= 2*GDP_2014)
            break;
    }
}

