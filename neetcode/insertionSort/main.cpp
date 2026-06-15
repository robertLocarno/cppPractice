#include<iostream>
#include<vector>
#include<format>

#include "solution.h"
#include "../../utils/testUtils.h"

void test1() {
	std::cout << "Test 1" << std::endl;

	Solution solution;
	std::vector<Pair> pairs = {Pair(5, "apple"), Pair(2, "bananna"), Pair(9, "cherry")};
	std::vector<std::vector<Pair>> expected = {
		std::vector<Pair>{Pair(5, "apple"), Pair(2, "bananna"), Pair(9, "cherry")},
		std::vector<Pair>{Pair(2, "bananna"), Pair(5, "apple"), Pair(9, "cherry")},
		std::vector<Pair>{Pair(2, "bananna"), Pair(5, "apple"), Pair(9, "cherry")}
	};

	std::vector<std::vector<Pair>> result = solution.insertionSort(pairs);

	for (int i = 0; i < pairs.size(); i++) {
		for (int j = 0; j < pairs.size(); j++) {
			if (i >= result.size() || j >= result[i].size()) {
				std::cout << std::format("ERROR: {}, {} out of bounds", i, j) << std::endl;
				break;
			}

			TestUtils::assertEqual(
				std::format("Iteration {}, Pair {}: ", i, j),
				expected[i][j],
				result[i][j]
			);
		}
	}
}

void test2() {
	std::cout << "Test 2" << std::endl;

	Solution solution;
	std::vector<Pair> pairs = {Pair(3, "cat"), Pair(3, "bird"), Pair(2, "dog")};
	std::vector<std::vector<Pair>> expected = {
		std::vector<Pair>{Pair(3, "cat"), Pair(3, "bird"), Pair(2, "dog")},
		std::vector<Pair>{Pair(3, "cat"), Pair(3, "bird"), Pair(2, "dog")},
		std::vector<Pair>{Pair(2, "dog"), Pair(3, "cat"), Pair(3, "bird")}
	};

	std::vector<std::vector<Pair>> result = solution.insertionSort(pairs);

	for (int i = 0; i < pairs.size(); i++) {
		for (int j = 0; j < pairs.size(); j++) {
			if (i >= result.size() || j >= result[i].size()) {
				std::cout << std::format("ERROR: {}, {} out of bounds", i, j) << std::endl;
				break;
			}

			TestUtils::assertEqual(
				std::format("Iteration {}, Pair {}: ", i, j),
				expected[i][j],
				result[i][j]
			);
		}
	}
}

int main() {
	test1();
	test2();
	
	return 0;
}

