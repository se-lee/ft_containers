#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <iterator>

int main()
{
	int myints[] = {1,2,3,4,3,2};
	std::vector<int> v(myints, myints+5);

	//コンテナの中身が同じかどうか調べる
	bool result = std::equal(v.begin(), v.end(), myints);
	std::cout << std::boolalpha << result << std::endl;






	return 0;
}