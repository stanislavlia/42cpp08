#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <iterator>

template <typename T, typename Container = std::deque<T> > //use deque as underlying container for stack (supports pop() from head and tail)
class MutantStack : public std::stack<T, Container>
{

    public:
        //constructors
        MutantStack()
        {    
        }
        MutantStack(const MutantStack& other)
        {
            *this = other;    
        }
        MutantStack& operator=(const MutantStack& other)
        {
            if(this != other){}
            return *this;   
        }
        ~MutantStack(){}


        //define as typealias to abstract from the type of container
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;


        iterator begin()
        {
            return this->c.begin(); //c - instance of underlying container (dequeue)
        };

        iterator end()
        {
            return this->c.end();
        };
        
        const_iterator  cbegin() const
        {
            return this->c.cbegin();
        };

        const_iterator  cend() const
        {
            return this->c.cend();
        };

        reverse_iterator    rbegin()
        {
            return this->c.rbegin();
        };

        reverse_iterator    rend()
        {
            return this->c.rend();
        };
        
        const_reverse_iterator crbegin() const
        {
            return this->c.crbegin();
        };

        const_reverse_iterator crend() const
        {
            return this->c.crend();
        };
};

#endif