#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <iterator>
#include "../include/containers/vector.hpp"
#include "../include/containers/stack.hpp"


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
}

	// {
	// 	std::cout << "======== [ std::vector ] ========" << std::endl;
	// 	std::vector<int>	vec1;
	// 	std::vector<int>	vec2(3, 5);
	// 	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }
	// {
	// 	std::cout << "======== [ ft ] ========" << std::endl;
	// 	ft::vector<int>	vec1;
	// 	ft::vector<int> vec2(3, 5);
	// 	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }

// struct classcomp {
// 	bool operator () ( const char &lhs, const char &rhs) const
// 	{ return lhs > rhs; }
// };

// template < class T >
// void show_vector( std::vector<T> &vect ) {
// 	std::cout << "[Vect contains: ";
// 	for (size_t i = 0; i < vect.size(); i++ )
// 		std::cout << ' ' << vect[i];
// 	std::cout << ']' << std::endl << std::endl;
// }

// int main()
// {
// /**************** vector *****************/
// 	std::cout << "====== constructor ======" << std::endl;
// 	{
// 		std::vector<int> int_vect;

// 		std::cout << "Vector size: " << int_vect.size() << std::endl;
// 		std::cout << "Alloc size : " << int_vect.capacity() << std::endl;

// 	}

// 	std::cout << "=======================" << std::endl;
// 	{
// 		std::cout << "explicit vector (size_type n, const value_type& val = ;value_type(), const allocator_type& alloc = allocator_type())" << std::endl << std::endl;
// 		std::vector<int> int_vect( 5, 0, 1 );

// 		std::cout << "Vector size: " << int_vect.size() << std::endl;
// 		std::cout << "Alloc size : " << int_vect.capacity() << std::endl;
// 		show_vector( int_vect );
// 	}

// 	return 0;
// }

/*
#include <iostream>
#include <string>
#include <deque>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}*/
