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


template<typename T>
void	displayStdVect(std::vector<T> vect, std::string name)
{
	std::cout << "std::" << name << " = ";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	displayVect(ft::vector<T> vect, std::string name)
{
	std::cout << "ft:: " << name << " = ";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{

	std::vector<int> std_vect2(4, 101);
	ft::vector<int> vect2(4, 101);

	//PUSHBACKS
	std::cout << "[ Push back ]" << std::endl;
	std_vect2.push_back(12);
	vect2.push_back(12);
	displayStdVect(std_vect2, "vect2");
	displayVect(vect2, "vect2");
	std::cout	<< "std::vect2 size = " << std_vect2.size()
				<< " vect2 capacity = " << std_vect2.capacity()
				<< " vect2 max_size = " << std_vect2.max_size() << std::endl;
	std::cout	<< "ft:: vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

	std::cout << "[ insert 1 ]" << std::endl;
	std::vector<int>::iterator it = std_vect2.begin() + 2;
	std_vect2.insert(it, 98);
	displayStdVect(std_vect2, "vect2");

	ft::vector<int>::iterator ft_it = vect2.begin() + 2;
	vect2.insert(ft_it, 98);
	displayVect(vect2, "vect2");
	std::cout	<< "std::vect2 size = " << std_vect2.size()
				<< " vect2 capacity = " << std_vect2.capacity()
				<< " vect2 max_size = " << std_vect2.max_size() << std::endl;
	std::cout	<< "ft:: vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;

	std::cout << std::endl;

	std::cout << "[ insert 2 ]" << std::endl;
	std::vector<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	std_vect2.insert(std_vect2.begin() + 2, x.begin(), x.end());
	displayStdVect(std_vect2, "vect2");

	ft::vector<int> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	vect2.insert(vect2.begin() + 2, y.begin(), y.end());
	displayVect(vect2, "vect2");
	std::cout	<< "std::vect2 size = " << std_vect2.size()
				<< " vect2 capacity = " << std_vect2.capacity()
				<< " vect2 max_size = " << std_vect2.max_size() << std::endl;
	std::cout	<< "ft:: vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;

	
}

/*
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
		std::cout << "size: " << mymap.size() << std::endl;
		std::cout << "max: " << mymap.max_size() << std::endl;
		
		std::map<char, int>::iterator lower = mymap.lower_bound('b');
		std::cout << "lower bound: " << lower->first << std::endl;
		std::map<char, int>::iterator upper = mymap.upper_bound('b');
		std::cout << "upper bound: " << upper->first << std::endl;


		std::map<char, int>::iterator = decltype(m)::iterator;
		std::pair<iterator, iterator> ret = m.equal_range("B");

		for (iterator it = ret.first; it != ret.second; ++it) {
			std::cout << it->first << "," << it->second << std::endl;

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
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('b', 20));
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('c', 30));
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('1', 100));
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
		// mymap.printTree();
		mymap.insert(ft::make_pair<char, int>('e', 30));
		// mymap.printTree();

		// ft::map<char,int>::iterator it = mymap.begin();
		// mymap.insert(it, ft::make_pair<char, int>('f',300));  // max efficiency inserting
		// mymap.insert(it, ft::make_pair<char, int>('2',400)); 

		mymap.printTree();


		std::cout << "Every node, from first to last:" << std::endl;
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		{
			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works
		}
		std::cout << std::endl;

		std::cout << "size: " << mymap.size() << std::endl;
		std::cout << "max: " << mymap.max_size() << std::endl;

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
*/
