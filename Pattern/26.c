#include<stdio.h>
int main()
{
    int rows=5;
     for (int i =1; i <= rows; i++)  
    {  
        for ( int j = 1; j <= rows - i; j++)  
        {  
            printf ("  ");   
        }  
        for (int  k = 0; k < ( 2 * i - 1); k++)  
        {  
            printf ("%d ",k+1); 
        }  
        printf ("\n");  
    }  
    return 0;
}
