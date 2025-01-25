#include "Span.hpp"

Span::Span() : _N(0)
{

};


Span::Span(unsigned int N) : _N(N)
{

};


Span::~Span()
{

};


Span::Span(const Span   &other) : _N(other._N), _numbers(other._numbers)
{
};


Span&    Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_numbers = other._numbers;
    };
    return *this;
};


void    Span::addNumber(int num)
{
    if (_numbers.size() >= _N)
        throw  std::runtime_error("Cannot add more elements to Span!");
    
    _numbers.push_back(num);

};

int     Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw  std::runtime_error("Span is empty. Cannot find shortest/longest span");
    
    
    std::sort(_numbers.begin(), _numbers.end());
    //shortest span must be obtained from two neighbours in sorted list

    int shortest_span = _numbers.back() - _numbers.front(); //assign  longest span initially (max - min)
    
    for (long unsigned int i = 1; i < _numbers.size(); i++)
    {
        if ((_numbers[i] - _numbers[i - 1]) <= shortest_span)
            //new shortest span
            shortest_span = (_numbers[i] - _numbers[i - 1]);

    };

    return shortest_span;
};


int     Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw  std::runtime_error("Span is empty. Cannot find shortest/longest span");
    
    std::sort(_numbers.begin(), _numbers.end());


    return (_numbers.back() - _numbers.front()); //longest span because list is sorted in ascending order

}