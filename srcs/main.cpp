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


// int main()
// {
// 	{
// 		std::cout << "======== [ std::map ] ========" << std::endl;

// 		// std::map<std::string, int> m;
// 		// // {{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
// 		// m.insert(std::make_pair("CPU", 10));
// 		// m.insert(std::make_pair("GPU", 15));
// 		// m.insert(std::make_pair("RAM", 20));

// 		// print_map("1) Initial map: " , m);

// 		// // m["CPU"] = 25;
// 		// m["SSD"] = 30;
// 		// print_map("2) Updated map: ", m);

// 		// std::cout << "3) m[UPS] = " << m["UPS"] << std::endl;
// 		// print_map("4) Updated map: ", m);


// 		// std::map<std::string, int>::iterator it;
// 		// it = m.begin();
// 		// std::cout << "map::begin: " << it->first << " | " << it->second << std::endl;

// 		// m.insert(std::make_pair("CP", 10));
// 		// print_map("4) Updated map: ", m);

// 		// m.insert(std::make_pair("AB", 100));
// 		// print_map("5) Updated map: ", m);
// 		std::map<char, int> mymap;

// 		mymap.insert(std::make_pair<char, int>('a', 10)); //Insert Simple Values
// 		mymap.insert(std::make_pair<char, int>('b', 20));
// 		mymap.insert(std::make_pair<char, int>('c', 30));
// 		mymap.insert(std::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
// 		mymap.insert(std::make_pair<char, int>('1', 100));
// 		mymap.insert(std::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
// 		mymap.insert(std::make_pair<char, int>('e', 30));

// 		std::cout << "Every node, from first to last:" << std::endl;
// 		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
// 			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works;
// 		std::cout << std::endl;

// 		std::cout << "size: " << mymap.size() << std::endl;
// 		std::cout << "max: " << mymap.max_size() << std::endl;
// 		// std::cout << "Every node, from last to first:" << std::endl;
// 		// for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
// 		// {
// 		// 	std::cout << it->first << "=>" << it->second << std::endl;
// 		// }
// 		// std::cout << std::endl;
		
// 	}

// 	{
// 		std::cout << "======== [ ft ] ========" << std::endl;
// 		ft::map<char, int> mymap;

// 		mymap.insert(ft::make_pair<char, int>('a', 10)); //Insert Simple Values
// 		mymap.insert(ft::make_pair<char, int>('b', 20));
// 		mymap.insert(ft::make_pair<char, int>('c', 30));
// 		mymap.insert(ft::make_pair<char, int>('d', 3)); // Insert does sort by first ('d') and not (3)
// 		mymap.insert(ft::make_pair<char, int>('1', 100));
// 		mymap.insert(ft::make_pair<char, int>('a', 5)); //Doesn't insert as 'a' already exist
// 		mymap.insert(ft::make_pair<char, int>('e', 30));

// 		std::cout << "Every node, from first to last:" << std::endl;
// 		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
// 		{
// 			std::cout << it->first << "=>" << it->second << std::endl; // Shows that the map works
// 		}
// 		std::cout << std::endl;

// 		std::cout << "size: " << mymap.size() << std::endl;
// 		std::cout << "max: " << mymap.max_size() << std::endl;



// 		// std::cout << "Every node, from last to first:" << std::endl;
// 		// for (ft::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it)
// 		// {
// 		// 	std::cout << it->first << "=>" << it->second << std::endl;
// 		// }
// 		// std::cout << std::endl;
// 	}

// 	return 0;
// }

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

