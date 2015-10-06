#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class CMyString
{
        friend std::ostream& operator<<( std::ostream& os, const CMyString& str); //对于<<的重载必须用引用
        private:
                char* m_pData; //  私有变量保存字符串            //得用深拷贝，三法则
        public:
                CMyString( const char* str = NULL ); // 构造函数
                CMyString( const CMyString& str ); // 拷贝构造函数
                ~CMyString( void ); // 析构函数
                CMyString& operator=( const CMyString& str ); // 赋值运算符
                CMyString operator+( const CMyString& str ); // 字符串连接 
                bool operator==( const CMyString& str ); // 判断相等
                char operator[]( int idx ); // 数组索引
                int getLength(); // 返回长度
};


//首先考虑三法则的问题，把三法则问题
//////////////////////////////////////////////////////////////////////
CMyString::CMyString( const char* str )
{
        if ( !str )
        {
                this->m_pData = 0;
        }
        else
        {
                this->m_pData = new char[ strlen( str ) + 1 ];
                strcpy( this->m_pData, str );
        }
}

CMyString::CMyString( const CMyString& str )            //拷贝构造函数，这里是深拷贝，如果是编译器默认的话是浅拷贝，只是复制
                                                        //元素的值，不会申请新的空间
{
        if ( !str.m_pData )
        {
                this->m_pData = 0;
        }
        else
        {
                this->m_pData = new char[ strlen( str.m_pData ) + 1 ];
                strcpy( this->m_pData, str.m_pData );
        }
}

CMyString::~CMyString( void )
{
        if ( this->m_pData)
        {
                delete[] this->m_pData;
                this->m_pData = 0;
        }
}

CMyString& CMyString::operator=( const CMyString& str)          
{
        if ( this != &str )
        {
                delete[] this->m_pData;                 //赋值运算法居然先要去释放原有空间里的数据
                if ( !str.m_pData )
                {
                        this->m_pData = 0;
                }
                else
                {
                        this->m_pData = new char[ strlen( str.m_pData ) + 1 ];
                        strcpy( this->m_pData, str.m_pData );
                }
        }
        return *this;
}
//////////////////////////////////////////////////////////////////////////////
CMyString CMyString::operator+( const CMyString& str )
{
        CMyString newString;
        if ( !str.m_pData )
        {
                newString = *this;
        }
        else if ( !this->m_pData )
        {
                newString = str;
        }
        else
        {
                newString.m_pData = new char[ strlen( this->m_pData ) + strlen( str.m_pData ) + 1 ];
                strcpy( newString.m_pData, this->m_pData );
                strcat( newString.m_pData, str.m_pData );
        }

        return newString;

}

bool CMyString::operator==( const CMyString& str )
{
        if ( strlen(this->m_pData) != strlen( str.m_pData ) )
        {
                return false;
        }
        else
        {
                return strcmp( this->m_pData, str.m_pData ) ? false : true;
        }
}

char CMyString::operator[]( int idx)
{
        if ( idx > 0 && idx < strlen( this->m_pData ) )
        return this->m_pData[idx];
}

int CMyString::getLength()
{
        return strlen(this->m_pData);
}

std::ostream& operator<<( std::ostream& os, const CMyString& str )
{
        os<< str.m_pData;
        return os;
}

int main()
{

        CMyString str1("i love ");
        CMyString str2("u baby");
        std::cout << "str1: " << str1 << std::endl;
        std::cout << "str2: " << str2 << std::endl;
        CMyString str3 = str1 + str2;
        std::cout << "str3: " << str3 << std::endl;

        CMyString str4 = str2;
        str1 = str2;
        std::cout << "str4: " << str4 << std::endl;
        std::cout << "str1: " << str1 << std::endl;

        std::cout << "str3 length: " << str3.getLength() << std::endl;
        std::cout << "str3[3]= " << str3[3] << std::endl;

        std::cout << ( str1 == str3 ) << std::endl;
        return 0;
}
