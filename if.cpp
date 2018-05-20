#include <iostream>
/*
 *  1.4.4节：if语句
 *  统计输入数列中连续数字出现的次数
 */

int main()
{
	int currVal = 0, val = 0;
	if(std::cin >> currVal)
	{
		int cnt = 1;
		while(std::cin >> val)
		{
			if(val == currVal)
			{
				++cnt;
			}
			else
			{
				std::cout << currVal << "出现了" << cnt << "次" << std::endl;
				currVal = val;
				cnt = 1; 
			}
		}
		std::cout << currVal << "出现了" << cnt << "次" << std::endl; 
	}
	return 0;
}
