#include<iostream>

int main()
{
    int arr[20]={1,1};

    for(int i =2;i<20;i++){arr[i] = arr[i-1] + arr[i-2];}

    for(int i =0;i<20;i++){std::cout<<arr[i]<<" ";}

    return 0;
}