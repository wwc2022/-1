#include<iostream>

int main()
{
    int arr[] = {1,2,3,4,5,6};

    int  length = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < length; i++)
    {
        int k = 0;

        for(int j = i;j<length;j++)
        {
            if(arr[j]>k) k = j;
        }

        int l;
        l = arr[i];
        arr[i] = arr[k];
        arr[k] = l;
    }

     for (int i = 0; i < length; i++)
    {   std::cout<<arr[i]<<" ";}
    
    return  EXIT_SUCCESS;
}