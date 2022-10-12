// #include <iostream>
// #include <string>
// #include <deque>

// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096


#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <iterator>
#include "include/vector.hpp"

void	display_vector_elements(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	display_ft_vector_elements(ft::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}


int main()
{
	{
		std::cout << "======== [ std::vector ] ========" << std::endl;
		std::vector<int> foo (3, 100); // three '100's
		std::vector<int> bar (2, 200); // two '200's

		if (foo == bar) std::cout << "foo == bar \n";
		if (foo != bar) std::cout << "foo != bar \n";
		if (foo < bar) std::cout << "foo < bar \n";
		if (foo <= bar) std::cout << "foo <= bar \n";
		if (foo > bar) std::cout << "foo > bar \n";
		if (foo >= bar) std::cout << "foo >= bar \n"; 

	}
	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::vector<int> foo (3, 100); // three '100's
		ft::vector<int> bar (2, 200); // two '200's

		if (foo == bar) std::cout << "foo == bar \n";
		if (foo != bar) std::cout << "foo != bar \n";
		if (foo < bar) std::cout << "foo < bar \n";
		if (foo <= bar) std::cout << "foo <= bar \n";
		if (foo > bar) std::cout << "foo > bar \n";
		if (foo >= bar) std::cout << "foo >= bar \n"; 

	}
	return 0;
}
