#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator :
	{
	
		public: 

			typedef Iterator 	iterator_type;
			typedef iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef iterator_traits<Iterator>::value_type			value_type;
			typedef iterator_traits<Iterator>::difference_type		difference_type;
			typedef iterator_traits<Iterator>::pointer				pointer;
			typedef iterator_traits<Iterator>::reference			reference;
		
		/* --- Constructors --- */	
			/* default */
			reverse_iterator();
			
			/* initialization */
			explicit reverse_iterator(iterator_type it);

			/* copy */
			template <class Iterator>
			reverse_iterator (const reverse_iterator<Iterator> &rev_it);

			
		private:

	};

}

#endif
