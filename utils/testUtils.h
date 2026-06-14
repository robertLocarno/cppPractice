#pragma once

#include<iostream>
#include<format>

class TestUtils {
public:
	template<typename Type>
	static bool assertEqual(std::string assertion, Type expected, Type actual) {
		if (expected != actual) {
			std::cout << std::format("'{}' failed.", assertion) << std::endl;
			std::cout << std::format("    Expected: {}", expected) << std::endl;
			std::cout << std::format("    Actual: {}", actual) << std::endl;

			return false;
		}

		return true;
	}
};

