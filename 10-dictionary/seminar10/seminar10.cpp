#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

//Problem 1
unordered_map<string, unsigned> countWords(const string words[], const size_t size) {
	unordered_map<string, unsigned> result;

	for (size_t i = 0; i < size; ++i) {
		if (result.count(words[i]) == 0) {
			result.insert({ words[i], 1 });
		} else {
			++result[words[i]];
		}
	}

	return result;
}

//Problem 2
unordered_map<string, vector<string>> groupByCategory(const pair<string, string> words[], const size_t size) {
	unordered_map<string, vector<string>> result;

	for (size_t i = 0; i < size; ++i) {
		if (result.count(words[i].second) == 0) {
			result.insert({ words[i].second, { words[i].first }});
		}
		else {
			result[words[i].second].push_back(words[i].first);
		}
	}

	return result;
}

int main() {
	const string fruits[] { "apple", "banana", "apple", "orange", "banana", "apple" };
	const auto result = countWords(fruits, 6);

	for (pair<string, unsigned> kvp : result) {
		cout << kvp.first << ":" << kvp.second << endl;
	}

	//Изход: { "apple": 3, "banana" : 2, "orange" : 1 }

	const pair<string, string> fruitsCategorized[]{ {"apple", "fruit"}, {"carrot", "vegetable"}, {"banana", "fruit"}, {"broccoli", "vegetable"} };

	const auto result2 = groupByCategory(fruitsCategorized, 4);

	for (pair<string, vector<string>> kvp : result2) {
		cout << kvp.first << ":";

		for (string fruit : kvp.second) {
			cout << fruit << ", ";
		}

		cout << endl;
	}

	//Изход: { "fruit": ["apple", "banana"] , "vegetable" : ["carrot", "broccoli"] }
	return 0;
}