//VECTORS
int main()
{
	// CONSTRUCTORS
	std::cout << "[ Empty Constructor ]" << std::endl;
	std::vector<int> std_vect1;
	ft::vector<int> vect1;
	displayStdVect(std_vect1, "vect1");
	displayVect(vect1, "vect1");
	std::cout	<< "std::vect1 size = " << std_vect1.size()
				<< " vect1 capacity = " << std_vect1.capacity()
				<< " vect1 max_size = " << std_vect1.max_size() << std::endl;
	std::cout	<< "ft:: vect1 size = " << vect1.size()
				<< " vect1 capacity = " << vect1.capacity()
				<< " vect1 max_size = " << vect1.max_size() << std::endl;
	std::cout << std::endl;
	
	std::cout << "[ Fill Constructor ]" << std::endl;
	std::vector<int> std_vect2(4, 101);
	ft::vector<int> vect2(4, 101);
	displayStdVect(std_vect2, "vect2");
	displayVect(vect2, "vect2");
	std::cout	<< "std::vect2 size = " << std_vect2.size()
				<< " vect2 capacity = " << std_vect2.capacity()
				<< " vect2 max_size = " << std_vect2.max_size() << std::endl;
	std::cout	<< "ft:: vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

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

	//RESIZE
	std::cout << "[ Resize ]" << std::endl;
	std_vect2.resize(2);
	vect2.resize(2);
	displayStdVect(std_vect2, "vect2");
	displayVect(vect2, "vect2");
	std::cout	<< "std::vect2 size = " << std_vect2.size()
				<< " vect2 capacity = " << std_vect2.capacity()
				<< " vect2 max_size = " << std_vect2.max_size() << std::endl;
	std::cout	<< "ft:: vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

	// vect2.shrink_to_fit();
	// displayVect(vect2, "vect2");
	// std::cout	<< "vect2 size = " << vect2.size()
	// 			<< " vect2 capacity = " << vect2.capacity()
	// 			<< " vect2 max_size = " << vect2.max_size() << std::endl;
	// std::cout << std::endl;

	//CONSTRUCTOR BY COPY
	std::cout << "[ Copy Constructor ]" << std::endl;
	std::vector<int> std_vect3(std_vect2);
	ft::vector<int> vect3(vect2);
	displayVect(vect3, "vect3");
	std::cout	<< "std::vect3 size = " << std_vect3.size()
				<< " vect3 capacity = " << std_vect3.capacity()
				<< " vect3 max_size = " << std_vect3.max_size() << std::endl;
	std::cout	<< "ft:: vect3 size = " << vect3.size()
				<< " vect3 capacity = " << vect3.capacity()
				<< " vect3 max_size = " << vect3.max_size() << std::endl;
	std::cout << std::endl;

	//INSERT
	// vect3.insert(vect3.begin(), 42);   
	// displayVect(vect3, "vect3");
	// std::cout	<< "vect3 size = " << vect3.size()
	// 			<< " vect3 capacity = " << vect3.capacity()
	// 			<< " vect3 max_size = " << vect3.max_size() << std::endl;
	// std::cout << std::endl;

	//CONSTRUCTOR
	std::cout << "[ Fill Constructor ]" << std::endl;
	std::vector<int>std_vect4(10, 42);
	ft::vector<int> vect4(10, 42);
	displayVect(vect4, "vect4");
	std::cout	<< "std::vect4 size = " << std_vect4.size()
				<< " vect4 capacity = " << std_vect4.capacity()
				<< " vect4 max_size = " << std_vect4.max_size() << std::endl;
	std::cout	<< "ft:: vect4 size = " << vect4.size()
				<< " vect4 capacity = " << vect4.capacity()
				<< " vect4 max_size = " << vect4.max_size() << std::endl;
	std::cout << std::endl;

	//ASSIGN
	std::cout << "[ Assign ]" << std::endl;
	std_vect4.assign(5, 84);
	vect4.assign(5, 84);
	displayVect(vect4, "vect4");
	std::cout	<< "std::vect4 size = " << std_vect4.size()
				<< " vect4 capacity = " << std_vect4.capacity()
				<< " vect4 max_size = " << std_vect4.max_size() << std::endl;
	std::cout	<< "ft:: vect4 size = " << vect4.size()
				<< " vect4 capacity = " << vect4.capacity()
				<< " vect4 max_size = " << vect4.max_size() << std::endl;
	std::cout << std::endl;

	//ITERATORS
	ft::vector<int> vect5;
	vect5.push_back(1);
	vect5.push_back(2);
	vect5.push_back(3);
	vect5.push_back(4);
	vect5.push_back(5);
	ft::reverse_iterator<ft::vector<int>::iterator> rev_it(vect5.end());
	std::cout	<< "rev_it[3] = " << rev_it[3] << std::endl;
	std::cout	<< "rev_it = " << *rev_it << std::endl;
	rev_it += 2;
	std::cout	<< "rev_it += 2" << std::endl << "rev_it = " << *rev_it << std::endl;
	rev_it--;
	std::cout	<< "rev_it--" << std::endl << "rev_it = " << *rev_it << std::endl;
	std::cout << std::endl;

	//POP_BACK
	vect5.pop_back();
	displayVect(vect5, "vect5");
	std::cout	<< "vect5 size = " << vect5.size()
				<< " vect5 capacity = " << vect5.capacity()
				<< " vect5 max_size = " << vect5.max_size() << std::endl;
	std::cout << std::endl;

	//ERASE
	// vect5.erase(vect5.begin() + 2);
	// displayVect(vect5, "vect5");
	// std::cout	<< "vect5 size = " << vect5.size()
	// 			<< " vect5 capacity = " << vect5.capacity()
	// 			<< " vect5 max_size = " << vect5.max_size() << std::endl;
	// std::cout << std::endl;

	// //SWAP
	// std::cout << "Before swap : " << std::endl;
	// displayVect(vect4, "vect4");
	// displayVect(vect5, "vect5");
	// swap(vect5, vect4);
	// std::cout << "After swap : " << std::endl;
	// displayVect(vect4, "vect4");
	// displayVect(vect5, "vect5");
	// std::cout << std::endl;

	//CONST_ITERATORS
	const ft::vector<int> vect6(10, 20);
	std::cout << "Const test" << std::endl;
	for (ft::vector<int>::const_iterator const_it = vect6.begin(); const_it != vect6.end(); const_it++)
	{
		// *const_it = 5;
		std::cout << *const_it << " ";
	}
	std::cout << std::endl;
}