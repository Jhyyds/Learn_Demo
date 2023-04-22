#include<iostream>
using namespace std;
typedef int KeyType;
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType otherinfo;
}ElemType;
typedef struct{
    ElemType *R;
    int length;
}SqList;
void Select_sort(SqList &L)
{
    int i, j, k;
    for(i = 1; i < L.length; i++)
    {
        k = i;
        for(j = i + 1; j <= L.length; j++)
            if(L.R[j].key < L.R[k].key) k=j;
        if(k != i)
        {
            L.R[0] = L.R[i];
            L.R[i] = L.R[k];
            L.R[k] = L.R[0];
        }
    }
}

void test()
{
    SqList T;
    int i;
    KeyType Key;
    cout<<"����˳���ĳ��ȣ�";
    cin>>T.length;
    cout<<"Ϊ˳����ʼ����";
    T.R = new ElemType[T.length];
    for(i=1;i<=T.length;i++)
    {
        cin>>T.R[i].key;
    }
    cout<<"��ʼ������:";
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
    cout<<endl<<"����������:";
    Select_sort(T);
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }
}
int main()
{
    test();
}