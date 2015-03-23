#include <iostream>
#include <set>
#include <vector>
int main(int argc, char* argv[]) {
	std::vector<int>vec;
	for(std::vector<int>::size_type i = 0; i < 10; ++i) {
		vec.push_back(i);
		vec.push_back(i);
	}
	std::cout<< "vector : " << std::endl;
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout<< *it << ",";
	}
	std::cout<< std::endl;
	std::set<int>st(vec.begin(), vec.end());
	std::cout<< "set : " << std::endl;
	for(std::set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		std::cout<< *it << ",";
	}
	std::cout<< std::endl;
	return 0;
}
