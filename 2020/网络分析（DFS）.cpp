/*小明正在做一个网络实验。
他设置了 n 台电脑，称为节点，用于收发和存储数据。
初始时，所有节点都是独立的，不存在任何连接。
小明可以通过网线将两个节点连接起来，连接后两个节点就可以互相通信
了。两个节点如果存在网线连接，称为相邻。
小明有时会测试当时的网络，他会在某个节点发送一条信息，信息会发送
到每个相邻的节点，之后这些节点又会转发到自己相邻的节点，直到所有直接
或间接相邻的节点都收到了信息。所有发送和接收的节点都会将信息存储下来。
一条信息只存储一次。
给出小明连接和测试的过程，请计算出每个节点存储信息的大小。
【输入格式】
输入的第一行包含两个整数 n,m，分别表示节点数量和操作数量。节点从
1 至 n 编号。
接下来 m 行，每行三个整数，表示一个操作。
如果操作为 1 a b，表示将节点 a 和节点 b 通过网线连接起来。当 a = b
时，表示连接了一个自环，对网络没有实质影响。
如果操作为 2 p t，表示在节点 p 上发送一条大小为 t 的信息。
【输出格式】
输出一行，包含 n 个整数，相邻整数之间用一个空格分割，依次表示进行
完上述操作后节点 1 至节点 n 上存储信息的大小。
试题J: 网络分析 12
第十一届蓝桥杯大赛软件类省赛 C/C++ 大学 B 组
【样例输入】
4 8
1 1 2
2 1 10
2 3 5
1 4 1
2 2 2
1 1 2
1 2 4
2 2 1
【样例输出】
13 13 5 3
【评测用例规模与约定】
对于 30% 的评测用例，1 ≤ n ≤ 20，1 ≤ m ≤ 100。
对于 50% 的评测用例，1 ≤ n ≤ 100，1 ≤ m ≤ 1000。
对于 70% 的评测用例，1 ≤ n ≤ 1000，1 ≤ m ≤ 10000。
对于所有评测用例，1 ≤ n ≤ 10000，1 ≤ m ≤ 100000，1 ≤ t ≤ 100。
*/
#include<iostream>
#include<cstring>
using namespace std;
#define N 10005
int n,m;
int vis[N];
int map[N][N];
int ans[N];
class soultion2//并查集
{
    public:
int n,m;
int i,j,k; 
int num[N]; 
//表示为：N的大哥为f[N]这个值  范围  1<=f[N]<=n
int f[N];
//表示为：N的小弟数量为f[N]这个值  
int r[N]; 
// 对f[N]进行初始化，每个人是自己的大哥 
// 对r[N]进行初始化，每个人都有自己的小弟 
void init(){
	for(i=1;i<=n;i++){
		f[i]=i;
		r[i]=1; 
	}
}
//找自己 （x） 的大哥 
int find(int x){
	 return f[x]==x?x:(f[x]=find(f[x]));
 } 
//x所在帮派和y所在帮派合并，那么x的所有人和y的所有人就是兄弟了
//但是呢？还是需要一个大哥，谁来做大哥呢？当然是小弟多的人做大哥呀 
void send(int x,int y){
	int tempx,tempy;
	//分别找到自己的总大哥 
	tempx = find(x);
	tempy = find(y);
	if(r[tempx]>=r[tempy]){
		//tempx的小弟人数多，那么tempy就并到tempx之下，成为tempy的小弟 
		f[tempy]=tempx; 
	}
	else{
		f[tempx]=tempy;
	}
	// if(r[tempx]==r[tempy]&&tempx!=tempy){
	// 	r[tempx]++;
	// }
} 
void count(int x,int y){
	int tempx;
	tempx = find(x);
	for(i=1;i<=n;i++){
		if(tempx==find(i)){
			num[i]+=y;
		}
	}
} 
int test(){
	cin>>n>>m;
	init();
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1){
			send(y,z);
		}
		if(x==2){
			count(y,z);
		}
	}
	for(i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	return 0;
} 

};
class solution1//dfs
{
public:
void dfs(int x,int y)
{
    ans[x]+=y;
    vis[x]=1;//访问过这个结点了
    for(int i=1;i<=n;i++)//遍历每一个结点
    {
        if(!vis[i] && map[i][x]==1)
        {
            dfs(i,y);
        }
    }
}
int test()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1)
        {
            map[y][z]=map[z][y]=1;//表示这2个相连
        }
        else if(x==2)
        {
            memset(vis,0,sizeof(vis));
            dfs(y,z);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
};

int main()
{
    solution1 s1;
    soultion2 s2;
    s1.test();
    cout<<endl;
    s2.test();
    return 0;
}