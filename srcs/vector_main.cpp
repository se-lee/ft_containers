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
#include "../include/containers/vector.hpp"


void	display_vector_elements(std::vector<int> vec)
{
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << ' ';
	// std::cout << std::endl;

	for (std::vector<int>::iterator iter = vec.begin();
		iter != vec.end(); iter++)
			std::cout << *iter << ' ';
	std::cout << std::endl;
	
}

void	display_ft_vector_elements(ft::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;

	// for (ft::vector<int>::iterator iter = vec.begin();
	// 	iter != vec.end(); iter++)
	// 		std::cout << *iter << ' ';
	// std::cout << std::endl;
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
	{
		std::cout << "======== [ std::vector ] ========" << std::endl;
		std::vector<int> foo(5, 10);
		display_vector_elements(foo);
		std::cout << "foo data: " << foo.data() << std::endl;

		std::cout <<  std::boolalpha;

	}
	{
		std::cout << "======== [ ft ] ========" << std::endl;
		// ft::vector<int> foo(5, 10);
		// for (size_t i = 0; i < foo.size(); i++)
		// 	std::cout << foo[i] << ' ';
		// std::cout << std::endl;
		// std::cout << "foo cap: " << foo.capacity() << std::endl;		
		// foo.reserve(1);
		// for (size_t i = 0; i < foo.size(); i++)
		// 	std::cout << foo[i] << ' ';
		// std::cout << std::endl;
		// std::cout << "foo cap: " << foo.capacity() << std::endl;
		// foo.resize(10, 1);
		// for (size_t i = 0; i < foo.size(); i++)
		// 	std::cout << foo[i] << ' ';
		// std::cout << std::endl;
		// std::cout << "foo cap: " << foo.capacity() << std::endl;
		// std::cout << "foo siz: " << foo.size() << std::endl;
	
		// foo.resize(10);
		// for (size_t i = 0; i < foo.size(); i++)
		// 	std::cout << foo[i] << ' ';
		// std::cout << std::endl;		
		std::cout <<  std::boolalpha;
	}
	return 0;
}

/*

template <typename T>
void	display_vector_elements(std::vector<T> vec)
{
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << ' ';
	// std::cout << std::endl;

	for (typename std::vector<T>::iterator iter = vec.begin();
		iter != vec.end(); iter++)
			std::cout << *iter << ' ';
	std::cout << std::endl;
	
}

template<typename T>
void	display_ft_vector_elements(ft::vector<T> ftVec)
{
	// for (size_t i = 0; i < ftVec.size(); i++)
	// 	std::cout << ftVec[i] << ' ';
	// std::cout << std::endl;

	for (typename ft::vector<T>::iterator iter = ftVec.begin();
		iter != ftVec.end(); iter++)
			std::cout << *iter << ' ';
	std::cout << std::endl;
};


int main()
{
	{
		std::cout << "======== [ std::vector ] ========" << std::endl;
		std::vector<int> foo(3, 2);
		std::vector<int> bar(4, 5);
		std::cout << "[foo] : ";
		display_vector_elements(foo);
		std::cout << "foo size: " << foo.size() << " | cap: " << foo.capacity() << std::endl;
		std::cout << "[bar] : ";
		display_vector_elements(bar);
		std::cout << "bar size: " << bar.size() << " | cap: " << bar.capacity() << std::endl;

		std::cout << " --- swap --- " << std::endl;
		std::swap(foo, bar);
		std::cout << "[foo] : ";
		display_vector_elements(foo);
		std::cout << "foo size: " << foo.size() << " | cap: " << foo.capacity() << std::endl;
		std::cout << "[bar] : ";
		display_vector_elements(bar);
		std::cout << "bar size: " << bar.size() << " | cap: " << bar.capacity() << std::endl;



	}
	{
		std::cout << "======== [ ft ] ========" << std::endl;
		ft::vector<int> foo(3, 2);
		ft::vector<int> bar(4, 5);
		std::cout << "[foo] : ";
		for (ft::vector<int>::iterator iter = foo.begin(); iter != foo.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << std::endl;
		std::cout << "foo size: " << foo.size() << " | cap: " << foo.capacity() << std::endl;
		std::cout << "[bar] : ";
		for (ft::vector<int>::iterator iter = bar.begin(); iter != bar.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << std::endl;	
		std::cout << "bar size: " << bar.size() << " | cap: " << bar.capacity() << std::endl;
		
		std::cout << " --- swap --- " << std::endl;
		ft::swap(foo, bar);
		std::cout << "[foo] : ";
		for (ft::vector<int>::iterator iter = foo.begin(); iter != foo.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << std::endl;
		std::cout << "foo size: " << foo.size() << " | cap: " << foo.capacity() << std::endl;
		std::cout << "[bar] : ";
		for (ft::vector<int>::iterator iter = bar.begin(); iter != bar.end(); iter++)
			std::cout << *iter << ' ';
		std::cout << std::endl;	
		std::cout << "bar size: " << bar.size() << " | cap: " << bar.capacity() << std::endl;
	}
	return 0;

*/
