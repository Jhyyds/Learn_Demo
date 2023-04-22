#include<iostream>
using namespace std;
typedef int KeyType;
typedef char InfoType;
typedef struct {
    KeyType key;
    InfoType otherinfo;
}ElemType;
typedef struct{
    ElemType *R;
    int length;
}SqList;
void Bubble_sort(SqList &L)                //冒泡排序
{
    int i, j;
    for(i = 1; i < L.length; i++)           //L.length个元素就弄L.length-1趟
    {
        for(j = 1; j <= L.length - i; j++)  //i+j=L.length
        {
            if(L.R[j+1].key < L.R[j].key)
            {
                L.R[0] = L.R[j+1];
                L.R[j+1] = L.R[j];
                L.R[j] = L.R[0];
            }
        }
    }
}
int Partition(SqList &L, int low, int high)
{
    L.R[0] = L.R[low];
    int pivotkey = L.R[low].key;                             //枢轴的值
    while(low < high)
    {
        while(low < high && L.R[high].key >= pivotkey) high--;           //遍历当右边数字小于枢轴值时,将其放回左边的空位中
        L.R[low] = L.R[high];
        while(low < high && L.R[low].key <= pivotkey) low++;
        L.R[high] = L.R[low];
    }
    L.R[low] = L.R[0];
    return low;  
}
void Quick_sort(SqList &L, int low, int high)                         //快速排序(递归思想)
{
    int pivotloc;                           //枢轴位置(下标)
    if(low < high)                          //如果左比右大,说明这个列表已经分割完成
    {
        pivotloc = Partition(L,low,high);
        Quick_sort(L,low,pivotloc-1);
        Quick_sort(L,pivotloc+1,high);
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
    //Bubble_sort(T);
    Quick_sort(T,1,T.length);
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
}
int main()
{
    test();
}