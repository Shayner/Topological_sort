#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
//实现拓扑排序

//实现Khan算法的拓扑排序
class Topological_Khan{

public:
	vector<int> Khan_sort(int point,vector<pair<int,int> >& edges);
};

//基于DFS的拓扑排序
class Topological_BaseDfs{
public:
	vector<int> BaseDfs_sort(int point,vector<pair<int,int> >& edges);
};