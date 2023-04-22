#include <iostream>
using namespace std;
typedef int KeyType;
typedef int InfoType;
typedef struct{
    KeyType key;                                   //关键字域
    InfoType otherinfo;                            //其他域
}ElemType;
typedef struct{
    ElemType *R;
    int length;
}SqList;
//直接插入排序:在一段已经排好序的序列中插入数据
void Insert_sort(SqList &L)
{
    int i, j;
    for(i = 2; i <= L.length; i++)
    {
        if(L.R[i].key < L.R[i-1].key)            //查找什么位置顺序改变，这个位置的元素就是要插入的元素
        {
            L.R[0] = L.R[i];                   //将后一位数保存到监视处
            //L.R[i] = L.R[i-1];                 //将前一位数的位置保存到后一位数原来的位置
            for(j = i-1; L.R[0].key<L.R[j].key; j--)  //从后向前查找,监视元素大于位置j中的元素就停止,此时j+1为空
                L.R[j+1] = L.R[j];                   
            L.R[j+1] = L.R[0];                //将监视的元素插到这个空的位置
        }
    }
}

//希尔排序:通过增量序列分块进行插入排序
void Shell_sort(SqList &L,int *dt,int t)       //dt:增量序列的数组   t:数组元素个数    
{
    int i, j, k;
    for(k = 0; k < t; k++)
    {
        for(i = dt[k]+1; i<=L.length; i++)
        {
            if(L.R[i].key < L.R[i-dt[k]].key)
            {
                L.R[0] = L.R[i];
                for(j = i - dt[k]; j>0 && L.R[0].key < L.R[j].key; j-=dt[k])
                L.R[j+dt[k]] = L.R[j];
                L.R[j+dt[k]] = L.R[0];

            }
        }
    }

}
void test()
{
    SqList T;
    int i;
    KeyType Key;
    int arr[3]={5,3,1};
    cout<<"输入顺序表的长度：";
    cin>>T.length;
    cout<<"为顺序表初始化：";
    T.R = new ElemType[T.length];
    for(i=1;i<=T.length;i++)
    {
        cin>>T.R[i].key;
    }
    cout<<"初始化序列:";
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
    cout<<endl<<"排序后的序列:";
    Shell_sort(T,arr,3);
    //Insert_sort(T);
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }

}
int main()
{
    test();
}