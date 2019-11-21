#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

map<string, string> buildmap(ifstream&map_file) {
	map<string, string>trans_map;
	string key, value;
	while (map_file >> key&&getline(map_file, value))
		if (value.size()>1) trans_map[key] = value.substr(1);
		else throw runtime_error("no rule for transform " + key);


		return trans_map;


}

const string& transform(const string& s, const map<string, string>& m) {
	auto map_it = m.find(s);
	if (map_it != m.end()) return  map_it->second;
	else return s;
}

void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = buildmap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) firstword = false;
			else cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}


int main() {
	ifstream map("map");
	ifstream txt("text");
	word_transform(map, txt);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

multiset<Sales_data, decltype(compareIsbn)*>
bookstore(compareIsbn);

word_count.insert({word, 1});
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, size_t>(word, 1));
word_count.insert(map<string, size_t>::value_type(word, 1));