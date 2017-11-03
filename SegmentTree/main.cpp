// 演示线段树构建、查询、更新等操作的示例程序
#include <stdio.h>
#include <math.h>
 
// 获取起止下标中点的工具函数
int getMid(int s, int e) {  return s + (e - s)/2;  }
 
/*  获取数组给定区间之和的递归函数
    下面是函数的参数列表
 
    st    --> 线段树的指针
    index --> 线段树当前节点的下标。 初始传入根节点的下标为0
             根节点的下标值不会变更
    ss & se  --> 线段树当前节点表示的原数组起止下标
                 亦即，st[index]的起止下标
    qs & qe  --> 查询区间的起止下标 */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // 如果当前节点存储的线段是区间的一部分，
    // 返回当前线段的和
    if (qs <= ss && qe >= se)
        return st[index];
 
    // 如果节点存储的线段不在给定区间之内
    if (se < qs || ss > qe)
        return 0;
 
    // 如果节点的线段与区间的一部分有交集
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
/* 更新下标位于给定区间内节点值的递归函数，
    下面是参数列表
    st, index, ss and se 与getSumUtil() 一致
    i    --> 待更新元素的下标，指的是输入数组的下标。
   diff --> 区间需要增加的值 */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    // Base Case: 如果输入下标在线段树范围之外
    if (i < ss || i > se)
        return;
 
    // 如果输入下标在节点范围之内,
    // 则更新节点及其孩子的值
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// 更新输入数组与线段树值的函数。
// 使用了函数 updateValueUtil() 来更新线段树的值
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // 检查错误的输入下标
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // 计算新值与老值之间的差值
    int diff = new_val - arr[i];
 
    // 更新数组的值
    arr[i] = new_val;
 
    // 更新线段树节点的值
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// 返回下标qs（查询起点）到qe（查询终点）的元素之和。
// 主要使用了函数getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // 检查错误的输入
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// 递归函数，为数组[ss..se]构建线段树
// si 是线段树st内当前节点的下标
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // 如果数组只包含一个元素
    // 将其存储与线段树的当前节点并返回
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // 如果有不止一个元素，
    // 则递归计算左右子树，并将两者之和存储与节点内，并返回
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* 从给定数组构建线段树的函数。
   函数为线段树分配内存空间，并调用函数constructSTUtil()
   来填充分配的内存 */
int *constructST(int arr[], int n)
{
    // 为线段树分配内存空间
    int x = (int)(ceil(log2(n))); //线段树的高度
    int max_size = 2*(int)pow(2, x) - 1; //线段树的最大容量
    int *st = new int[max_size];
 
    // 填充线段树st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // 返回构建的线段树
    return st;
}
 
// 上述函数的测试程序
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // 从给定数组构建线段树
    int *st = constructST(arr, n);
 
    // 输出下标1 到 3的元素之和
    printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));
 
    // 更新: 令 arr[1] = 10
    //  并更新相应的线段树节点
    updateValue(arr, st, n, 1, 10);
 
    // 输出更新后的和值
    printf("Updated sum of values in given range = %d\n",
                                                  getSum(st, n, 1, 3));
 
    return 0;
}
