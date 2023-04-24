// 图论
// 软件1 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4


// 邻接矩阵
int Adj_M[maxn][maxn]; 


// 邻接表 
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


// 全局变量 
static int n, m;
static int u, v, w;
int dis[maxn], in[maxn], nr_point[maxn];
bool vis[maxn], nag_vis[maxn];
char graph_class1, graph_class2;
string command;	// 命令代码 
string algo;	// 算法选择 
int g[maxn][maxn];

// Dijkstra 求单源最短路 
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
			if(!vis[t.v] && t.len < mind) // 选出 next 
			{
				min_next = t.v;
				mind = t.len;
			}
			if(!vis[t.v] && dis[now] + t.len < dis[t.v]) // 计算dis 
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

// SPFA 求单源最短路 
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
			if(dis[now] + t.len < dis[t.v]) // 计算dis 
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


// SPFA算法寻找负环 
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
			if(dis[now] + t.len < dis[t.v]) // 计算dis 
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


// SPFA算法返回负环中的结点 
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
			if(dis[now] + t.len < dis[t.v]) // 计算dis 
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
		cout << endl << "图中不存在负环" << endl; 
	}
	else
	{
		cout << endl << "图中负环上的点分别是：" << endl;
		for(int i=1;i<=num;i++)
		{
			cout << nr_point[i] << " ";
		}
		cout << endl;
	}
		
}


// floyd 算法求解多源最短路 
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
	cout << endl << "邻接矩阵：" << endl;
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
			if(Adj_M[i][j] > 65535) cout << "— ";
			else cout << Adj_M[i][j] << "  ";
		}
		cout << endl;
	}
}

