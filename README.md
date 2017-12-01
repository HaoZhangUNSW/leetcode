
# leetcode


1.[C++的链表专题系列](https://segmentfault.com/a/1190000002490878), 主要内容包括reverse,insert,sorted,merge,duplicate.

2.[回溯法讨论](https://zhuanlan.zhihu.com/p/28340833),[leetcode专题](https://discuss.leetcode.com/topic/46162/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partioning/2)

3.[牛顿迭代法](http://blog.punkid.org/2008/02/28/compute-the-square-root-via-newtons-iteration/),用来求平方根，包含简单推导和泰勒公式推导两块。

4.[一个RE错误的代码示例](http://blog.csdn.net/jessir/article/details/60881012)

5.[最美数据结构-并查集](https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86#.E8.B7.AF.E5.BE.84.E5.8E.8B.E7.BC.A9)

[一道题目](http://blog.csdn.net/stpeace/article/details/46506861)

6.[线段树-给定区间求和](http://bookshadow.com/weblog/2015/08/13/segment-tree-set-1-sum-of-given-range/)

7.[当我在递归，我在干什么-从二叉树的遍历说起](https://zhuanlan.zhihu.com/p/30490183)

8.[前缀和，前缀积的三道题目](http://www.cnblogs.com/AndyJee/p/4474073.html)

9.[树状数组](https://zh.wikipedia.org/wiki/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84)

10.[Leetcode中的大整数问题](http://www.voidcn.com/article/p-pstqxxeb-qc.html)

Rosen的《离散数学及其应用》中大整数的计算机算术运算章节讲了一种利用中国剩余定理的方式。比之基于字符串的方式，该方式虽然可以处理大整数，但是大整数范围有限，故没有从本质上解决大整数的运算问题，但是如果给定大整数范围，可以采用这种方案，基于mod的并行计算很棒。

11.[背包问题](http://blog.csdn.net/lyhvoyage/article/details/8545852)

《背包九讲》

12.[C++ STL之哈希表](http://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/)

[Bloom Filter的原理](http://blog.csdn.net/hguisu/article/details/7866173)

[一致性哈希](http://blog.csdn.net/cywosp/article/details/23397179/)

13.[二维数组查找的测试用例设计](http://www.cnblogs.com/edisonchou/p/4737944.html)


具体设计：target在数组中，target不在数组中，target是数组中最小的数，target是数组中最大的数，target比数组中最小的数还小，target比数组中最大的数还大，输入空指针(鲁棒性测试)。

14.[Edison Chou的关于剑指Offer的部分题目的博客，设计了测试用例](http://www.cnblogs.com/edisonchou/category/625054.html)

15.[多源最短路径: Floyd-Warshall算法](http://wiki.jikexueyuan.com/project/easy-learn-algorithm/floyd.html)

时间复杂度是N^3，不能处理"负权环"(可能每转一圈，路程都会更短一些，取决于边和是否大于0)。代码只有五行!!!!思想(dp)：从i顶点到j顶点只经过前k顶点的最短路程。

16.[求二叉树深度，递归和非递归的方式](http://blog.csdn.net/beitiandijun/article/details/41930583)

按层遍历的时候，记录遍历的层数。

17.[最长递增子序列](http://www.ahathinking.com/archives/117.html)

给出了好多思路。

18.[Matrix67的Blog](http://www.matrix67.com/)

19.[合并K个有序数组的最小堆算法](http://blog.csdn.net/u012328476/article/details/52522900)

20.[关于Dijkstra算法和其他的一些图算法(Johnson, Floyd-Warshall, A*)解决最短路径的问题的方法的Python实现](https://zhuanlan.zhihu.com/p/30818986)


21.[关于动态规划的分析，装饰器函数和经典问题(LCS, DAG, 背包问题， 序列对比，最优搜索树)解决方案的Python实现](https://zhuanlan.zhihu.com/p/30738846)


22.[数组中第K大的数](http://www.cnblogs.com/fengkang1008/p/4727038.html)

总结了解决该问题的很多方法。但是个人最喜欢用QuickSorted的思想来解决。

23.[数组中第K大的数-Blog](https://www.cnblogs.com/grandyang/p/4539757.html)

24.**尺取法**的几道题目:[Gas Station](http://www.jianshu.com/p/64abe526fe91),

[Minimum Window Substring](http://blog.csdn.net/ljhandlwt/article/details/52626821)

[尺子覆盖点的数目](http://blog.csdn.net/qingen1/article/details/12358585)

(这道题目百度问过。)

25.[N!的最后一位非零数字](http://blog.csdn.net/rappy/article/details/1903360)需要考虑N!不可计算的场景。

26.[IP地址和整数相互转换](http://blog.csdn.net/zhihaoma/article/details/51841169)
(百度)

27.[完全二叉树的底层最右节点](https://www.cnblogs.com/qieerbushejinshikelou/p/3917019.html)

给出了递归版本和非递归版本。[完全二叉树插入一个节点](http://www.cppblog.com/luyulaile/archive/2011/02/15/140067.html)

28.[尺子覆盖多少点？](http://blog.csdn.net/qingen1/article/details/12358585)

29.[排序二叉树转换成双向链表](http://blog.csdn.net/l_tudou/article/details/51753921)

给出了两种思路。

30.[二叉树的三种遍历方法-递归和非递归](http://blog.csdn.net/ns_code/article/details/12977901/)

31.[KD树算法之详细篇](https://zhuanlan.zhihu.com/p/23966698)

这篇Blog给出了详细的建树过程和利用树结构进行K近邻查询的过程。

[k-d tree算法](http://www.cnblogs.com/eyeszjwang/articles/2429382.html)

这篇Blog给出了kd树较理论的分析，同时给出了部分伪代码。

32.[二叉查找树转为有序双向链表的递归过程分析](http://www.leoox.com/?p=137)

33.[递归函数引用参数对工作栈大小影响的分析](http://blog.csdn.net/zhhz418418/article/details/8973748)

34.[基于贪心算法的几类区间覆盖问题](http://blog.csdn.net/chenguolinblog/article/details/7882316)

区间完全覆盖问题，最大不相交覆盖，区间选点问题。

35.[尾调用优化](http://www.ruanyifeng.com/blog/2015/04/tail-call.html)

讲了尾调用的原理，如何将一般递归转换为尾递归？

36.[递归算法转换为非递归算法的技巧](https://mp.weixin.qq.com/s?__biz=MzA5ODUxOTA5Mg==&mid=2652556683&idx=2&sn=5692497d7b3d352e428be81e73f2ee08&chksm=8b7e3cd0bc09b5c67cc9b557785607f552defdcff0084297dafc4d8ba9c6e9ee8231a18685a5&mpshare=1&scene=1&srcid=1122HbnVa5L18L5MtmzspUqi&key=3c4368fbfacb90f6c4cadce6ea5c67f92e6e756c8854394bb32b42b34bce948a1f8d4d552b74a78e992e3c20edf67c50e9845b93de483df5b344f7ef091a76cc30a637e15fc8c4f1d66732b94468e6ce&ascene=0&uin=MTg2NTIxNzUxNw%3D%3D&devicetype=iMac+MacBookAir7%2C2+OSX+OSX+10.12.6+build(16G29)&version=11020201&pass_ticket=5%2FHbNTzhdkF1OGDmK4ftv4YVskXiezj8KnXUz8AdKgPlHSeKGmHjUaM2rfxMsLQ9)

快速排序的递归写法转换为非递归写法，参照二叉树的先序遍历的非递归的写法。
这篇文章中的快排的写法和王道考研中的貌似一样，不过都是我喜欢的代码，相比于剑指Offer中的代码，这个很棒。

37.[二叉树的最低公共祖先](http://blog.csdn.net/gdmmzmj/article/details/77479110)

这篇blog的想法适用于二叉排序树，当然如果是基于二叉排序树，可以这样想：如果当前节点的值在两个节点之间，则返回当前节点。如果当前节点的值大于两个节点，在当前节点的左子树上寻找；如果小于两个节点，在当前节点的右子树上寻找。

38.[子集树和排列树](http://www.cnblogs.com/diegodu/p/3805669.html)

39.[KMP算法](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)

建立一个部分匹配表：表示一个字符串中头部和尾部子字符串的相同。

[Boyer-Moore算法](http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)

Ctrl+F的查找算法