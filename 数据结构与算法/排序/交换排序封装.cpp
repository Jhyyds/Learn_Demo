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
class Quicksort{                       //����������

public:
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
void Qsort(SqList &L, int low, int high)                         //��������(�ݹ�˼��)
{
    int pivotloc;                           //����λ��(�±�)
    if(low < high)                          //�������Ҵ�,˵������б��Ѿ��ָ����
    {
        pivotloc = Partition(L,low,high);
        Qsort(L,low,pivotloc-1);
        Qsort(L,pivotloc+1,high);
    }
}
void Quick_sort(SqList &L)
{
    Qsort(L,1,L.length);
}
};
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
    //Bubble_sort(T);
    Quicksort Q;
    Q.Quick_sort(T);
    for(i=1;i<=T.length;i++)
    {
        cout<<T.R[i].key<<" ";
    }

}
int main()
{
    test();
}
