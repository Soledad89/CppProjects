#include <iostream>
#include <set>
#include <vector>
int main(int argc, char* argv[]) {
	std::vector<int>vec;
	vec.push_back(1);
	vec.push_back(2);
	std::set<int>st;
	st.insert(10);
	st.insert(0);
	st.insert(vec.begin(),vec.end());
	std::cout<< "set : ";
	for(std::set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		std::cout<< *it << " ";
	}
	std::cout<< std::endl;
	return 0;
}

