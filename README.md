# Topological_sort
Topological sort based Khan algorithm
基于Khan算法实现的拓扑排序，其实现过程为代码如下：
#L← Empty list that will contain the sorted elements
#S ← Set of all nodes with no incoming edges
#while S is non-empty do
    remove a node n from S
    insert n into L
    foreach node m with an edge e from nto m do
        remove edge e from thegraph
        ifm has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least onecycle)
else
    return L (a topologically sortedorder)

主要是解决了LeetCode 中的第207题：Course Schedule。
拓扑排序还有基于DFS的实现算法，有待实现。
