#include<iostream>
using namespace std;
typedef int KeyType;                               //���ùؼ��ֵ�����
typedef char InfoType;                             //������������������
typedef struct
{
    KeyType key;                                   //�ؼ�����
    InfoType otherinfo;                            //������
}ElemType;
typedef struct 
{
    ElemType *R;                                   //�ṹ��������׵�ַ
    int length;                                    //����
    
}SSTble;  
int Search_Bin(SSTble T,KeyType Key)                //���ֲ���
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
int Search_Seq(SSTble T,KeyType Key)           //˳�����
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
    cout<<"����˳���ĳ��ȣ�"<<endl;
    cin>>T.length;
    cout<<"Ϊ˳����ʼ����"<<endl;
    T.R = new ElemType[T.length];
    for(i=1;i<=T.length;i++)
    {
        cin>>T.R[i].key;
    }
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
    cout<<endl<<"����Ҫ���ҵ���"<<endl;
    cin>>Key;
    cout<<"���ҵ��±�Ϊ:"<<Search_Seq(T,Key); 
}