#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
/*
请用c++ 实现stl中的string类，实现构造，拷贝构造，析构，赋值，比较，字符串相加，获取长度及子串等功能。
*/
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
                CMyString operator<( const CMyString& str ); //字符串比较 
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

CMyString& CMyString::operator=( const CMyString& str)   //赋值构造函数在调用时，应该首先判断其是否为本身       
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

 
class String{
public:
    // 默认构造函数
    String(const char* str = NULL);
    // 复制构造函数
    String(const String &str);
    // 析构函数
    ~String();
    // 字符串连
    String operator+(const String &str);
    // 字符串赋值
    String & operator=(const String &str);//两种赋值方式
    // 字符串赋值
    String & operator=(const char* str);
    // 判断是否字符串相等
    bool operator==(const String &str);
    // 获取字符串长度
    int length();
    // 求子字符串[start,start+n-1]
    String substr(int start, int n);
    // 重载输出接
    friend ostream & operator<<(ostream &o,const String &str);
private:
    char* data;
    int size;
};
// 构造函数
String::String(const char *str){
    if(str == NULL){
        data = new char[1];
        data[0] = '\0';
        size = 0;
    }//if
    else{
        size = strlen(str);             
        data = new char[size+1];            //必须实行深拷贝
        strcpy(data,str);
    }//else
}
// 复制构造函数
String::String(const String &str){
    size = str.size;
    data = new char[size+1];
    strcpy(data,str.data);
}
// 析构函数
String::~String(){
    delete[] data;
}
// 字符串连接
String String::operator+(const String &str){
    String newStr;
    //释放原有空间
    delete[] newStr.data;
    newStr.size = size + str.size;
    newStr.data = new char[newStr.size+1];
    strcpy(newStr.data,data);
    strcpy(newStr.data+size,str.data);
    return newStr;
}
// 字符串赋值
String & String::operator=(const String &str){
    if(data == str.data){
        return *this;
    }//if
    delete [] data;
    size = str.size;
    data = new char[size+1];
    strcpy(data,str.data);
    return *this;
}
// 字符串赋值
String& String::operator=(const char* str){
    if(data == str){
        return *this;
    }//if
    delete[] data;
    size = strlen(str);
    data = new char[size+1];
    strcpy(data,str);
    return *this;
}
// 判断是否字符串相等
bool String::operator==(const String &str){
    return strcmp(data,str.data) == 0;
}
// 获取字符串长度
int String::length(){
    return size;
}
// 求子字符串[start,start+n-1]
String String::substr(int start, int n){
    String newStr;
    // 释放原有内存
    delete [] newStr.data;
    // 重新申请内存
    newStr.data = new char[n+1];
    for(int i = 0;i < n;++i){
        newStr.data[i] = data[start+i];
    }//for
    newStr.data[n] = '\0';
    newStr.size = n;
    return newStr;
}
// 重载输出
std::ostream& operator<<( std::ostream& os, const String& str )
{
        os<< str.data;
        return os;
}
