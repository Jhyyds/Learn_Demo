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
void Bubble_sort(SqList &L)                //ð������
{
    int i, j;
    for(i = 1; i < L.length; i++)           //L.length��Ԫ�ؾ�ŪL.length-1��
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
    int pivotkey = L.R[low].key;                             //�����ֵ
    while(low < high)
    {
        while(low < high && L.R[high].key >= pivotkey) high--;           //�������ұ�����С������ֵʱ,����Ż���ߵĿ�λ��
        L.R[low] = L.R[high];
        while(low < high && L.R[low].key <= pivotkey) low++;
        L.R[high] = L.R[low];
    }
    L.R[low] = L.R[0];
    return low;  
}
void Quick_sort(SqList &L, int low, int high)                         //��������(�ݹ�˼��)
{
    int pivotloc;                           //����λ��(�±�)
    if(low < high)                          //�������Ҵ�,˵������б��Ѿ��ָ����
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