#include <iostream>
#include <set>
int main(int argc, char* argv[]) {
	std::set<int> st;
	st.insert(1);
	st.insert(5);
	st.insert(10);
	std::cout<< "count(5) : " << st.count(5) << std::endl;
	std::cout<< "find(5): " << *st.find(5) << std::endl;
	return 0;
}
