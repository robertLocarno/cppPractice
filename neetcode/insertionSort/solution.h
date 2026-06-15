#pragma once

#include<memory>
#include<unordered_set>
#include<utility>
#include<vector>
#include<iostream>

class Pair {
public:
	int key;
	std::string value;

	Pair(int key, std::string value) : key(key), value(value) {}

	bool operator==(const Pair& other) const = default;
};

template <>
struct std::formatter<Pair> {
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}

	template <class FormatContext>
	auto format(const Pair& p, FormatContext& ctx) const {
		return std::format_to(ctx.out(), "({}, {})", p.key, p.value);
	}
};

class Solution {
public:
	std::vector<std::vector<Pair>> insertionSort(std::vector<Pair>& pairs) {
		std::vector<Pair> result{};
		std::vector<std::vector<Pair>> resultHistory{};

		for (size_t i = 0; i < pairs.size(); i++) {
			for (size_t j = 0; j <= result.size(); j++) {
				if (j == result.size()) {
					result.push_back(pairs[i]);
					break;
				}

				if (result[j].key > pairs[i].key) {
					result.insert(result.begin() + j, pairs[i]);
					break;
				}
			}

			std::vector<Pair> log = result;
			for (size_t z = result.size(); z < pairs.size(); z++) {
				log.push_back(pairs[z]);
			}

			resultHistory.push_back(log);
		}

		return resultHistory; 
	}
};
