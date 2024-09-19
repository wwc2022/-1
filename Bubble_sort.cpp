#include<iostream>


int main()
{
   int arr[6] = {1,2,3,4,5,6};
   int length = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    for(;i<length;i++)
        for (int j = 0; j < length-1; j++)
        {
            if(arr[j]<arr[j+1]){int k;k=arr[j];arr[j]=arr[j+1];arr[j+1]=k;}
        }
  

    for (int i = 0; i < 6; i++)
    {
        std::cout<<arr[i]<<" ";

    }
    return EXIT_SUCCESS;
    
}


