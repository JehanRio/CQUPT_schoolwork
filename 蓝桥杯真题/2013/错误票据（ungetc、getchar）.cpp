/*某涉密单位下发了某种票据，并要在年终全部收回。每张票据有唯一的ID号，全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。你的任务是通过编程，找出断号的ID和重号的ID，假设断号不可能发生在最大和最小号。
要求程序首先输入一个整数N（N<100）表示后面数据行数，接着读入N行数据，每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000），每个整数代表一个ID号。要求程序输出1行，含两个整数m n，用空格分隔，其中，m表示断号ID，n表示重号ID。
例如，用户输入：
2
5 6 8 11 9
10 12 9
则程序输出：
7 9
再例如，用户输入：
6
164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
172 189 127 107 112 192 103 131 133 169 158
128 102 110 148 139 157 140 195 197
185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
149 138 142 146 199 126 165 156 153 193 144 166 170 121 171 132 101 194 187 188
113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119
则程序输出：
105 120
*/
//链接：https://blog.csdn.net/eurus_/article/details/79267266?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164449900016781683990317%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164449900016781683990317&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-2-79267266.first_rank_v2_pc_rank_v29&utm_term=%E9%94%99%E8%AF%AF%E7%A5%A8%E6%8D%AEc%2B%2B&spm=1018.2226.3001.4187
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
void test1()
{
    int nums[100001]={0};//先初始化为0
    int max=0,min=100001;
    int row;
    cin>>row;//输入行数
    int id;
    char c;
    //getchar();//用于消去输入row时的回车，防止在for中被识别 //getchar()这个一定不能少，就是消去回车
    for(int i=1;i<=row;)
    {
        c=getchar();//获取输入的数据,如果是换行或者空格，则不需要回收
        if(c>='0' && c<='9')
        {
            ungetc(c,stdin);//字符c送回到缓冲区中，保持数据的完整性
            cin>>id;
            nums[id]++;
            if(id<min)min=id;
            if(id>max)max=id;//分别找到最大最小值
        }
        else if(c=='\n')//换行了
        {
            i++;
        }
    }
    int m,n;
    for(int i=min;i<=max;i++)
    {
        if(nums[i]==0)m=i;
        if(nums[i]==2)n=i;
    }
    cout<<m<<" "<<n;
}
void test2()
{
    vector<int>num;
    int n;cin>>n;
    int x;
    while(cin>>x)
    {
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    int chongfu,loudiao;
    int a=num[0];
    for(int i=0;i<num.size();i++)
    {
        if(a==num[i])a++;
        else if(a<num[i])
        {
            loudiao=a+1;
            a+=2;
        }
        else
        {
            chongfu=num[i];
        }
    }
    cout<<loudiao<<" "<<chongfu;
}
int num[100010];
int main()
{
    int x;
    vector<int> a;
    int n;
	cin >> n;
	//自动读到最后,acm的经验 
	while(cin >> x){a.push_back(x);}
	sort(a.begin(), a.end());
	int ans1, ans2;				//断掉的数字和重复的数字
	int num = a[0];				//记录现在应该的数字信息 
	for(int i = 0;i < a.size();i++){
		if(a[i] == num)	{num++;}
		else if(a[i] > num)	{ans1 = num;num += 2;}
		else {ans2 = a[i];} 
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
   