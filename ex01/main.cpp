#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    // Test 1: Basic functionality
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Test 1: Basic Functionality" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: Edge cases (empty and single-element spans)
    try {
        Span spEmpty(0);
        std::cout << "\nTest 2a: Empty Span (Add Number)" << std::endl;
        spEmpty.addNumber(1); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " (Expected)" << std::endl;
    }

    try {
        Span spSingle(1);
        spSingle.addNumber(42);
        std::cout << "\nTest 2b: Single-Element Span (Shortest Span)" << std::endl;
        spSingle.shortestSpan(); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " (Expected)" << std::endl;
    }

    // Test 3: Large span (10,000 elements)
    try {
        Span spLarge(10000);
        std::vector<int> largeVec;
        for (int i = 0; i < 10000; ++i) {
            largeVec.push_back(i); // Fill with 0, 1, 2, ..., 9999
        }
        spLarge.addRange(largeVec.begin(), largeVec.end());

        std::cout << "\nTest 3: Large Span (10,000 Elements)" << std::endl;
        std::cout << "Shortest span: " << spLarge.shortestSpan() << " (Expected: 1)" << std::endl;
        std::cout << "Longest span: " << spLarge.longestSpan() << " (Expected: 9999)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 4: Add a range of elements (valid and invalid)
    try {
        Span spRange(5);
        std::vector<int> validRange;
        validRange.push_back(10);
        validRange.push_back(20);
        validRange.push_back(30);

        std::cout << "\nTest 4a: Add Valid Range" << std::endl;
        spRange.addRange(validRange.begin(), validRange.end());
        std::cout << "Shortest span: " << spRange.shortestSpan() << " (Expected: 10)" << std::endl;
        std::cout << "Longest span: " << spRange.longestSpan() << " (Expected: 20)" << std::endl;

        std::vector<int> invalidRange;
        invalidRange.push_back(40);
        invalidRange.push_back(50);
        invalidRange.push_back(60);

        std::cout << "\nTest 4b: Add Invalid Range (Overflow)" << std::endl;
        spRange.addRange(invalidRange.begin(), invalidRange.end()); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << " (Expected)" << std::endl;
    }

    // Test 5: All elements are the same
    try {
        Span spSame(5);
        spSame.addNumber(5);
        spSame.addNumber(5);
        spSame.addNumber(5);

        std::cout << "\nTest 5: All Elements Same" << std::endl;
        std::cout << "Shortest span: " << spSame.shortestSpan() << " (Expected: 0)" << std::endl;
        std::cout << "Longest span: " << spSame.longestSpan() << " (Expected: 0)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}