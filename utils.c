#include <stdio.h>
#include <stdlib.h>


int in_liste(int data, int* liste, int n){
    for (int i = 0; i < n-1; i++)
    {
        if (liste[i]==data)
        {
            return 1;
        }
    }
    return 0;
}



int max(int size, int* liste){
    int maxi = liste[0];
    for (int i = 0; i < size; i++)
    {
        if (liste[i]>maxi){
            maxi = liste[i];
        }
    }
    return maxi;
}



// int main(void)
// {

    

//     return 0;
// }