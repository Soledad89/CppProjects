#include<iostream>
using namespace std;

class Singleton
{
public:
    static Singleton * GetInstance()//通过静态公有函数获得该类的实例对象
    {
        if(m_pInstance==NULL) {
            m_pInstance = new Singleton();
        }
        return m_pInstance;
    }

private:
    Singleton(){}               //构造函数私有化的目的是为了防止从别处实例化该类对象
    static Singleton * m_pInstance;
    class Garbo                 //删除Singleton实例的对象
    {
    public:
        ~Garbo()
        {
            if(Singleton::m_pInstance)
            {
                delete Singleton::m_pInstance;
            }
        }
    };
    static Garbo gb;             //在程序结束时，系统会调用它的析构函数
};
Singleton * Singleton::m_pInstance = NULL;//初始化静态数据成员

int main()
{
    Singleton *sl=Singleton::GetInstance();
    return 0;
}