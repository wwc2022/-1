/*            9
            4   7   
          5   3   1
        2   4   4   1
      7   5   3   2   4
    ���⣺�ҳ����·����--̰�ġ���̬�滮
*/



#include<stdio.h>
#define NUM 5

int arr[NUM][NUM] = {0};

void initArr();

int max(int a,int b);//����ab�д���Ǹ�

int getmax(int i,int j);

int count = 0;//��¼���·����

int maxArr[NUM][NUM] ;//��ʱ���������Ż�

int main()
{

    initArr();

    count = getmax(0,0);
    

    for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++){
            maxArr[i][j] = -1;//Ϊ-1˵��û�ù�
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
    //step 1���ݹ鷽ʽ ÿһ��������
    if(NUM == i)return arr[i][j];//Խ���ˣ�����

    int n = getmax(i+1,j);
    int m = getmax(i+1,j+1);

    printf("i:%d,j��%d,n��%d,m��%d,arr[%d][%d]:%d\n",i,j,n,m,i,j,arr[i][j]);

    return arr[i][j] + max(n,m);
}
*/

//�Ż�2
int getmax(int i,int j){
    //step 2:֮ǰ�ݹ������Ľ�� ֱ�Ӵ洢 ֱ��ʹ�� ��������
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

//�Ż�3 �ݹ���ѭ�� 
int getmax()
{
    //step3:��step2�Ļ����ϱ��ѭ��
    //�ȸ�����һ�㸳ֵ
    for(int i=0;i<NUM;i++){
        maxArr[NUM -1][i] = arr[NUM - 1][i];
    }
    //Ȼ��ѭ�����㣬һ������ϸ�ֵ 
    for(int i = NUM -2;i>=0;i--)
        for(int j = 0;j<=i;j++){
            maxArr[i][j]  = arr[i][j] + max(maxArr[i+1][j],maxArr[i+1][j+1]);
        }
    return  maxArr[0][0];
}

//�Ż�4 �Ż���ʱ���飬ֻ��Ҫһ������
int getmax()
{   int temp[NUM];
    //�ȸ�����һ�㸳ֵ
    for(int i=0;i<NUM;i++){
        temp[i] = arr[NUM - 1][i];
    }
    //Ȼ��ѭ�����㣬һ������ϸ�ֵ 
    for(int i = NUM -2;i>=0;i--)
        for(int j = 0;j<=i;j++){
            temp[i]  = arr[i][j] + max(temp[j],temp[j+1]);
        }
    return  temp[0];
}
int max(int a,int b){//����ab�д���Ǹ�
    return ((a>b)?a:b);
}