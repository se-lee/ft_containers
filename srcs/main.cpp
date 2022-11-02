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
// #include "../include/containers/map.hpp"


void	print_map(std::string_view comment, const std::map<std::string, int> &m)
{
	std::cout << comment;
	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
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


	// {
	// 	std::cout << "======== [ ft ] ========" << std::endl;
	// 	ft::pair<std::string, double> product1; //default constructor
	// 	ft::pair<std::string, double> product2("tomatoes", 2.30); //value init
	// 	ft::pair<std::string, double> product3(product2); //copy

	// 	product1 = ft::make_pair(std::string("lightbulbs"), 0.99); //using make_pair

	// 	product2.first = "shoes"; //the type of first is string
	// 	product2.second = 39.90; // the type of second is double

	// 	std::cout << "the price of " << product1.first << " is $" << product1.second << std::endl;
	// 	std::cout << "the price of " << product2.first << " is $" << product2.second << std::endl; 
	// 	std::cout << "the price of " << product3.first << " is $" << product3.second << std::endl; 
	// }

	}

	return 0;
}
