#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
//ʵ����������

//ʵ��Khan�㷨����������
class Topological_Khan{

public:
	vector<int> Khan_sort(int point,vector<pair<int,int> >& edges);
};

//����DFS����������
class Topological_BaseDfs{
public:
	vector<int> BaseDfs_sort(int point,vector<pair<int,int> >& edges);
};