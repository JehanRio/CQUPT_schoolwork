/*某电视台举办了低碳生活大奖赛。题目的计分规则相当奇怪：每位选手需要回答10个问题（其编号为1到10），越后面越有难度。
答对的，当前分数翻倍；答错了则扣掉与题号相同的分数（选手必须回答问题，不回答按错误处理）。
每位选手的起步分都是10分，某获胜选手最终得分刚好是100分，如果不让你看比赛过程，你能推断出他（她）哪个题目答对了，哪个题目答错了吗？
果把答对的记为1，答错的记为0，则10个题目的回答情况可用仅含1和0的串来表示，如0010110011就是可能的情况。
你的任务是算出所有可能情况，每个答案占一行。
*/
//递归算法：考虑好递归的终止条件即可
//回溯算法模板
#include<iostream>
using namespace std;
int nums[11]={0};
void solve(int grade,int index)//当前成绩与当前题目的分数
{
    if(index>11)//临界条件判断
    {
        return;
    }
    if(grade==100 && index==11)//分数达到100 且到11题
    {
        for(int i=1;i<=10;i++)
        {
            cout<<nums[i];
        }
        cout<<endl;
        return;
    }
    nums[index]=0;//先令当前题目做错
    solve(grade-index,index+1);
    nums[index]=1;//撤销，令其做对
    solve(grade*2,index+1);
}
int main()
{
    solve(10,1);
    return 0;
}