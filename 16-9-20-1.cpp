/*һ��ѭ������nλ�������в���һ��Ԫ�� ��7 8 9 1 2 3 4 5 6*/
#include <iostream>

using namespace std;
#define MAXSIZE 1000

int binarysearch(int a[], int left, int right, int find)
{
    int mid;
    while (left <= right)
    {
        mid = (left+right)/2;
        if (find == a[mid])
        {
            return mid;
        }
        else if (find > a[mid])
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}

int mysearch(int a[], int left, int right, int find)
{
    int result;
    int base = a[left];
    int mid = (left+right)/2;
    //�ݹ���� 
    if (left > right)
        return -1;
    if (find == a[mid])
        return mid;
    else if ((base > a[mid]) && (find > a[mid]))
    {
        if ((result = binarysearch(a, mid+1, right, find)) != -1)    return result;
        else return mysearch(a, left, mid-1, find);
    }
    else if ((base > a[mid]) && (find < a[mid]))
    {
        return mysearch(a, left, mid-1, find);
    }
    else if ((base < a[mid]) && (find < a[mid]))
    {
        if ((result =binarysearch(a, left, mid-1, find)) != -1)    return result;
        else return mysearch(a, mid+1, right, find);
    }
    else if ((base < a[mid]) && (find > a[mid]))
    {
        return mysearch(a, mid+1, right, find);
    }
    else
    {
        return (find == a[left]) ? left : ((find == a[right]) ? right : -1);
    }
}

int main()
{
    int a[MAXSIZE];
    int num;
    int i;
    int result;
    int find;
    cout << "��������Ԫ�صĸ�����" << endl;
    cin >> num;
    cout << "������ " << num<< " ��Ԫ�أ��Կհ׷�����" << endl; 
    for (i = 0; i < num; i++)
    {
        cin >> a[i];
    }
    cout << "������Ҫ�����Ǹ�Ԫ��:" << endl;
    while (cin >> find) 
    {
        result = mysearch(a, 0, num-1, find);
        if (result == -1)
            cout << "û���ҵ����Ԫ��" << endl; 
        else
            cout << "��Ԫ���������е�λ����: " << result << endl;
    }
    return 0;
}
