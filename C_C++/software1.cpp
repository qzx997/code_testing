// ͼ��
// ���1 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4


// �ڽӾ���
int Adj_M[maxn][maxn]; 


// �ڽӱ� 
struct Node{
	int v, len;
};

vector<Node> G[110]; 

void insert_single_dir(int u, int v, int w)
{
	Node temp;
	temp.v = v;
	temp.len = w;
	G[u].push_back(temp);
}

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u, v, w);
	insert_single_dir(v, u, w);
}


// ȫ�ֱ��� 
static int n, m;
static int u, v, w;
int dis[maxn], in[maxn], nr_point[maxn];
bool vis[maxn], nag_vis[maxn];
char graph_class1, graph_class2;
string command;	// ������� 
string algo;	// �㷨ѡ�� 
int g[maxn][maxn];

// Dijkstra ��Դ���· 
void dijkstra(int now)
{
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	vis[now] = 1;
	for(int i=1;i<=n;i++)
	{
		int mind = 100000000, min_next = -1;
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			if(!vis[t.v] && t.len < mind) // ѡ�� next 
			{
				min_next = t.v;
				mind = t.len;
			}
			if(!vis[t.v] && dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
			}
		}
		if(min_next == -1) return ;
		vis[min_next] = true;
		now = min_next;
//		cout << endl << "now: " << now << endl;
	}
}

// SPFA ��Դ���· 
void spfa(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		vis[now] = false;
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			if(dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
				}
			}
		}
	}
}


// SPFA�㷨Ѱ�Ҹ��� 
bool spfa_judge_nagtive_ring(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	memset(in, 0, sizeof(in));
	in[now] = 1;
	
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		vis[now] = false;
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			if(dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
					++in[t.v];
					if(in[t.v] > n)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}


// SPFA�㷨���ظ����еĽ�� 
void spfa_nagtive_ring_node(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	memset(in, 0, sizeof(in));
	in[now] = 1;
	memset(nr_point, 0, sizeof(nr_point));
	int num = 0;
	memset(nag_vis, false, sizeof(nag_vis));
	
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		vis[now] = false;
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			if(dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v] && !nag_vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
					++in[t.v];
					if(in[t.v] > n)
					{
						nag_vis[t.v] = true;
						nr_point[++num] = t.v;
					}
				}
			}
		}
	}
	
	if(num == 0)
	{
		cout << endl << "ͼ�в����ڸ���" << endl; 
	}
	else
	{
		cout << endl << "ͼ�и����ϵĵ�ֱ��ǣ�" << endl;
		for(int i=1;i<=num;i++)
		{
			cout << nr_point[i] << " ";
		}
		cout << endl;
	}
		
}


// floyd �㷨����Դ���· 
void floyd(int n)
{
	memcpy(g, Adj_M, sizeof(g));
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	
	
}


void print_adjacency_matrix()
{
	cout << endl << "�ڽӾ���" << endl;
	for(int i=0;i<=n;i++)
	{
		if(i == 0)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==1) cout << "   | " << j;
				else cout << "  " << j;
			}
			cout << endl;
			for(int j=1;j<=n;j++)
			{
				cout << "------";
			}
			cout << endl;
			continue;
		}
		cout << " " << i << " | ";
		for(int j=1;j<=n;j++)
		{
			if(Adj_M[i][j] > 65535) cout << "�� ";
			else cout << Adj_M[i][j] << "  ";
		}
		cout << endl;
	}
}

void print_adjacency_list()
{
	cout << endl << "�ڽӱ�" << endl;
	for(int i = 1; i <= n; ++i)
	{
		for(vector<Node>:: iterator k = G[i].begin(); k != G[i].end(); ++k)
		{
			Node t = *k;
			cout << i << ": " << t.v << " " << t.len << endl;
		}
		cout << endl;
	}
} 



void print_shortest_matrix()
{
	int dis_matrix[100][100];
	cout << endl << "���·������" << endl;
	memset(dis_matrix, 0, sizeof(dis_matrix));
	for(int i=0;i<=n;i++) 
	{
		if(i == 0)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==1) cout << "   | " << j;
				else cout << "  " << j;
			}
			cout << endl;
			for(int j=1;j<=n;j++)
			{
				cout << "------";
			}
			cout << endl;
			continue;
		}
		
		cout << " " << i << " | ";
		if(algo == "dijkstra") dijkstra(i);
		else if(algo == "spfa") spfa(i);
		else if(algo == "floyd")
		{
			floyd(n);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cout << g[i][j] << "  ";
				}
				cout << endl;
			}
			return ;
		}
		for (int j=1;j<=n;j++)
		{
			cout << dis[j] << "  ";
			dis_matrix[i][j] = dis[j];
		}
		cout << endl;
	}
	cout << endl;
}


