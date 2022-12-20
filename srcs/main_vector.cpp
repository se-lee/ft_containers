#include <iostream>
#include <vector>
#include "vector.hpp"

template <typename T>
void	displayVect(ft::vector<T> vect, std::string name)
{
	std::cout << name << " = ";
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
	ft::vector<int> vect1;
	displayVect(vect1, "vect1");
	std::cout	<< "vect1 size = " << vect1.size()
				<< " vect1 capacity = " << vect1.capacity()
				<< " vect1 max_size = " << vect1.max_size() << std::endl;
	std::cout << std::endl;
	
	ft::vector<int> vect2(4, 101);
	displayVect(vect2, "vect2");
	std::cout	<< "vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

	//PUSHBACKS
	vect2.push_back(12);
	displayVect(vect2, "vect2");
	std::cout	<< "vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

	//RESIZE
	vect2.resize(2);
	displayVect(vect2, "vect2");
	std::cout	<< "vect2 size = " << vect2.size()
				<< " vect2 capacity = " << vect2.capacity()
				<< " vect2 max_size = " << vect2.max_size() << std::endl;
	std::cout << std::endl;

	//CONSTRUCTOR BY COPY
	ft::vector<int> vect3(vect2);
	displayVect(vect3, "vect3");
	std::cout	<< "vect3 size = " << vect3.size()
				<< " vect3 capacity = " << vect3.capacity()
				<< " vect3 max_size = " << vect3.max_size() << std::endl;
	std::cout << std::endl;

	//INSERT
	vect3.insert(vect3.begin(), 42);
	displayVect(vect3, "vect3");
	std::cout	<< "vect3 size = " << vect3.size()
				<< " vect3 capacity = " << vect3.capacity()
				<< " vect3 max_size = " << vect3.max_size() << std::endl;
	std::cout << std::endl;

	//CONSTRUCTOR
	ft::vector<int> vect4(10, 42);
	displayVect(vect4, "vect4");
	std::cout	<< "vect4 size = " << vect4.size()
				<< " vect4 capacity = " << vect4.capacity()
				<< " vect4 max_size = " << vect4.max_size() << std::endl;
	std::cout << std::endl;

	//ASSIGN
	vect4.assign(5, 84);
	displayVect(vect4, "vect4");
	std::cout	<< "vect4 size = " << vect4.size()
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
	vect5.erase(vect5.begin() + 2);
	displayVect(vect5, "vect5");
	std::cout	<< "vect5 size = " << vect5.size()
				<< " vect5 capacity = " << vect5.capacity()
				<< " vect5 max_size = " << vect5.max_size() << std::endl;
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
	const ft::vector<int> vect6(10, 20);
	std::cout << "Const test" << std::endl;
	for (ft::vector<int>::const_iterator const_it = vect6.begin(); const_it != vect6.end(); const_it++)
	{
		// *const_it = 5;
		std::cout << *const_it << " ";
	}
	std::cout << std::endl;
}