void print_adjacency_list()
{
	cout << endl << "邻接表：" << endl;
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
	cout << endl << "最短路径矩阵：" << endl;
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


// o 源     isprint 是否打印 
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
			cout << endl << "点" << o << "到每个点的最短路径：" << endl;
		for(int i=1;i<=n;i++)
		{
			if(isprint == 1)
				cout << "1->" << i << ": " << g[o][i] << endl;
			D[i] = dis[i];
		}
		
		return D;
	}
	if(isprint == 1) 
		cout << endl << "点" << o << "到每个点的最短路径：" << endl;
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
	
	cout << "欢迎使用图论最短路计算器!" << endl;  
	
	while(1)
	{
		cout << "请输入图的结点数和边数(空格隔开)：" << endl << ">>> " ;
		cin >> n >> m;
		
		
		cout << "请选择图的类型(带权图：W/无权图：Z)：" << endl << ">>> ";
		while(cin >> graph_class1)
		{
			if(graph_class1 == 'W' || graph_class1 == 'Z') break;
			else
			{
				cout << "请输入W/Z：" << endl << ">>> ";
			}
		}
		cout << "请选择图的类型(有向图：D/无向图：U)：" << endl << ">>> ";
		while(cin >> graph_class2)
		{
			if(graph_class2 == 'D' || graph_class2 == 'U') break;
			else
			{
				cout << "请输入D/U：" << endl << ">>> ";
			}
		}
		
		cout << "请依次分别输入结点1、结点2以及他们之间的边：" << endl;
		while(m--)
		{
			cout << ">>> ";
			// 读取每条边对应的结点 
			if(graph_class1 == 'Z')
			{
				// 无权图 
				while(1)
				{
					cin >> u >> v;
					if(u > 0 && u <= n && v > 0 && v <= n)
					{
						break;
					}
					else
					{
						cout << "请检查输入的结点格式是否正确" << endl << ">>> "; 
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
				// 带权图 
//				int count = 0;
				while(cin >> u >> v >> w)
				{
					if(cin.good() && u > 0 && u <= n && v > 0 && v <= n)
					{
						break;
					}
					else
					{
						cout << "请检查输入的结点格式是否正确" << endl << ">>> "; 
					}
				}
				// 将结点和边插入邻接表或邻接矩阵 
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
			cout << "请输入命令(输入help查看帮助)：" << endl << ">>> " ; 
			cin >> command;
			flag:
			
			/************************************/
			// 主代码 
			/************************************/
			if(command == "insert_edge")
			{
				cout << "请输入要插入的边：" << endl << ">>> ";
				int uu, vv, ww;
				if(graph_class1 == 'Z')
				{
					// 无权图 
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
					// 带权图 
					cin >> uu >> vv >> ww;
					// 将结点和边插入邻接表或邻接矩阵 
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
				cout << "请输入要插入的结点编号：" << endl << ">>> ";
				int node_num;
				cin >> node_num;
				
				cout << "请输入要插入的边：" << endl << ">>> ";
				int uu, vv, ww;
				if(graph_class1 == 'Z')
				{
					// 无权图 
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
					// 带权图 
					cin >> uu >> vv >> ww;
					// 将结点和边插入邻接表或邻接矩阵 
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
					cout << "请选择最短路求解算法" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
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
						cout << "请输入正确的命令！" << endl;
					}
				}
				print_shortest_matrix();
				continue;
			}
			else if(command == "help")
			{
				cout << "输入help(命令名称)可查看命令的具体用法" << endl; 
				cout << "print_adjacency_list: 打印邻接表" << endl 
					 << "print_adjacency_matrix: 打印邻接矩阵" << endl
					 << "print_shortest_circuit_matrix: 打印最短距离矩阵" << endl
					 << "single_source_shortest_circuit: 单源最短路" << endl
					 << "spfa_judge_nagtive_ring: SPFA查看图中是否存在负环" << endl
					 << "two_node_distance: 求图中两点之间的最短路径" << endl
					 << "spfa_nagtive_ring_node: 返回图中所有在负环上的点" << endl
					 << "insert_edge: 向图中插入边" << endl
					 << "insert_node_and_edge: 向图中插入结点和一条边" << endl
					 << "exit: 退出本次求解" << endl;
				continue;
			}
			else if(command == "help(print_adjacency_list)")
			{
				cout << "命令：print_adjacency_list" << endl
					 << "打印该图所对应的邻接表\n如果图发生改变，则打印新的图所对应的邻接表" << endl; 
				continue;
			}
			else if(command == "help(print_adjacency_matrix)")
			{
				cout << "命令：print_adjacency_matrix" << endl
					 << "打印该图所对应的邻接矩阵\n如果图发生改变，则打印新的图所对应的邻接矩阵" << endl; 
				continue;
			}
			else if(command == "help(print_shortest_circuit_matrix)")
			{
				cout << "命令：print_shortest_circuit_matrix" << endl
					 << "打印最短路径矩阵，并且按照矩阵的形式呈现" << endl
					 << "使用该命令可以选择三种算法对图进行求解" << endl
					 << "所得到的结果为图中两两结点之间的最短距离" << endl; 
				continue;
			}
			else if(command == "help(single_source_shortest_circuit)")
			{
				cout << "命令：single_source_shortest_circuit" << endl
					 << "该命令可以求解由某一点开始的最短路径(单源最短路)" << endl
					 << "输入两个参数:" << endl
					 << "第一个参数代表的是单源最短路的起点" << endl
					 << "第二个参数代表的是是否打印出到每个点的最短路" << endl 
					 << "所得到的结果为图中两两结点之间的最短距离" << endl; 
				continue;
			}
			else if(command == "help(two_node_distance)")
			{
				cout << "命令：two_node_distance" << endl
					 << "该命令可以输出图中任意两点之间的最短路径" << endl
					 << "输入两个参数，分别代表最短路的起点和终点" << endl
					 << "所得到的结果为图中输入两结点之间的最短距离" << endl; 
				continue;
			}
			else if(command == "help(spfa_judge_nagtive_ring)")
			{
				cout << "命令：spfa_judge_nagtive_ring" << endl
					 << "该命令用SPFA算法来判断图中是否存在负环" << endl
					 << "直接调用即可" << endl; 
				continue;
			}
			else if(command == "help(spfa_nagtive_ring_node)")
			{
				cout << "命令：spfa_nagtive_ring_node" << endl
					 << "该命令用SPFA求判断图中在负环上的结点" << endl
					 << "并且可以输出图中在负环上的所有结点" << endl; 
				continue;
			}
			else if(command == "help(exit)")
			{
				cout << "命令：exit" << endl
					 << "退出本次求解，开始下一次求解" << endl; 
				continue;
			}
			else if(command == "single_source_shortest_circuit")
			{
				int param1, param2;
				while(1)
				{
					cout << "请分别输入两个参数：" << endl 
						 << "第一个参数为最短路的源点" << endl
						 << "第二个参数为0/1，表示是否打印源点到所有点的距离" << endl
						 << ">>> "; 
					cin >> param1 >> param2;
					if(param1 > 0  && param1 <= n && (param2 == 0 || param2 == 1))
					{
						break;
					}
					else
					{
						cout << "请注意参数范围" << endl; 
					}
				}
				while(1)
				{
					cout << "请选择最短路求解算法" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
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
						cout << "请输入正确的命令！" << endl;
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
						cout << "请检查输入的参数是否正确！" << endl;
					}
					cout << "end: ";
					cin >> end;
					if(end > 0 && end <= n) break;
					else
					{
						cout << "请检查输入的参数是否正确！" << endl;
					}
				}
				while(1)
				{
					cout << "请选择最短路求解算法" << endl << "dijkstra/spfa/floyd" << endl << ">>> ";
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
						cout << "请输入正确的命令！" << endl;
					}
				}
				int D2 = two_node_distance(start, end);
				cout << endl << "从点" << start << "到点" << end << "之间的距离为" << D2 << endl;  
				continue;
			}
			else if(command == "spfa_judge_nagtive_ring")
			{
				if(spfa_judge_nagtive_ring(1))
				{
					cout << "图中存在负环" << endl;
				}
				else 
				{
					cout << "图中不存在负环" << endl;
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
				cout << "请输入正确的命令!" << endl;
				/************************************/
				// 命令修正 
				/************************************/
				if(command.find("insert_e") != string::npos || command.find("ert_edge") != string::npos )
				{
					cout << "你是否想输入 insert_edge" << endl << "[y/n]";
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
					cout << "你是否想输入 insert_node_and_edge" << endl << "[y/n]";
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
					cout << "你是否想输入 print_adjacency_list" << endl << "[y/n]";
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
					cout << "你是否想输入 print_adjacency_matrix" << endl << "[y/n]";
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
					cout << "你是否想输入 print_shortest_circuit_matrix" << endl << "[y/n]";
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
					cout << "你是否想输入 single_source_shortest_circuit" << endl << "[y/n]";
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
					cout << "你是否想输入 two_node_distance" << endl << "[y/n]";
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
					cout << "你是否想输入 spfa_judge_nagtive_ring" << endl << "[y/n]";
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
					cout << "你是否想输入 spfa_nagtive_ring_node" << endl << "[y/n]";
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
					cout << "你是否想输入 exit" << endl << "[y/n]";
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
					cout << "请选择序号确定输入" << endl
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
							cout << "请输入正确的数据！" << endl << ">>> ";
						}
					}
				}
				
			}
			
		}
		
	}

	
	return 0;
}
/*
测试样例 
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


无向图 
in 
4 4
1 2 1
2 3 -1
1 3 -3
3 4 1
out 
yes

*/

