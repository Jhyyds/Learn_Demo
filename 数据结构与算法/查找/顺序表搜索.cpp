#include<iostream>
using namespace std;
typedef int KeyType;                               //设置关键字的类型
typedef char InfoType;                             //设置其他变量的类型
typedef struct
{
    KeyType key;                                   //关键字域
    InfoType otherinfo;                            //其他域
}ElemType;
typedef struct 
{
    ElemType *R;                                   //结构体数组的首地址
    int length;                                    //长度
    
}SSTble;  
int Search_Bin(SSTble T,KeyType Key)                //二分查找
{
    int low,high,mid;
    low = 1;
    high = T.length;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(T.R[mid].key==Key)
        return mid;
        else if(T.R[mid].key>Key)
        high = mid-1;
        else
        low =mid+1;
    }
    return 0;
}
int Search_Seq(SSTble T,KeyType Key)           //顺序查找
{
    for(int i=T.length;i>=1;i--)
    {
        if(Key==T.R[i].key)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
   SSTble T;
    int i;
    KeyType Key;
    cout<<"输入顺序表的长度："<<endl;
    cin>>T.length;
    cout<<"为顺序表初始化："<<endl;
    T.R = new ElemType[T.length];
    for(i=1;i<=T.length;i++)
    {
        cin>>T.R[i].key;
    }
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
    cout<<endl<<"输入要查找的数"<<endl;
    cin>>Key;
    cout<<"查找的下标为:"<<Search_Seq(T,Key); 
}