//oiwiki Compress Words (hash's application) 1.5h
/*
1. 效率问题：查询太慢 (TLE)
解决： 预处理幂次数组 p[i] = B^i % M，查询时直接取 p[len]
2. 重复计算：每次二分都算一遍哈希
错误： 在 check 函数里反复调用 add_hash 计算整个新串。
解决： 对新串 add 预处理前缀哈希数组
3. 内存搬运：错误的字符串拼接
错误： ans = ans + ... 会频繁申请内存并拷贝
解决： 使用 push_back 逐字符拼接，并同步动态更新 ans 的哈希值。
4. 数学错误：负数取模
错误： hash1 - hash2 可能为负，C++ % 运算符会保留负号。
解决： 统一使用 (res % M + M) % M 确保结果为正。
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
string ans;
vector<LL>ha_table = { 0 };
const LL b = 133;
const LL m = 1e9 + 7;
//需要提前写好幂次表存起来
vector<LL> p = { 1 }; // 幂次表
void init_pow(int n) {
	for (int i = 1; i <= n; i++) p.push_back((p.back() * b) % m);
}
LL add_hash(string add)
{
	LL sum = 0;
	for (char i : add)
	{
		sum = ((sum % m) * (b % m) + i)%m;
	}
	return sum;
}
void ans_hash()
{
	
	if (!ans.empty())
	{
		int add = ans.size() - ha_table.size();
		for (int i = 0; i < add; i++)
		{
			LL now = (ha_table.back() * (b % m) + ans[ha_table.size() + i])%m;
			ha_table.push_back(now);
		}
	}
	else
	{

	}
}
LL get_hash(int left, int right)
{
	if (left > 1 && right < ans.size())
	{
		LL sum = ha_table[left - 1];
		for (int i = 0; i < right - left + 1; i++)
		{
			sum = (sum % m) * (b % m);
		}
		LL res = ha_table[right] - sum;
		return (res % m + m) % m;;
	}
	else
		return -1;
}
bool check(int len,string add)
{
	if (len > ans.size())
		return false;
	LL now_hash = add_hash(add);
	if (get_hash(ans.size() - len, len) == now_hash)
		return true;
	else
		return false;

}
int two_seperated(int left, int right,string add)
{
	int mid = (left + right) / 2;
	int res=0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid,add.substr(0,mid)))
		{
			left = mid + 1;
			res = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return res;
}
void add_string(string add)
{
	int len = two_seperated(0, add.size(), add);
	ans = ans+ add.substr(len);
	ans_hash();
}
int main()
{
	for (; 1;)
	{
		string add;
		cin >> add;
		add_string(add);
	}
}