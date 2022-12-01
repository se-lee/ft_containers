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

	std::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);
	
	displayStdVect(myvector, "1) ");
	std::cout	<< "std::vect1 size = " << myvector.size()
				<< " vect1 capacity = " << myvector.capacity()
				<< " vect1 max_size = " << myvector.max_size() << std::endl;
	myvector.erase(myvector.begin() + 2, myvector.begin() + 5);
	displayStdVect(myvector, "2) ");
		std::cout	<< "std::vect1 size = " << myvector.size()
				<< " vect1 capacity = " << myvector.capacity()
				<< " vect1 max_size = " << myvector.max_size() << std::endl;

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
	displayStdVect(std_vect3, "vect3");
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
	displayStdVect(std_vect4, "vect4");
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
	displayStdVect(std_vect4, "vect4");
	displayVect(vect4, "vect4");
	std::cout	<< "std::vect4 size = " << std_vect4.size()
				<< " vect4 capacity = " << std_vect4.capacity()
				<< " vect4 max_size = " << std_vect4.max_size() << std::endl;
	std::cout	<< "ft:: vect4 size = " << vect4.size()
				<< " vect4 capacity = " << vect4.capacity()
				<< " vect4 max_size = " << vect4.max_size() << std::endl;
	std::cout << std::endl;

	//ITERATORS
	std::cout << "[ Iterators ]" << std::endl;
	std::vector<int> std_vect5;
	std_vect5.push_back(1);
	std_vect5.push_back(2);
	std_vect5.push_back(3);
	std_vect5.push_back(4);
	std_vect5.push_back(5);
	std::cout << "---- std ----" << std::endl;
	std::reverse_iterator<std::vector<int>::iterator> std_rev_it(std_vect5.end());
	std::cout	<< "rev_it[3] = " << std_rev_it[3] << std::endl;
	std::cout	<< "rev_it = " << *std_rev_it << std::endl;
	std_rev_it += 2;
	std::cout	<< "rev_it += 2" << std::endl << "rev_it = " << *std_rev_it << std::endl;
	std_rev_it--;
	std::cout	<< "rev_it--" << std::endl << "rev_it = " << *std_rev_it << std::endl;
	std::cout << std::endl;


	ft::vector<int> vect5;
	vect5.push_back(1);
	vect5.push_back(2);
	vect5.push_back(3);
	vect5.push_back(4);
	vect5.push_back(5);
	std::cout << "---- ft ----" << std::endl;
	ft::reverse_iterator<ft::vector<int>::iterator> rev_it(vect5.end());
	std::cout	<< "rev_it[3] = " << rev_it[3] << std::endl;
	std::cout	<< "rev_it = " << *rev_it << std::endl;
	rev_it += 2;
	std::cout	<< "rev_it += 2" << std::endl << "rev_it = " << *rev_it << std::endl;
	rev_it--;
	std::cout	<< "rev_it--" << std::endl << "rev_it = " << *rev_it << std::endl;
	std::cout << std::endl;

	//POP_BACK
	std::cout << "[ Pop back ]" << std::endl;
	std_vect5.pop_back();
	vect5.pop_back();
	displayStdVect(std_vect5, "vect5");
	displayVect(vect5, "vect5");
	std::cout	<< "std::vect5 size = " << std_vect5.size()
				<< " vect5 capacity = " << std_vect5.capacity()
				<< " vect5 max_size = " << std_vect5.max_size() << std::endl;
	std::cout	<< "ft:: vect5 size = " << vect5.size()
				<< " vect5 capacity = " << vect5.capacity()
				<< " vect5 max_size = " << vect5.max_size() << std::endl;
	std::cout << std::endl;

	//ERASE
	std::cout << "[ Erase ]" << std::endl;
	std::vector<int> std_vect6;
	ft::vector<int> vect6;
	for (int i = 0; i < 10; i++)
	{
		std_vect6.push_back(i);
		vect6.push_back(i);
	}

	// std_vect5.erase(std_vect5.begin() + );
	std_vect6.erase(std_vect6.begin() + 2, std_vect6.begin() + 4);
	vect6.erase(vect6.begin() + 2, vect6.begin() + 4);
	displayStdVect(std_vect6, "vect6");
	displayVect(vect6, "vect6");
	std::cout	<< "std::vect6 size = " << std_vect6.size()
				<< " vect6 capacity = " << std_vect6.capacity()
				<< " vect6 max_size = " << std_vect6.max_size() << std::endl;
	std::cout	<< "ft:: vect5 size = " << vect6.size()
				<< " vect6 capacity = " << vect6.capacity()
				<< " vect6 max_size = " << vect6.max_size() << std::endl;
	std::cout << std::endl;

	//SWAP
	std::cout << "Before swap : " << std::endl;
	displayVect(vect4, "vect4");
	displayVect(vect5, "vect5");
	swap(vect5, vect4);
	std::cout << "After swap : " << std::endl;
	displayVect(vect4, "vect4");
	displayVect(vect5, "vect5");
	std::cout << std::endl;

	//CONST_ITERATORS
	const ft::vector<int> vect7(10, 20);
	std::cout << "Const test" << std::endl;
	for (ft::vector<int>::const_iterator const_it = vect7.begin(); const_it != vect7.end(); const_it++)
	{
		// *const_it = 5;
		std::cout << *const_it << " ";
	}
	std::cout << std::endl;
}


