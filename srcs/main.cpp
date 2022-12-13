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
	// {
	// 	std::cout << "======== [ std::map ] ========" << std::endl;
	// 	std::map<char, int> mymap;

	// 	// mymap.insert(std::make_pair<char, int>('a', 10)); //Insert Simple Values
	// 	// mymap.insert(std::make_pair<char, int>('b', 20));
	// 	// mymap.insert(std::make_pair<char, int>('c', 30));
	// 	// mymap.insert(std::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
	// 	// mymap.insert(std::make_pair<char, int>('1', 100));
	// 	// mymap.insert(std::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
	// 	// mymap.insert(std::make_pair<char, int>('e', 30));

	// 	mymap.insert(std::make_pair(8, 'a'));
	// 	mymap.insert(std::make_pair(3, 'c'));
	// 	mymap.insert(std::make_pair(1, 'd'));
	// 	mymap.insert(std::make_pair(6, 'e'));
	// 	mymap.insert(std::make_pair(4, 'f'));
	// 	mymap.insert(std::make_pair(7, 'g'));
	// 	mymap.insert(std::make_pair(13, 'i'));
	// 	mymap.insert(std::make_pair(10, 'b'));
	// 	mymap.insert(std::make_pair(14, 'h'));


	// 	std::cout << "Every node, from first to last:" << std::endl;
	// 	for (std::map<char, int>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
	// 		std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works;
	// 	std::cout << std::endl;
	// 	std::cout << "size: " << mymap.size() << std::endl;
	// 	std::cout << "max: " << mymap.max_size() << std::endl;
		
	// 	std::map<char, int>::iterator lower = mymap.lower_bound('b');
	// 	if (lower != mymap.end()) 
	// 		{ std::cout << "lower: " << lower->first << std::endl; } 
	// 	else 
	// 		{ std::cout << "it == end" << std::endl; }

	// 	// std::cout << "lower bound: " << lower->first << std::endl;
	// 	// std::map<char, int>::iterator upper = mymap.upper_bound('b');
	// 	// std::cout << "upper bound: " << upper->first << std::endl;


	// 	// std::cout << "Every node, from last to first:" << std::endl;
	// 	// for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
	// 	// {
	// 	// 	std::cout << it->first << "=>" << it->second << std::endl;
	// 	// }
	// 	// std::cout << std::endl;
		
	// }

	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::map<int, char> mymap;

		// mymap.insert(ft::make_pair<char, int>('a', 10)); //Insert Simple Values
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('b', 20));
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('c', 30));
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('1', 100));
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
		// // mymap.printTree();
		// mymap.insert(ft::make_pair<char, int>('e', 30));
		// // mymap.printTree();

		// ft::map<char,int>::iterator it = mymap.begin();
		// mymap.insert(it, ft::make_pair<char, int>('f',300));  // max efficiency inserting
		// mymap.insert(it, ft::make_pair<char, int>('2',400)); 

		mymap.insert(ft::make_pair(8, 'a'));
		mymap.insert(ft::make_pair(3, 'c'));
		mymap.insert(ft::make_pair(1, 'd'));
		mymap.insert(ft::make_pair(6, 'e'));
		mymap.insert(ft::make_pair(4, 'f'));
		mymap.insert(ft::make_pair(7, 'g'));
		mymap.insert(ft::make_pair(13, 'i'));
		mymap.insert(ft::make_pair(10, 'b'));
		mymap.insert(ft::make_pair(14, 'h'));
		mymap.insert(ft::make_pair(17, 'h'));
		mymap.insert(ft::make_pair(20, 'h'));
		mymap.insert(ft::make_pair(25, 'h'));


		mymap.printTree();


		// std::cout << "Every node, from first to last:" << std::endl;
		// for (ft::map<int, char>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
		// {
		// 	std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works
		// }
		// std::cout << std::endl;

		// std::cout << "size: " << mymap.size() << std::endl;
		// std::cout << "max: " << mymap.max_size() << std::endl;


		// ft::map<char, int>::iterator lower = mymap.lower_bound('b');
		// if (lower != mymap.end()) 
		// 	{ std::cout << "lower: " << lower->first << std::endl; } 
		// else 
		// 	{ std::cout << "it == end" << std::endl; }


		// ft::map<char, int>::iterator lower = mymap.lower_bound('b');
		// std::cout << "lower bound: " << lower->first << std::endl;
		// ft::map<char, int>::iterator upper = mymap.upper_bound('b');
		// std::cout << "upper bound: " << upper->first << std::endl;


		// std::cout << std::endl;
		// mymap.printTree();
		// std::cout << "Every node, from last to first:" << std::endl;
		// for (ft::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
		// {
		// 	std::cout << it->first << "=>" << it->second << std::endl;
		// }
		// std::cout << std::endl;
	}
	return 0;
}
