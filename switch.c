#include<stdio.h>
#include<cs50.h>
int main(void)
{
    printf("Hello, This is Vedant Pathak and This is My Code!\n");
    int x=get_int("Enter Switch State Plz! ( O for OFF and 1 for ON): ");
    if(x==1)
    {
     printf("Switch is ON\n");
    }
    else if(x==0)
    {
     printf("Switch is OFF\n");
    }
    else
    {
    printf("Plz Enter The Answer in terms of 0 or 1 only!.\n");
}
return 0;
}