// void	display_vector_elements(std::vector<int> vec)
// {
// 	// for (size_t i = 0; i < vec.size(); i++)
// 	// 	std::cout << vec[i] << ' ';
// 	// std::cout << std::endl;

// 	for (std::vector<int>::iterator iter = vec.begin();
// 		iter != vec.end(); iter++)
// 			std::cout << *iter << ' ';
// 	std::cout << std::endl;
	
// }

// void	display_ft_vector_elements(ft::vector<int> vec)
// {
// 	for (size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << ' ';
// 	std::cout << std::endl;

// 	// for (ft::vector<int>::iterator iter = vec.begin();
// 	// 	iter != vec.end(); iter++)
// 	// 		std::cout << *iter << ' ';
// 	// std::cout << std::endl;
// }

// int main()
// {
// 	{
// 		std::cout << "======== [ std::vector ] ========" << std::endl;
// 		std::vector<int> foo (3, 100); // three '100's
// 		std::vector<int> bar (2, 200); // two '200's

// 		if (foo == bar) std::cout << "foo == bar \n";
// 		if (foo != bar) std::cout << "foo != bar \n";
// 		if (foo < bar) std::cout << "foo < bar \n";
// 		if (foo <= bar) std::cout << "foo <= bar \n";
// 		if (foo > bar) std::cout << "foo > bar \n";
// 		if (foo >= bar) std::cout << "foo >= bar \n"; 

// 	}
// 	{
// 		std::cout << "======== [ ft ] ========" << std::endl;
// 		ft::vector<int> foo (3, 100); // three '100's
// 		ft::vector<int> bar (2, 200); // two '200's

// 		if (foo == bar) std::cout << "foo == bar \n";
// 		if (foo != bar) std::cout << "foo != bar \n";
// 		if (foo < bar) std::cout << "foo < bar \n";
// 		if (foo <= bar) std::cout << "foo <= bar \n";
// 		if (foo > bar) std::cout << "foo > bar \n";
// 		if (foo >= bar) std::cout << "foo >= bar \n"; 
// 	}
// 	{
// 		std::cout << "======== [ std::vector ] ========" << std::endl;
// 		std::vector<int> foo(5, 10);
// 		display_vector_elements(foo);
// 		std::cout << "foo data: " << foo.data() << std::endl;

// 		std::cout <<  std::boolalpha;

// 	}
// 	{
// 		std::cout << "======== [ ft ] ========" << std::endl;
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
// 		std::cout <<  std::boolalpha;
// 	}
// 	return 0;
// }

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

/*

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

*/