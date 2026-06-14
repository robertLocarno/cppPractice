#include<iostream>

#include "solution.h"
#include "../../utils/testUtils.h"

void test1() {
	std::cout << "Test 1" << std::endl;

	UnionFind unionFind(10);
	TestUtils::assertEqual("IsSame 1, 3", false, unionFind.isSameComponent(1, 3));
	TestUtils::assertEqual("Union 1, 2", true, unionFind._union(1, 2));
	TestUtils::assertEqual("Union 2, 3", true, unionFind._union(2, 3));
	TestUtils::assertEqual("NumComponents", 8, unionFind.getNumComponents());
	TestUtils::assertEqual("IsSame 1, 3", true, unionFind.isSameComponent(1, 3));
}

void test2() {
	std::cout << "Test 2" << std::endl;

	UnionFind unionFind(4);
	TestUtils::assertEqual("Union 0, 1", true, unionFind._union(0, 1));
	TestUtils::assertEqual("Union 2, 3", true, unionFind._union(2, 3));
	TestUtils::assertEqual("NumComponents", 2, unionFind.getNumComponents());
	TestUtils::assertEqual("Union 0, 2", true, unionFind._union(0, 2));
	TestUtils::assertEqual("NumComponents", 1, unionFind.getNumComponents());
	TestUtils::assertEqual("IsSame 0, 3", true, unionFind.isSameComponent(0, 3));
	TestUtils::assertEqual("IsSame 1, 2", true, unionFind.isSameComponent(1, 2));
	TestUtils::assertEqual("IsSame 0, 1", true, unionFind.isSameComponent(0, 1));
}

int main() {
	test1();
	test2();
	
	return 0;
}

