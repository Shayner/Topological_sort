#include "Topological_sort.h"

/****************************************************************************/
/**Khan�㷨��α���룺
 **	1����������Q��Q�д洢��Ϊ���Ϊ0�Ľڵ㣻
 **	2����Q��ȡ��һ�����n,��n��������result�У�
 **	3�����ͼ����nΪ��ȵĽڵ�m,ȥ��n---m��һ���ߣ������Ϊ0 �����Q�У��ظ�2��
 **	4��������Q�����޽ڵ㣬�򵱱߽��ҲΪ��ʱ����������
 **						  ��֮����-1����ʾͼ�л���**/
/****************************************************************************/
vector<int> Topological_Khan::Khan_sort(int point,vector<pair<int,int> >& edges){
	queue<int> zeroOfindegree;
	vector<int> result;
	vector<unordered_set<int> > graph(point);   //����ͼ��
	int count = 0;
	int numOfedges = edges.size();

	//����ͼ
	for(int i = 0; i < numOfedges; i++)
		graph[edges[i].first].insert(edges[i].second);

	vector<int> inDegree(point,0);                //��¼�ڵ�����
	vector<int> outDegree(point,0);               //��¼�ڵ�ĳ���

	//����ÿ���ڵ�ĳ����
	for(int j = 0; j < point; j++){
		outDegree[j] = graph[j].size();          //ͳ��ÿ���ڵ�ĳ���
		for(auto k : graph[j])                   //ͳ��ÿ���ڵ�����
			inDegree[k] ++;
	}
	/*for(int i = 0; i < point; i++)
		cout << i <<": in:" << inDegree[i] << "   out:" << outDegree[i] << endl;*/
	//��ʼ������Q
	for(int j = 0; j < point; j++)
		if(inDegree[j] == 0) zeroOfindegree.push(j);
	//����������
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