// o Դ     isprint �Ƿ��ӡ 
int * single_source_shortest_circuit(int o, bool isprint=0)
{
	int *D = new int[100];
	memset(D, 0, sizeof(D));
	if(algo == "dijkstra") dijkstra(o);
	else if(algo == "spfa") spfa(o);
	else if(algo == "floyd")
	{
		floyd(n);
		if(isprint == 1) 
			cout << endl << "��" << o << "��ÿ��������·����" << endl;
		for(int i=1;i<=n;i++)
		{
			if(isprint == 1)
				cout << "1->" << i << ": " << g[o][i] << endl;
			D[i] = dis[i];
		}
		
		return D;
	}
	if(isprint == 1) 
		cout << endl << "��" << o << "��ÿ��������·����" << endl;
	for (int i=1;i<=n;i++)
	{
		if(isprint == 1 ) 
			cout << "1->" << i << ": " << dis[i] << endl;
		D[i] = dis[i];
	}
	cout << endl << endl;
	
	return D;
}

int two_node_distance(int start, int end)
{
	int *Dis = single_source_shortest_circuit(start, 0);
	return Dis[end]; 
}


int main()
{
	ios::sync_with_stdio(false);
	
	memset(G, 0, sizeof(G));
	memset(Adj_M, 0x3f, sizeof(Adj_M));
	
	cout << "��ӭʹ��ͼ�����·������!" << endl;  
	
	while(1)
	{
		cout << "������ͼ�Ľ�����ͱ���(�ո����)��" << endl << ">>> " ;
		cin >> n >> m;
		
		
		cout << "��ѡ��ͼ������(��Ȩͼ��W/��Ȩͼ��Z)��" << endl << ">>> ";
		while(cin >> graph_class1)
		{
			if(graph_class1 == 'W' || graph_class1 == 'Z') break;
			else
			{
				cout << "������W/Z��" << endl << ">>> ";
			}
		}
		cout << "��ѡ��ͼ������(����ͼ��D/����ͼ��U)��" << endl << ">>> ";
		while(cin >> graph_class2)
		{
			if(graph_class2 == 'D' || graph_class2 == 'U') break;
			else
			{
				cout << "������D/U��" << endl << ">>> ";
			}
		}
		
		cout << "�����ηֱ�������1�����2�Լ�����֮��ıߣ�" << endl;
		while(m--)
		{
			cout << ">>> ";
			// ��ȡÿ���߶�Ӧ�Ľ�� 
			if(graph_class1 == 'Z')
			{
				// ��Ȩͼ 
				while(1)
				{
					cin >> u >> v;
					if(u > 0 && u <= n && v > 0 && v <= n)
					{
						break;
					}
					else
					{
						cout << "��������Ľ���ʽ�Ƿ���ȷ" << endl << ">>> "; 
					}
				}
				w = 1; 
				if(graph_class2 == 'D') 
				{
					insert_single_dir(u, v, w);
				}
				else
				{
					insert_double_dir(u, v, w);
				}
				Adj_M[u][v] = w;
			}
			else 
			{
				// ��Ȩͼ 
//				int count = 0;
				while(cin >> u >> v >> w)
				{
					if(cin.good() && u > 0 && u <= n && v > 0 && v <= n)
					{
						break;
					}
					else
					{
						cout << "��������Ľ���ʽ�Ƿ���ȷ" << endl << ">>> "; 
					}
				}
				// �����ͱ߲����ڽӱ���ڽӾ��� 
				if(graph_class2 == 'D')
				{
					insert_single_dir(u, v, w);
				}
				else
				{
					insert_double_dir(u, v, w);
				}
				Adj_M[u][v] = Adj_M[v][u] = w;
			}
			
			
		}
		
		
		while(1)
		{
			cout << "����������(����help�鿴����)��" << endl << ">>> " ; 
			cin >> command;
			flag:
			
			/************************************/
			// ������ 
			/************************************/
			if(command == "insert_edge")
			{
				cout << "������Ҫ����ıߣ�" << endl << ">>> ";
				int uu, vv, ww;
				if(graph_class1 == 'Z')
				{
					// ��Ȩͼ 
					cin >> uu >> vv;
					w = 1; 
					if(graph_class2 == 'D') 
					{
						insert_single_dir(uu, vv, ww);
					}
					else
					{
						insert_double_dir(uu, vv, ww);
					}
					Adj_M[uu][vv] = ww;
				}
				else 
				{
					// ��Ȩͼ 
					cin >> uu >> vv >> ww;
					// �����ͱ߲����ڽӱ���ڽӾ��� 
					if(graph_class2 == 'D')
					{
						insert_single_dir(uu, vv, ww);
					}
					else
					{
						insert_double_dir(uu, vv, ww);
					}
					Adj_M[uu][vv] = Adj_M[vv][uu] = w;
				}
				continue;
			}
			else if(command == "insert_node_and_edge")
			{
				cout << "������Ҫ����Ľ���ţ�" << endl << ">>> ";
				int node_num;
				cin >> node_num;
				
				cout << "������Ҫ����ıߣ�" << endl << ">>> ";
				int uu, vv, ww;
				if(graph_class1 == 'Z')
				{
					// ��Ȩͼ 
					cin >> uu >> vv;
					w = 1; 
					if(graph_class2 == 'D') 
					{
						insert_single_dir(uu, vv, ww);
					}
					else
					{
						insert_double_dir(uu, vv, ww);
					}
					Adj_M[uu][vv] = ww;
				}
				else 
				{
					// ��Ȩͼ 
					cin >> uu >> vv >> ww;
					// �����ͱ߲����ڽӱ���ڽӾ��� 
					if(graph_class2 == 'D')
					{
						insert_single_dir(uu, vv, ww);
					}
					else
					{
						insert_double_dir(uu, vv, ww);
					}
					Adj_M[uu][vv] = Adj_M[vv][uu] = w;
				}
				continue;
			}
			else if(command == "print_adjacency_list")
			{
				print_adjacency_list();
				continue;
			}
			else if(command == "print_adjacency_matrix")
			{
				print_adjacency_matrix();
				 continue;
			}
			else if(command == "print_shortest_circuit_matrix")
			{
				
				while(1)
				{
					cout << "��ѡ�����·����㷨" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
					cin >> algo;
					if(algo == "Dijkstra" || algo == "dijkstra")
					{
						algo = "dijkstra";
						break;
					}
					else if(algo == "spfa" || algo == "SPFA")
					{
						algo = "spfa";
						break;
					}
					else if(algo == "floyd" || algo == "Floyd")
					{
						algo = "floyd";
						break;
					}
					else
					{
						cout << "��������ȷ�����" << endl;
					}
				}
				print_shortest_matrix();
				continue;
			}
			else if(command == "help")
			{
				cout << "����help(��������)�ɲ鿴����ľ����÷�" << endl; 
				cout << "print_adjacency_list: ��ӡ�ڽӱ�" << endl 
					 << "print_adjacency_matrix: ��ӡ�ڽӾ���" << endl
					 << "print_shortest_circuit_matrix: ��ӡ��̾������" << endl
					 << "single_source_shortest_circuit: ��Դ���·" << endl
					 << "spfa_judge_nagtive_ring: SPFA�鿴ͼ���Ƿ���ڸ���" << endl
					 << "two_node_distance: ��ͼ������֮������·��" << endl
					 << "spfa_nagtive_ring_node: ����ͼ�������ڸ����ϵĵ�" << endl
					 << "insert_edge: ��ͼ�в����" << endl
					 << "insert_node_and_edge: ��ͼ�в������һ����" << endl
					 << "exit: �˳��������" << endl;
				continue;
			}
			else if(command == "help(print_adjacency_list)")
			{
				cout << "���print_adjacency_list" << endl
					 << "��ӡ��ͼ����Ӧ���ڽӱ�\n���ͼ�����ı䣬���ӡ�µ�ͼ����Ӧ���ڽӱ�" << endl; 
				continue;
			}
			else if(command == "help(print_adjacency_matrix)")
			{
				cout << "���print_adjacency_matrix" << endl
					 << "��ӡ��ͼ����Ӧ���ڽӾ���\n���ͼ�����ı䣬���ӡ�µ�ͼ����Ӧ���ڽӾ���" << endl; 
				continue;
			}
			else if(command == "help(print_shortest_circuit_matrix)")
			{
				cout << "���print_shortest_circuit_matrix" << endl
					 << "��ӡ���·�����󣬲��Ұ��վ������ʽ����" << endl
					 << "ʹ�ø��������ѡ�������㷨��ͼ�������" << endl
					 << "���õ��Ľ��Ϊͼ���������֮�����̾���" << endl; 
				continue;
			}
			else if(command == "help(single_source_shortest_circuit)")
			{
				cout << "���single_source_shortest_circuit" << endl
					 << "��������������ĳһ�㿪ʼ�����·��(��Դ���·)" << endl
					 << "������������:" << endl
					 << "��һ������������ǵ�Դ���·�����" << endl
					 << "�ڶ���������������Ƿ��ӡ����ÿ��������·" << endl 
					 << "���õ��Ľ��Ϊͼ���������֮�����̾���" << endl; 
				continue;
			}
			else if(command == "help(two_node_distance)")
			{
				cout << "���two_node_distance" << endl
					 << "������������ͼ����������֮������·��" << endl
					 << "���������������ֱ�������·�������յ�" << endl
					 << "���õ��Ľ��Ϊͼ�����������֮�����̾���" << endl; 
				continue;
			}
			else if(command == "help(spfa_judge_nagtive_ring)")
			{
				cout << "���spfa_judge_nagtive_ring" << endl
					 << "��������SPFA�㷨���ж�ͼ���Ƿ���ڸ���" << endl
					 << "ֱ�ӵ��ü���" << endl; 
				continue;
			}
			else if(command == "help(spfa_nagtive_ring_node)")
			{
				cout << "���spfa_nagtive_ring_node" << endl
					 << "��������SPFA���ж�ͼ���ڸ����ϵĽ��" << endl
					 << "���ҿ������ͼ���ڸ����ϵ����н��" << endl; 
				continue;
			}
			else if(command == "help(exit)")
			{
				cout << "���exit" << endl
					 << "�˳�������⣬��ʼ��һ�����" << endl; 
				continue;
			}
			else if(command == "single_source_shortest_circuit")
			{
				int param1, param2;
				while(1)
				{
					cout << "��ֱ���������������" << endl 
						 << "��һ������Ϊ���·��Դ��" << endl
						 << "�ڶ�������Ϊ0/1����ʾ�Ƿ��ӡԴ�㵽���е�ľ���" << endl
						 << ">>> "; 
					cin >> param1 >> param2;
					if(param1 > 0  && param1 <= n && (param2 == 0 || param2 == 1))
					{
						break;
					}
					else
					{
						cout << "��ע�������Χ" << endl; 
					}
				}
				while(1)
				{
					cout << "��ѡ�����·����㷨" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
					cin >> algo;
					if(algo == "Dijkstra" || algo == "dijkstra")
					{
						algo = "dijkstra";
						break;
					}
					else if(algo == "spfa" || algo == "SPFA")
					{
						algo = "spfa";
						break;
					}
					else if(algo == "floyd" || algo == "Floyd")
					{
						algo = "floyd";
						break;
					}
					else
					{
						cout << "��������ȷ�����" << endl;
					}
				}
				int *Dis = single_source_shortest_circuit(param1, param2);
				continue;
			}
			else if(command == "two_node_distance")
			{
				int start, end;
				while(1)
				{
					cout << "start: ";
					cin >>  start;
					if(start > 0 && start <= n) break;
					else
					{
						cout << "��������Ĳ����Ƿ���ȷ��" << endl;
					}
					cout << "end: ";
					cin >> end;
					if(end > 0 && end <= n) break;
					else
					{
						cout << "��������Ĳ����Ƿ���ȷ��" << endl;
					}
				}
				while(1)
				{
					cout << "��ѡ�����·����㷨" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
					cin >> algo;
					if(algo == "Dijkstra" || algo == "dijkstra")
					{
						algo = "dijkstra";
						break;
					}
					else if(algo == "spfa" || algo == "SPFA")
					{
						algo = "spfa";
						break;
					}
					else if(algo == "floyd" || algo == "Floyd")
					{
						algo = "floyd";
						break;
					}
					else
					{
						cout << "��������ȷ�����" << endl;
					}
				}
				int D2 = two_node_distance(start, end);
				cout << endl << "�ӵ�" << start << "����" << end << "֮��ľ���Ϊ" << D2 << endl;  
				continue;
			}
			else if(command == "spfa_judge_nagtive_ring")
			{
				if(spfa_judge_nagtive_ring(1))
				{
					cout << "ͼ�д��ڸ���" << endl;
				}
				else 
				{
					cout << "ͼ�в����ڸ���" << endl;
				}
				continue;
			}
			else if(command == "spfa_nagtive_ring_node")
			{
				spfa_nagtive_ring_node(1);
				continue;
			}
			else if(command == "exit")
			{
				break;
			}
			else
			{
				cout << "��������ȷ������!" << endl;
				/************************************/
				// �������� 
				/************************************/
				if(command.find("insert_e") != string::npos || command.find("ert_edge") != string::npos )
				{
					cout << "���Ƿ������� insert_edge" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "insert_edge";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("sert_no") != string::npos || command.find("insert_node") != string::npos )
				{
					cout << "���Ƿ������� insert_node_and_edge" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "insert_node_and_edge";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("adjacency_list") != string::npos || command.find("acency_lis") != string::npos )
				{
					cout << "���Ƿ������� print_adjacency_list" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "print_adjacency_list";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("adjacency_matrix") != string::npos || command.find("acency_matr") != string::npos )
				{
					cout << "���Ƿ������� print_adjacency_matrix" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "print_adjacency_matrix";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				
				if(command.find("print_shor") != string::npos || command.find("hortest_circu") != string::npos )
				{
					cout << "���Ƿ������� print_shortest_circuit_matrix" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "print_shortest_circuit_matrix";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				
				if(command.find("single_sou") != string::npos || command.find("ce_shortest_ci") != string::npos )
				{
					cout << "���Ƿ������� single_source_shortest_circuit" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "single_source_shortest_circuit";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				
				if(command.find("two_node") != string::npos || command.find("wo_n") != string::npos )
				{
					cout << "���Ƿ������� two_node_distance" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "two_node_distance";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("pfa_ju") != string::npos || command.find("judge_nagtive_ring") != string::npos )
				{
					cout << "���Ƿ������� spfa_judge_nagtive_ring" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "spfa_judge_nagtive_ring";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("spfa_nagtive") != string::npos || command.find("ring_node") != string::npos )
				{
					cout << "���Ƿ������� spfa_nagtive_ring_node" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "spfa_nagtive_ring_node";
						goto flag;
					}
					else 
					{
						continue;
					}
				}
				
				if(command.find("exi") != string::npos || command.find("xit") != string::npos )
				{
					cout << "���Ƿ������� exit" << endl << "[y/n]";
					cin >> command;
					if(command == "y")
					{
						command = "exit";
						goto flag;
					}
					else 
					{
						continue;
					}
				}



				if(command.find("help(") != string::npos )
				{
					cout << "��ѡ�����ȷ������" << endl
						 << "1. print_adjacency_list" << endl
						 << "2. print_adjacency_matrix" << endl
						 << "3. print_shortest_circuit_matrix" << endl
						 << "4. single_source_shortest_circuit" << endl
						 << "5. two_node_distance" << endl
						 << "6. spfa_judge_nagtive_ring" << endl
						 << "7. spfa_nagtive_ring_node" << endl
						 << "8. exit" << endl << ">>> ";
					int ans;
					while(cin >> ans)
					{
						if(ans == 1)
						{
							command = "help(print_adjacency_list)";
						}
						else if(ans == 2)
						{
							command = "help(print_adjacency_matrix)";
						}
						else if(ans == 3)
						{
							command = "help(print_shortest_circuit_matrix)";
						}
						else if(ans == 4)
						{
							command = "help(single_source_shortest_circuit)";
						}
						else if(ans == 5)
						{
							command = "help(two_node_distance)";
						}
						else if(ans == 6)
						{
							command = "help(spfa_judge_nagtive_ring)";
						}
						else if(ans == 7)
						{
							command = "help(spfa_nagtive_ring_node)";
						}
						else if(ans == 8)
						{
							command = "help(exit)";
						}
						else 
						{
							cout << "��������ȷ�����ݣ�" << endl << ">>> ";
						}
					}
				}
				
			}
			
		}
		
	}

	
	return 0;
}
/*
�������� 
in 
4 6
1 3 5
1 4 9
1 2 3
3 2 2
3 4 4
2 4 1
out 
0 3 5 4


 
in
3 3
1 2 5
2 3 5
3 1 2
out
0 5 2


in
4 4
1 2 4
1 3 4
2 3 8
3 4 1
out 
0 4 4 5


����ͼ 
in 
4 4
1 2 1
2 3 -1
1 3 -3
3 4 1
out 
yes

*/

