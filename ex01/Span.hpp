#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class Span
{
    private:
        unsigned int     _N;
        std::vector<int> _numbers;


    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span&other);


        void    addNumber(int num);

        template <typename Iterator>
        void addRange(Iterator start, Iterator end)
        {
            if (start > end)
                throw std::invalid_argument("Invalid range: start > end");

            // Calculate number of elements in range
            typename std::iterator_traits<Iterator>::difference_type d = std::distance(start, end);

            // Check capacity (cast to avoid signed/unsigned warnings)
            if (_numbers.size() + static_cast<size_t>(d) > _N)
                throw std::runtime_error("Provided range does not fit into Span. Out of Range!");

            _numbers.insert(_numbers.end(), start, end);
        };


        int    shortestSpan();
        int    longestSpan();

};

#endif
