#include <stdio.h>
double sqrt_binarysearch(int,int);

int main(){
    int num,precision;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the precision: ");
    scanf("%d",&precision);
    printf("Square root of %d with precision %d is ",num,precision);
    double ans=sqrt_binarysearch(num,precision);
    printf("%.*f .",precision,ans);
}

double sqrt_binarysearch(int number,int precision){
    double difference=1;
    for(int i=0;i<precision;i++)
    {
        difference/=10;
    }
    double low=0;
    double high=number;
    while((high-low)>difference)
    {
        double mid=(low+high)/2;
        if(mid*mid>=number){
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    return low;
}