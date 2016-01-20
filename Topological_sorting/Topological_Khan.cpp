#include "Topological_sort.h"

/****************************************************************************/
/**Khan算法的伪代码：
 **	1：建立队列Q，Q中存储的为入度为0的节点；
 **	2：从Q中取出一个结点n,将n放入结果集result中；
 **	3：检查图中以n为入度的节点m,去除n---m这一条边，若入度为0 则放入Q中，重复2；
 **	4：若队列Q中已无节点，则当边结合也为空时，输出结果；
 **						  反之返回-1：表示图有环；**/
/****************************************************************************/
vector<int> Topological_Khan::Khan_sort(int point,vector<pair<int,int> >& edges){
	queue<int> zeroOfindegree;
	vector<int> result;
	vector<unordered_set<int> > graph(point);   //建立图；
	int count = 0;
	int numOfedges = edges.size();

	//建立图
	for(int i = 0; i < numOfedges; i++)
		graph[edges[i].first].insert(edges[i].second);

	vector<int> inDegree(point,0);                //记录节点的入度
	vector<int> outDegree(point,0);               //记录节点的出度

	//建立每个节点的出入度
	for(int j = 0; j < point; j++){
		outDegree[j] = graph[j].size();          //统计每个节点的出度
		for(auto k : graph[j])                   //统计每个节点的入度
			inDegree[k] ++;
	}
	/*for(int i = 0; i < point; i++)
		cout << i <<": in:" << inDegree[i] << "   out:" << outDegree[i] << endl;*/
	//初始化队列Q
	for(int j = 0; j < point; j++)
		if(inDegree[j] == 0) zeroOfindegree.push(j);
	//拓扑排序处理
	while(!zeroOfindegree.empty()){
		int curPoint = zeroOfindegree.front();
		zeroOfindegree.pop();

		for(auto k : graph[curPoint]){
			inDegree[k] --;
			if(inDegree[k] == 0) zeroOfindegree.push(k);
		}
		count ++;
		result.push_back(curPoint);
	}
	if(count != point) 
		cout << "Graph has at least onecycle!" << endl;
	return result;
}