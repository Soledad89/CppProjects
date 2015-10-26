#include <iostream>
#include <functional>
#include <string>
#include <assert.h>

int main()
{
    std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    std::size_t str_hash = hash_fn(str);
    
    std::cout << str_hash << '\n';
    
    //test the string functions
        std::string const s("Emplary");
        assert(s.size() == std::strlen(s.c_str()));
        assert(std::equal(s.begin(), s.end(), s.c_str()));
        assert(std::equal(s.c_str(), s.c_str() + s.size(), s.begin()));
        assert(0 == *(s.c_str() + s.size()));
}


//#include <stdio.h>
//char * f()
//{
//    char x[512];
//    sprintf(x, "hello world");
//    return x + 6;
//}
//int main()
//{
//    printf("%s", f());
//    return 0;
//
//}
//#include <functional>
//#include <queue>
//#include <vector>
//#include <iostream>
//
//template<typename T> void print_queue(T& q) {
//    while(!q.empty()) {
//        std::cout << q.top() << " ";
//        q.pop();
//    }
//    std::cout << '\n';
//}
//
//int main() {
//    std::priority_queue<int> q;
//    
//    for(int n : {1,8,5,6,3,4,0,9,3,2})
//        q.push(n);
//    
//    print_queue(q);
//    
//    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
//    
//    for(int n : {1,8,5,6,3,4,0,9,3,2})
//        q2.push(n);
//    
//    print_queue(q2);
//}


//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//
//struct Employee {
//    Employee(int age, std::string name) : age(age), name(name) { }
//    int age;
//    std::string name;  // Does not particpate in comparisons
//};
//
//bool operator<(const Employee &lhs, const Employee &rhs) {
//    return lhs.age < rhs.age;
//}
//
//int main()
//{
//    std::vector<Employee> v = {
//        Employee(108, "Zaphod"),
//        Employee(32, "Arthur"),
//        Employee(108, "Ford"),
//    };
//    
//    std::stable_sort(v.begin(), v.end());
//    
//    for (const Employee &e : v) {
//        std::cout << e.age << ", " << e.name << '\n';
//    }
//}


//
//#include <functional>
//#include <queue>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//

//template<typename T> void print_queue(T& q) {
//    while(!q.empty()) {
//        std::cout << q.top() << " ";
//        q.pop();
//    }
//    std::cout << '\n';
//}
//
//int main() {
//    std::priority_queue<int> q;
//    
//    for(int n : {1,8,5,6,3,4,0,9,3,2})
//        q.push(n);
//    
//    
//    print_queue(iv);
//    print_queue(q);
//    
//    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
//    
//    for(int n : {1,8,5,6,3,4,0,9,3,2})
//        q2.push(n);
//    
//    print_queue(q2);
//}


//
//
////by MoreWindows( http://blog.csdn.net/MoreWindows )
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include <cstdlib>
//#include <iostream>
//#include <list>
//
//template <class T>
//struct plus2 {
//    void operator() (T& x) const
//    {
//        x+=2;
//    }
//};
//
//using namespace std;
//void PrintfVectorInt(vector<int> &vet)
//{
//    for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)
//        printf("%d ", *pos);
//    putchar('\n');
//}
//int main()
//{
//    
//    int buf[]={3,29,4,27,15,9,2,4,7};
//    nth_element(buf,buf+3,buf+sizeof(buf)/sizeof(int));//注意这里是9，[first,last)前开后闭原则
//    copy(buf,buf+sizeof(buf)/sizeof(int),ostream_iterator<int>(cout,","));
//    cout << endl;
//    
//    
//    const int MAXN = 20;
//    int a[MAXN];
//    int i;
//    for (i = 0; i < MAXN; ++i)
//        a[i] = rand() % (MAXN * 2);
//    
//    int ia[] = {0, 1,2 , 3,4 , 5};
//    
//    vector<int> iv(ia, ia + sizeof(ia)/sizeof(int));
//    PrintfVectorInt(iv);
//    for_each(iv.begin(), iv.end(), plus2<int>());
//    PrintfVectorInt(iv);
//    
//    make_heap(ia, ia+6);
//    sort_heap(ia, ia+6);
//    for (int i = 0; i < 6; i++)
//        std::cout << ia[i] << " ";
//    std::cout << endl;
//    
//    //动态申请vector 并对vector建堆
//    vector<int> *pvet = new vector<int>(40);
//    pvet->assign(a, a + MAXN);
//    PrintfVectorInt(*pvet);
//    
//    //建堆
//    make_heap(pvet->begin(), pvet->end());
//    PrintfVectorInt(*pvet);
//    
//    //加入新数据 先在容器中加入，再调用push_heap()
//    pvet->push_back(25);
//    push_heap(pvet->begin(), pvet->end());
//    PrintfVectorInt(*pvet);
//    
//    //删除数据  要先调用pop_heap()，再在容器中删除
//    pop_heap(pvet->begin(), pvet->end());
//   // PrintfVectorInt(*pvet);
//    pvet->pop_back();
//    PrintfVectorInt(*pvet);
//       //堆排序
//    sort_heap(pvet->begin(), pvet->end());
//    PrintfVectorInt(*pvet);
//    
//    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
//    
//    std::cout << "before sort:      ";
//    for (int n: v)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    
//    // insertion sort
//    for (auto i = v.begin(); i != v.end(); ++i) {
//        std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
//    }
//    
//    std::cout << "after sort:       ";
//    for (int n: v)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    
//    // simple rotation to the left
//    std::rotate(v.begin(), v.begin() + 1, v.end());
//    
//    std::cout << "simple rotate left  : ";
//    for (int n: v)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    
//    // simple rotation to the right
//    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
//    
//    std::cout << "simple rotate right : ";
//    for (int n: v)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    
//    std::vector<int> vv = {1, 2, 3, 4, 5};
//    reverse(vv.begin(), vv.end());
//    
//    std::list<int> ll = {-1, -2, -3, -4, -5};
//    
//    std::swap_ranges(vv.begin(), vv.begin()+3, ll.begin());
//    
//    for(int n : vv)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    for(int n : ll)
//        std::cout << n << ' ';
//    std::cout << '\n';
//    
//    delete pvet;
//    return 0;
//}



//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main()
//{
//    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
//    
//    std::cout << "initially, v: ";
//    for (auto i : v) std::cout << i << ' ';
//    std::cout << '\n';
//    
//    std::make_heap(v.begin(), v.end());
//    
//    std::cout << "after make_heap, v: ";
//    for (auto i : v) std::cout << i << ' ';
//    std::cout << '\n';
//    
//    std::pop_heap(v.begin(), v.end());
//    auto largest = v.back();
//    v.pop_back();
//    std::cout << "largest element: " << largest << '\n';
//    
//    std::cout << "after removing the largest element, v: ";
//    for (auto i : v) std::cout << i << ' ';
//    std::cout << '\n';
//}


//#include <iostream>
//#include <list>
//
//std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
//{
//    for (auto &i : list) {
//        ostr << " " << i;
//    }
//    return ostr;
//}
//
//int main ()
//{
//    std::list<int> list1 = { 1, 2, 3, 4, 5 };
//    std::list<int> list2 = { 10, 20, 30, 40, 50 };
//    
//    auto it = list1.begin();
//    std::advance(it, 3);
//    
//    list1.splice(it, list2);
//    
//    std::cout << "list1: " << list1 << "\n";
//    std::cout << "list2: " << list2 << "\n";
//    
//    list2.splice(list2.begin(), list1, it, list1.end());
//    
//    std::cout << "list1: " << list1 << "\n";
//    std::cout << "list2: " << list2 << "\n";
//}
//
//#include <stdio.h>
//#include <stddef.h>
//#include <stdint.h>
//
//int main(void)
//{
//    const size_t N = 100;
//    int numbers[N];
//    
//    printf("PTRDIFF_MAX = %ld\n", PTRDIFF_MAX);
//    int *p1=&numbers[18], *p2=&numbers[23];
//    ptrdiff_t diff = p2-p1;
//    printf("p2-p1 = %td\n", diff);
//    
//    return 0;
//}