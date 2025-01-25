#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void print_header(const std::string& text) {
    std::cout << "\n" << GREEN << "===== " << text << " =====" << RESET << "\n";
}

void vector_tests() {
    print_header("VECTOR TESTS");
    
    // Test 1: Find first element
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "1. Find first element (10): ";
        std::vector<int>::const_iterator it = easyfind(vec, 10);
        std::cout << "Found at index " << (it - vec.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 2: Find last element
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "2. Find last element (30): ";
        std::vector<int>::const_iterator it = easyfind(vec, 30);
        std::cout << "Found at index " << (it - vec.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 3: Find middle element
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "3. Find middle element (20): ";
        std::vector<int>::const_iterator it = easyfind(vec, 20);
        std::cout << "Found at index " << (it - vec.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 4: Find duplicate
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "4. Find first duplicate (20): ";
        std::vector<int>::const_iterator it = easyfind(vec, 20);
        std::cout << "Found at index " << (it - vec.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 5: Non-existent element
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::cout << "5. Find non-existent (40): ";
        easyfind(vec, 40);
        std::cerr << RED << "Error: Exception not thrown!" << RESET << "\n";
    } catch (const std::exception& e) {
        std::cout << "Correctly threw: " << e.what() << "\n";
    }

    // Test 6: Empty container
    try {
        std::vector<int> vec;
        std::cout << "6. Search empty container: ";
        easyfind(vec, 10);
        std::cerr << RED << "Error: Exception not thrown!" << RESET << "\n";
    } catch (const std::exception& e) {
        std::cout << "Correctly threw: " << e.what() << "\n";
    }
}

void list_tests() {
    print_header("LIST TESTS");
    
    // Test 1: Find first element
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "1. Find first element (1): ";
        std::list<int>::const_iterator it = easyfind(lst, 1);
        std::cout << "Found value " << *it << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 2: Find last element
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "2. Find last element (3): ";
        std::list<int>::const_iterator it = easyfind(lst, 3);
        std::cout << "Found value " << *it << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 3: Find middle element
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "3. Find middle element (2): ";
        std::list<int>::const_iterator it = easyfind(lst, 2);
        std::cout << "Found value " << *it << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 4: Find duplicate
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "4. Find first duplicate (2): ";
        std::list<int>::const_iterator it = easyfind(lst, 2);
        std::cout << "Found value " << *it << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 5: Non-existent element
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "5. Find non-existent (4): ";
        easyfind(lst, 4);
        std::cerr << RED << "Error: Exception not thrown!" << RESET << "\n";
    } catch (const std::exception& e) {
        std::cout << "Correctly threw: " << e.what() << "\n";
    }
}

void deque_tests() {
    print_header("DEQUE TESTS");
    
    // Test 1: Find existing element
    try {
        std::deque<int> dq;
        dq.push_back(100);
        dq.push_back(200);
        dq.push_back(300);
        std::cout << "1. Find middle element (200): ";
        std::deque<int>::const_iterator it = easyfind(dq, 200);
        std::cout << "Found at index " << (it - dq.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 2: Find in modified deque
    try {
        std::deque<int> dq;
        dq.push_back(5);
        dq.push_back(10);
        dq.push_back(15);
        dq.push_back(20);
        std::cout << "2. Find element (15): ";
        std::deque<int>::const_iterator it = easyfind(dq, 15);
        std::cout << "Found at index " << (it - dq.begin()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << "\n";
    }

    // Test 3: Non-existent element
    try {
        std::deque<int> dq;
        dq.push_back(100);
        dq.push_back(200);
        std::cout << "3. Find non-existent (300): ";
        easyfind(dq, 300);
        std::cerr << RED << "Error: Exception not thrown!" << RESET << "\n";
    } catch (const std::exception& e) {
        std::cout << "Correctly threw: " << e.what() << "\n";
    }

    // Test 4: Empty deque
    try {
        std::deque<int> dq;
        std::cout << "4. Search empty deque: ";
        easyfind(dq, 42);
        std::cerr << RED << "Error: Exception not thrown!" << RESET << "\n";
    } catch (const std::exception& e) {
        std::cout << "Correctly threw: " << e.what() << "\n";
    }
}

int main() {
    vector_tests();
    list_tests();
    deque_tests();
    return 0;
}