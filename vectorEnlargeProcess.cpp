#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Point
{
public:
        Point()
        {
            cout << "construction" << endl;
        }
        Point(const Point& p)
        {
            cout << "copy construction" << endl;
        }
        ~Point()
        {
            cout << "destruction" << endl;
        }
};

int main()
{
    vector<Point> pointVec;
    //pointVec.reserve(4);
    Point a;
    Point b;
    Point c;
    pointVec.push_back(a);		
    //记住拷贝构造函数在调用函数时也会传入,但是明明push_back传入的是引用啊，怎么回事还会有拷贝复制，
    //原来是因为内存空间不够，需要重新分配一个2倍的内存空间，然后把原来的元素拷贝到新的空间中，同时析构以前的空间
    pointVec.push_back(b);
    pointVec.push_back(c);

    cout<<pointVec.size()<<std::endl;

    return 0;
}