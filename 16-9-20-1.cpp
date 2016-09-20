/*一个循环右移n位的数组中查找一个元素 如7 8 9 1 2 3 4 5 6*/
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
    //递归出口 
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
    cout << "输入数组元素的个数：" << endl;
    cin >> num;
    cout << "请输入 " << num<< " 个元素，以空白符隔开" << endl; 
    for (i = 0; i < num; i++)
    {
        cin >> a[i];
    }
    cout << "输入你要查找那个元素:" << endl;
    while (cin >> find) 
    {
        result = mysearch(a, 0, num-1, find);
        if (result == -1)
            cout << "没有找到这个元素" << endl; 
        else
            cout << "此元素在数组中的位置是: " << result << endl;
    }
    return 0;
}
