/*ĳ���ܵ�λ�·���ĳ��Ʊ�ݣ���Ҫ������ȫ���ջء�ÿ��Ʊ����Ψһ��ID�ţ�ȫ������Ʊ�ݵ�ID���������ģ���ID�Ŀ�ʼ���������ѡ���ġ�
��Ϊ������Ա�������¼��ID�ŵ�ʱ������һ�����������ĳ��ID�Ϻţ�����һ��ID�غš����������ͨ����̣��ҳ��Ϻŵ�ID���غŵ�ID������ϺŲ����ܷ�����������С�š�
Ҫ�������������һ������N��N<100����ʾ�����������������Ŷ���N�����ݣ�ÿ�����ݳ��Ȳ��ȣ����ÿո�ֿ������ɸ���������100������������������100000����ÿ����������һ��ID�š�Ҫ��������1�У�����������m n���ÿո�ָ������У�m��ʾ�Ϻ�ID��n��ʾ�غ�ID��
���磬�û����룺
2
5 6 8 11 9
10 12 9
����������
7 9
�����磬�û����룺
6
164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
172 189 127 107 112 192 103 131 133 169 158
128 102 110 148 139 157 140 195 197
185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
149 138 142 146 199 126 165 156 153 193 144 166 170 121 171 132 101 194 187 188
113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119
����������
105 120
*/
//���ӣ�https://blog.csdn.net/eurus_/article/details/79267266?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164449900016781683990317%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164449900016781683990317&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-2-79267266.first_rank_v2_pc_rank_v29&utm_term=%E9%94%99%E8%AF%AF%E7%A5%A8%E6%8D%AEc%2B%2B&spm=1018.2226.3001.4187
#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
void test1()
{
    int nums[100001]={0};//�ȳ�ʼ��Ϊ0
    int max=0,min=100001;
    int row;
    cin>>row;//��������
    int id;
    char c;
    //getchar();//������ȥ����rowʱ�Ļس�����ֹ��for�б�ʶ�� //getchar()���һ�������٣�������ȥ�س�
    for(int i=1;i<=row;)
    {
        c=getchar();//��ȡ���������,����ǻ��л��߿ո�����Ҫ����
        if(c>='0' && c<='9')
        {
            ungetc(c,stdin);//�ַ�c�ͻص��������У��������ݵ�������
            cin>>id;
            nums[id]++;
            if(id<min)min=id;
            if(id>max)max=id;//�ֱ��ҵ������Сֵ
        }
        else if(c=='\n')//������
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
	//�Զ��������,acm�ľ��� 
	while(cin >> x){a.push_back(x);}
	sort(a.begin(), a.end());
	int ans1, ans2;				//�ϵ������ֺ��ظ�������
	int num = a[0];				//��¼����Ӧ�õ�������Ϣ 
	for(int i = 0;i < a.size();i++){
		if(a[i] == num)	{num++;}
		else if(a[i] > num)	{ans1 = num;num += 2;}
		else {ans2 = a[i];} 
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
   