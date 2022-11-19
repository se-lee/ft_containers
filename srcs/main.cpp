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

// void	print_ft_map(std::string_view comment, ft::map<char, int> &m)
// {
// 	std::cout << comment;
// 	for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); ++it)
// 		std::cout << '[' << it->first << "] = " << it->second << "; ";
// 		// it->_value.first << "] = " << it->_value.second << "; "
// 	std::cout << std::endl;
// }


int main()
{
	{
		std::cout << "======== [ std::map ] ========" << std::endl;

		// std::map<std::string, int> m;
		// // {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
		// m.insert(std::make_pair("CPU", 10));
		// m.insert(std::make_pair("GPU", 15));
		// m.insert(std::make_pair("RAM", 20));

		// print_map("1) Initial map: " , m);

		// // m["CPU"] = 25;
		// m["SSD"] = 30;
		// print_map("2) Updated map: ", m);

		// std::cout << "3) m[UPS] = " << m["UPS"] << std::endl;
		// print_map("4) Updated map: ", m);


		// std::map<std::string, int>::iterator it;
		// it = m.begin();
		// std::cout << "map::begin: " << it->first << " | " << it->second << std::endl;

		// m.insert(std::make_pair("CP", 10));
		// print_map("4) Updated map: ", m);

		// m.insert(std::make_pair("AB", 100));
		// print_map("5) Updated map: ", m);
		std::map<char, int> mymap;

		mymap.insert(std::make_pair<char, int>('a', 10)); //Insert Simple Values
		mymap.insert(std::make_pair<char, int>('b', 20));
		mymap.insert(std::make_pair<char, int>('c', 30));
		mymap.insert(std::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
		mymap.insert(std::make_pair<char, int>('1', 100));
		mymap.insert(std::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
		mymap.insert(std::make_pair<char, int>('e', 30));

		std::cout << "Every node, from first to last:" << std::endl;
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works;
		std::cout << std::endl;
		// std::cout << "Every node, from last to first:" << std::endl;
		// for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
		// {
		// 	std::cout << it->first << "=>" << it->second << std::endl;
		// }
		// std::cout << std::endl;
		
	}

	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::map<char, int> mymap;

		mymap.insert(ft::make_pair<char, int>('a', 10)); //Insert Simple Values
		mymap.insert(ft::make_pair<char, int>('b', 20));
		mymap.insert(ft::make_pair<char, int>('c', 30));
		mymap.insert(ft::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
		mymap.insert(ft::make_pair<char, int>('1', 100));
		mymap.insert(ft::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
		mymap.insert(ft::make_pair<char, int>('e', 30));

		std::cout << "Every node, from first to last:" << std::endl;
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works;
		
		}
		std::cout << std::endl;

		// std::cout << "Every node, from last to first:" << std::endl;
		// for (ft::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
		// {
		// 	std::cout << it->first << "=>" << it->second << std::endl;
		// }
		// std::cout << std::endl;
	}

	return 0;
}
