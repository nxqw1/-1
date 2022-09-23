#pragma once
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
typedef struct BOOK {//ͼ����Ϣ��¼
	int bno = 0;//���
	string name;//����
	string author;//����
	string press;//������
	string fenlei;//����
	int book_count = 0;//����
	int borrow = 0;//������
	BOOK* name_next = nullptr;//ͬ������ָ��
	BOOK* author_next = nullptr;//ͬ����ָ��
	BOOK* press_next = nullptr;//ͬ������ָ��
	BOOK* next = nullptr;//����ָ��
}book;

typedef struct BOOK_NAME //����������ͷ�ļ�
{
	string name;//����
	BOOK* head = nullptr;//��ͷָ��
	int count = 0;//����
	BOOK_NAME* next = nullptr;
}book_name;

typedef struct BOOK_AUTHOR //����������ͷ�ļ�
{
	string name;//����
	BOOK* head = nullptr;//��ͷָ��
	int count = 0;//����
	BOOK_AUTHOR* next = nullptr;
}book_author;

typedef struct BOOK_PRESS //������������ͷ�ļ�
{
	string name;//����
	BOOK* head = nullptr;//��ͷָ��
	int count = 0;//����
	BOOK_PRESS* next = nullptr;
}book_press;

typedef struct BORROW//���������鼮�ṹ�壬�����������Ϣ
{
	int bno = 0;//���
}borrow;

typedef struct READER//������Ϣ�ṹ�壬����������ʽ�洢
{
	string reader_name;//���߱��
	borrow borrow1[100];//�ö��������鼮���
	int count = 0;//��������
	READER* next;//����ָ��
}reader;

void usermain();//ͼ�����������
void readermain();//����������

bool inc_book(int bno, string name, string author, string press, string fenlei, int book_count);//�鼮������
void print_book(book* a1);//����鼮��Ϣ
book* found_name(string name);//ʹ�����������鼮
book* found_author(string author);//ʹ���������ֲ����鼮
book* found_press(string press);//ʹ���������ֲ����鼮
book* found_book(string name, string author, string press);//ʹ��������Ϣ�����鼮
book* found_bno(int bno);//ʹ�����������鼮
reader* found_reader(string name);//ʹ�ö��߱�Ų��Ҷ���
void print_reader(reader* a1);//����ö��߱�Ŷ�����Ϣ
bool outbook(book* head);//����ͼ����Ϣ���ļ�
bool readbook();//���ļ��ж�ȡͼ����Ϣ
bool outreader(reader* head);//���������Ϣ���ļ�
bool readreader();//���ļ��ж�ȡ������Ϣ
void delete_node();//ɾ��������

