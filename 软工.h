#pragma once
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
typedef struct BOOK {//图书信息记录
	int bno = 0;//书号
	string name;//书名
	string author;//作者
	string press;//出版社
	string fenlei;//分类
	int book_count = 0;//藏书
	int borrow = 0;//借书数
	BOOK* name_next = nullptr;//同名书名指针
	BOOK* author_next = nullptr;//同作者指针
	BOOK* press_next = nullptr;//同出版社指针
	BOOK* next = nullptr;//主书指针
}book;

typedef struct BOOK_NAME //书名索引链头文件
{
	string name;//书名
	BOOK* head = nullptr;//链头指针
	int count = 0;//长度
	BOOK_NAME* next = nullptr;
}book_name;

typedef struct BOOK_AUTHOR //作者索引链头文件
{
	string name;//书名
	BOOK* head = nullptr;//链头指针
	int count = 0;//长度
	BOOK_AUTHOR* next = nullptr;
}book_author;

typedef struct BOOK_PRESS //出版社索引链头文件
{
	string name;//书名
	BOOK* head = nullptr;//链头指针
	int count = 0;//长度
	BOOK_PRESS* next = nullptr;
}book_press;

typedef struct BORROW//读者所借书籍结构体，可添加其他信息
{
	int bno = 0;//书号
}borrow;

typedef struct READER//读者信息结构体，采用链表形式存储
{
	string reader_name;//读者编号
	borrow borrow1[100];//该读者所借书籍书号
	int count = 0;//借书数量
	READER* next;//链表指针
}reader;

void usermain();//图书管理主函数
void readermain();//读者主函数

bool inc_book(int bno, string name, string author, string press, string fenlei, int book_count);//书籍入库操作
void print_book(book* a1);//输出书籍信息
book* found_name(string name);//使用书名查找书籍
book* found_author(string author);//使用作者名字查找书籍
book* found_press(string press);//使用作者名字查找书籍
book* found_book(string name, string author, string press);//使用所有信息查找书籍
book* found_bno(int bno);//使用书名查找书籍
reader* found_reader(string name);//使用读者编号查找读者
void print_reader(reader* a1);//输出该读者编号读者信息
bool outbook(book* head);//保存图书信息至文件
bool readbook();//从文件中读取图书信息
bool outreader(reader* head);//保存读者信息至文件
bool readreader();//从文件中读取读者信息
void delete_node();//删除链表函数

