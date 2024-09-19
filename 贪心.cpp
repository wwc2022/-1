/*            9
            4   7   
          5   3   1
        2   4   4   1
      7   5   3   2   4
    问题：找出最大路径和--贪心、动态规划
*/



#include<stdio.h>
#define NUM 5

int arr[NUM][NUM] = {0};

void initArr();

int max(int a,int b);//返回ab中大的那个

int getmax(int i,int j);

int count = 0;//记录最大路径和

int maxArr[NUM][NUM] ;//临时数组用来优化

int main()
{

    initArr();

    count = getmax(0,0);
    

    for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++){
            maxArr[i][j] = -1;//为-1说明没用过
        }

    printf("%d\n",count);
 
    return 0;    
}


void initArr(){
    arr[0][0] = 9;
    arr[1][0] = 4;arr[1][1] = 7;
    arr[2][0] = 5;arr[2][1] = 3;arr[2][2] = 1;
    arr[3][0] = 2;arr[3][1] = 4;arr[3][2] = 4;arr[3][3] = 1;
    arr[4][0] = 7;arr[4][1] = 5;arr[4][2] = 3;arr[4][3] = 2;arr[4][4] = 4;

}


/*int getmax(int i,int j){
    //step 1：递归方式 每一步都计算
    if(NUM == i)return arr[i][j];//越界了，结束

    int n = getmax(i+1,j);
    int m = getmax(i+1,j+1);

    printf("i:%d,j：%d,n：%d,m：%d,arr[%d][%d]:%d\n",i,j,n,m,i,j,arr[i][j]);

    return arr[i][j] + max(n,m);
}
*/

//优化2
int getmax(int i,int j){
    //step 2:之前递归计算出的结果 直接存储 直接使用 不用算了
    if(maxArr[i][j]!=-1) return maxArr[i][j];

    if(NUM == i){
        maxArr[i][j] = arr[i][j];
    }
    else {
        int n = getmax(i+1,j);
        int m = getmax(i+1,j);
        maxArr[i][j] = arr[i][j] + max(n,m);
    }

    return maxArr[i][j];
}

//优化3 递归变成循环 
int getmax()
{
    //step3:在step2的基础上变成循环
    //先给最下一层赋值
    for(int i=0;i<NUM;i++){
        maxArr[NUM -1][i] = arr[NUM - 1][i];
    }
    //然后循环计算，一层层往上赋值 
    for(int i = NUM -2;i>=0;i--)
        for(int j = 0;j<=i;j++){
            maxArr[i][j]  = arr[i][j] + max(maxArr[i+1][j],maxArr[i+1][j+1]);
        }
    return  maxArr[0][0];
}

//优化4 优化临时数组，只需要一个容器
int getmax()
{   int temp[NUM];
    //先给最下一层赋值
    for(int i=0;i<NUM;i++){
        temp[i] = arr[NUM - 1][i];
    }
    //然后循环计算，一层层往上赋值 
    for(int i = NUM -2;i>=0;i--)
        for(int j = 0;j<=i;j++){
            temp[i]  = arr[i][j] + max(temp[j],temp[j+1]);
        }
    return  temp[0];
}
int max(int a,int b){//返回ab中大的那个
    return ((a>b)?a:b);
}