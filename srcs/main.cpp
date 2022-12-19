#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <iterator>
#include <utility>
#include <string>
#include "../include/containers/vector.hpp"
#include "../include/containers/stack.hpp"
#include "../include/containers/map.hpp"

void	print_map(std::string_view comment, const std::map<std::string, int> &m)
{
	std::cout << comment;
	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
		std::cout << '[' << it->first << "] = " << it->second << "; ";
	
	std::cout << std::endl;
}

void	print_ft_map(std::string_view comment, ft::map<char, int> &m)
{
	std::cout << comment;
	for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << '[' << it->first << "] = " << it->second << "; ";
		// it->_value.first << "] = " << it->_value.second << "; "
	std::cout << std::endl;
}


int main()
{

	{
		std::cout << "======== [ std::map ] ========" << std::endl;
		std::map<int, char> mymap;

		// mymap.insert(std::make_pair<char, int>('a', 10)); //Insert Simple Values
		// mymap.insert(std::make_pair<char, int>('b', 20));
		// mymap.insert(std::make_pair<char, int>('c', 30));
		// mymap.insert(std::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
		// mymap.insert(std::make_pair<char, int>('1', 100));
		// mymap.insert(std::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
		// mymap.insert(std::make_pair<char, int>('e', 30));

		mymap.insert(std::make_pair(8, 'a'));
		mymap.insert(std::make_pair(3, 'c'));
		mymap.insert(std::make_pair(1, 'd'));
		mymap.insert(std::make_pair(6, 'e'));
		mymap.insert(std::make_pair(4, 'f'));
		mymap.insert(std::make_pair(7, 'g'));
		mymap.insert(std::make_pair(13, 'i'));
		mymap.insert(std::make_pair(10, 'b'));
		mymap.insert(std::make_pair(14, 'h'));
		mymap.insert(mymap.end(), std::make_pair(2, 'a'));
		mymap.insert(mymap.find(14), std::make_pair(0, 'd'));
		mymap.insert(mymap.find(3), std::make_pair(13, 'd'));
		mymap.insert(mymap.find(7), std::make_pair(12, 'd'));
		
		std::map<int, char>::iterator  it;
		it = mymap.insert(mymap.begin(), std::make_pair(15, 'a'));

		std::cout << "Every node, from first to last:" << std::endl;
		for (std::map<int, char>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works;
		std::cout << std::endl;
		std::cout << "size: " << mymap.size() << std::endl;
		std::cout << "max: " << mymap.max_size() << std::endl;


		std::map<int, char>::reverse_iterator rit = mymap.rbegin();
		std::cout << "rbegin(): " << rit->first << std::endl;
		for (std::map<int, char>::reverse_iterator rite = mymap.rbegin(); rite != mymap.rend(); ++rite)
			std::cout << rite->first << " | ";
		std::cout << std::endl;
		
	}
	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::map<int, char> mymap;

		mymap.insert(ft::make_pair(8, 'a'));
		mymap.insert(ft::make_pair(3, 'c'));
		mymap.insert(ft::make_pair(1, 'd'));
		mymap.insert(ft::make_pair(6, 'f'));
		mymap.insert(ft::make_pair(4, 'g'));
		mymap.insert(ft::make_pair(7, 'i'));
		mymap.insert(ft::make_pair(13, 'b'));
		mymap.insert(ft::make_pair(10, 'h'));
		mymap.insert(ft::make_pair(14, 'h'));
		mymap.insert(mymap.end(), ft::make_pair(2, 'a'));
		mymap.insert(mymap.find(14), ft::make_pair(0, 'd'));
		mymap.insert(mymap.find(3), ft::make_pair(13, 'd'));
		mymap.insert(mymap.find(7), ft::make_pair(12, 'd'));
		
		ft::map<int, char>::iterator  it = mymap.insert(mymap.begin(), ft::make_pair(15, 'a'));

		// mymap.printTree();

		std::cout << "Every node, from first to last:" << std::endl;
		for (ft::map<int, char>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works
		}
		std::cout << std::endl;
		std::cout << "size: " << mymap.size() << std::endl;
		std::cout << "max: " << mymap.max_size() << std::endl;

		ft::map<int, char>::reverse_iterator rit = mymap.rbegin();
		std::cout << "rbegin(): " << rit->first << std::endl;
		for (ft::map<int, char>::reverse_iterator rite = mymap.rbegin(); rite != mymap.rend(); ++rite)
			std::cout << rite->first << " | ";
		std::cout << std::endl;

	}

	return 0;
}
