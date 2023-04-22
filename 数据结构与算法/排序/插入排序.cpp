#include <iostream>
using namespace std;
typedef int KeyType;
typedef int InfoType;
typedef struct{
    KeyType key;                                   //�ؼ�����
    InfoType otherinfo;                            //������
}ElemType;
typedef struct{
    ElemType *R;
    int length;
}SqList;
//ֱ�Ӳ�������:��һ���Ѿ��ź���������в�������
void Insert_sort(SqList &L)
{
    int i, j;
    for(i = 2; i <= L.length; i++)
    {
        if(L.R[i].key < L.R[i-1].key)            //����ʲôλ��˳��ı䣬���λ�õ�Ԫ�ؾ���Ҫ�����Ԫ��
        {
            L.R[0] = L.R[i];                   //����һλ�����浽���Ӵ�
            //L.R[i] = L.R[i-1];                 //��ǰһλ����λ�ñ��浽��һλ��ԭ����λ��
            for(j = i-1; L.R[0].key<L.R[j].key; j--)  //�Ӻ���ǰ����,����Ԫ�ش���λ��j�е�Ԫ�ؾ�ֹͣ,��ʱj+1Ϊ��
                L.R[j+1] = L.R[j];                   
            L.R[j+1] = L.R[0];                //�����ӵ�Ԫ�ز嵽����յ�λ��
        }
    }
}

//ϣ������:ͨ���������зֿ���в�������
void Shell_sort(SqList &L,int *dt,int t)       //dt:�������е�����   t:����Ԫ�ظ���    
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