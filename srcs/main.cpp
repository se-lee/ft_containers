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

void	print_ft_map(std::string_view comment, const ft::map<std::string, int> &m)
{
	std::cout << comment;
	for (ft::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << '[' << it->first << "] = " << it->second << "; ";

	std::cout << std::endl;
}


int main()
{
	{
		std::cout << "======== [ std::map ] ========" << std::endl;
		
		std::map<std::string, int> m;
		// {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
		m.insert(std::make_pair("CPU", 10));
		m.insert(std::make_pair("GPU", 15));
		m.insert(std::make_pair("RAM", 20));

		print_map("1) Initial map: " , m);

		// m["CPU"] = 25;
		m["SSD"] = 30;
		print_map("2) Updated map: ", m);

		std::cout << "3) m[UPS] = " << m["UPS"] << std::endl;
		print_map("4) Updated map: ", m);


		std::map<std::string, int>::iterator it;
		it = m.begin();
		std::cout << "map::begin: " << it->first << " | " << it->second << std::endl;

		m.insert(std::make_pair("CP", 10));
		print_map("4) Updated map: ", m);

		m.insert(std::make_pair("AB", 100));
		print_map("5) Updated map: ", m);
		
	}

	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::map<std::string, int> m;
		m.insert(ft::make_pair("CPU", 10));

	}

	return 0;
}
