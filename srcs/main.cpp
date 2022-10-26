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
#include "../include/utils/pair.hpp"


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

		m["CPU"] = 25;
		m["SSD"] = 30;
		print_map("2) Updated map: ", m);

		std::cout << "3) m[UPS] = " << m["UPS"] << std::endl;
		print_map("4) Updated map: ", m);

		m.erase("GPU");
		print_map("5) After erase: ", m);


	}
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
