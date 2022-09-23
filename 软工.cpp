#include"软工.h"

book* head = new book();
book_name* name_head = new book_name();
book_author* author_head = new book_author();
book_press* press_head = new book_press();
reader* read = new reader();

void usermain()
{

	int a1 = 1;//图书管理while循环选择
	int a2 = 1;//图书信息while循环选择
	bool flag = false;
	int bno;//书号
	string name;//书名
	string author;//作者
	string press;//出版社
	string fenlei;//分类
	int book_count;//藏书
	book* p1;
	reader* p;
	while (a1 != 0)
	{
		cout << endl << "\t\t\t**图书管理**" << endl;
		cout << "\t\t\t1.图 书 信 息 管 理 " << endl;
		cout << "\t\t\t2.读取存储的图书信息" << endl;
		cout << "\t\t\t3.查看所有读者信息" << endl;
		cout << "\t\t\t0.返 回 " << endl;
		cout << " 请选择：";
		cin >> a1;
		switch (a1)
		{
		case 1:
			a2 = 1;
			while (a2 != 0)
			{
				cout << "\n\t\t\t** 图 书 信 息 **" << endl;
				cout << " \t\t\t1.新 增 " << endl;
				cout << "\t\t\t2.按照书号升序输出 " << endl;
				cout << " \t\t\t3.按照书号查找 " << endl;
				cout << " \t\t\t4.书名查找 " << endl;
				cout << " \t\t\t5.作者名字查找 " << endl;
				cout << " \t\t\t6.出版社名字查找 " << endl;
				cout << " \t\t\t7.输入书名、作者、出版社信息查找 " << endl;
				cout << " \t\t\t8.保存图书信息 " << endl;
				cout << " \t\t\t0.返 回 " << endl;
				cout << " 请选择：";
				cin >> a2;

				switch (a2)
				{
				case 1://书籍入库操作

					cout << endl << "输入书号：";
					cin >> bno;
					cout << "输入书名：";
					cin >> name;
					cout << "输入作者：";
					cin >> author;
					cout << "输入出版社：";
					cin >> press;
					cout << "输入分类：";
					cin >> fenlei;
					cout << "输入数量：";
					cin >> book_count;

					inc_book(bno, name, author, press, fenlei, book_count);//收集信息利用入库函数进行入库操作

					break;
				case 2://按照书号升序输出所有书籍

					p1 = head;//指针指向书库头指针
					if (p1->next == nullptr)cout << "未读取到书籍" << endl;
					while (p1->next != nullptr)
					{
						print_book(p1->next);
						p1 = p1->next;
					}
					break;
				case 3://按照书号查找
					cout << '\n' << "输入书号：";
					cin >> bno;
					p1 = found_bno(bno);//调用书号查找函数
					if (p1->next == nullptr)
					{
						cout << "未找到该书籍。" << endl;
					}
					break;
				case 4://按照书名查找
					cout << '\n' << "输入书名：";
					cin >> name;
					found_name(name); //调用书名查找函数，利用书名索引查找
					break;
				case 5://按照作者名字查找
					cout << '\n' << "输入作者名字:";
					cin >> author;
					found_author(author);//调用作者名字查找函数，利用作者索引查找
					break;
				case 6://按照出版社名字查找
					cout << '\n' << "输入出版社名字:";
					cin >> press;
					found_press(press);//调用出版社查找函数，利用出版社索引查找

					break;
				case 7://按照上述三项查找
					cout << '\n' << "输入书名：";
					cin >> name;
					cout << "输入作者名字:";
					cin >> author;
					cout << "输入出版社名字:";
					cin >> press;
					p1 = found_book(name, author, press);//调用查找函数，利用三种索引快速查找
					if (p1 == nullptr)
					{
						cout << "未找到该书籍。" << endl;
					}
					else
					{
						cout << "找到书籍，信息如下：" << endl;
						print_book(p1);
					}
					break;
				case 8://保存书籍信息至文件
					flag = outbook(head);

					if (flag)cout << "\t\t**保存书籍信息成功**" << endl;

					break;
				case 0:
					break;
				}
			}
			break;
		case 2://读取文件中图书信息
			delete_node();
			head = new book;
			name_head = new book_name;
			author_head = new book_author;
			press_head = new book_press;
			read = new reader();
			flag = readbook();//调用读取函数

			if (flag) {
				cout << "\t\t**数据读取成功**" << endl;
				readreader();//调用读者信息读取函数
			}
			else
			{
				cout << "\t\t**还未有书籍信息**" << endl;
			}
			break;
		case 3:
			p = read;
			while (p->next != nullptr)
			{
				print_reader(p->next);
				p = p->next;
			}
			break;
		case 0:
			return;
		}
	}
}
void readermain()
{
	int a1 = 1;//读者while循环选择
	/*int a2 = 1;*///读者while循环选择
	bool flag = false;
	int select = 1;
	int bno;//书号
	string name;//书名
	string author;//作者
	string press;//出版社
	string fenlei;//分类
	int book_count;//藏书
	string reader_name;//读者编号
	book* p1;
	reader* b1;
	book* h;

	delete_node();//调用链表删除函数，删除链表后读入书籍信息
	head = new book();
	name_head = new book_name();
	author_head = new book_author();
	press_head = new book_press();
	readbook();//调用书籍信息读取函数
	read = new reader();
	readreader();//调用读者信息读取函数
	while (a1 != 0)
	{
		cout << endl << "\t\t\t**读者**" << endl;
		cout << "\t\t\t1.查找书籍信息 " << endl;
		cout << "\t\t\t2.借书" << endl;
		cout << "\t\t\t3.还书" << endl;
		cout << "\t\t\t4.输出借书信息" << endl;
		cout << "\t\t\t5.保存读者文件" << endl;
		cout << "\t\t\t6.读取读者文件" << endl;
		cout << "\t\t\t0.返 回 " << endl;
		cout << " 请选择：";
		cin >> a1;
		switch (a1)
		{
		case 1://查找书籍信息
			select = 1;
			while (select != 0)
			{
				cout << endl << "1、用书名查询；2、用作者名字查询；3、用出版社查询；4、用以上信息查询；5、输出所有图书信息；6、用书号查询；0、返回" << endl;
				cout << " 请选择：";
				cin >> select;
				if (select == 1) {
					cout << "输入书名：";
					cin >> name;
					p1 = found_name(name);//按照书名查找
					
				}
				else if (select == 2)
				{
					cout << "输入作者名字:";
					cin >> author;
					p1 = found_author(author);//按照作者查找
					
				}
				else if (select == 3)
				{
					cout << "输入出版社名字:";
					cin >> press;
					p1 = found_press(press);//按照出版社查找
					
				}
				else if (select == 4)
				{
					cout << "输入书名：";
					cin >> name;
					cout << "输入作者名字:";
					cin >> author;
					cout << "输入出版社名字:";
					cin >> press;
					p1 = found_book(name, author, press);//按照书名、作者、出版社查找
					if (p1 == nullptr)
					{
						cout << "\t\t**未找到该书籍**" << endl;
					}
					else
					{
						cout << "\t\t**找到书籍，信息如下**" << endl;
						print_book(p1);
					}
				}
				else if (select == 5)
				{
					p1 = head;
					while (p1->next != nullptr)
					{
						print_book(p1->next);//输出所有书籍信息
						p1 = p1->next;
					}
				}
				else if (select == 6)
				{
					cout << "输入书号：";
					cin >> bno;
					p1 = found_bno(bno);//按照书号查找
					if (p1->next == nullptr)
					{
						cout << "\t\t**没有该书号的书籍**" << endl;
					}
				}
			}
			break;
		case 2://借书
			cout << endl << "请输入读者编号：";
			cin >> reader_name;
			cout << "请输入想借的书的书号：";
			cin >> bno;
			h = head;
			while (h->next != nullptr)//这里找到所借书籍的地址
			{
				if (h->next->bno == bno)
				{
					break;
				}
				h = h->next;
			}
			if (h->next != nullptr)//若找到书籍
			{

				if (h->next->book_count > 0)//若藏书大于0则
				{
					h->next->borrow++;//所借书数量+1
					h->next->book_count--;//藏书书-1
				}
				else
				{
					cout << "\t\t**该书无库存**" << endl;
					break;
				}
			}
			else
			{
				cout << "\t\t**没有该书**" << endl;
				break;
			}
			b1 = found_reader(reader_name);//按照读者编号查找是否已存在该读者
			if (b1 != nullptr)//找到
			{
				b1->borrow1[b1->count].bno = bno;//将其所借书号添加进borrow1[]数组中

				b1->count++;//所借书数量+1
			}
			else//未找到，新建该读者信息
			{
				reader* q = read;//从链头指针开始创建
				reader* p = new reader();
				p->reader_name = reader_name;//读者编号
				p->next = q->next;//将其插入链表头
				q->next = p;
				p->borrow1[p->count].bno = bno;//将其所借书号添加进borrow1[]数组中
				p->count++;
			}
			cout << "**借 书 成 功**" << endl;//到这一步，表明有读者成功借到书籍
			outreader(read);//借书成功后将信息保存下来
			break;
		case 3://还书
			cout << '\n' << "请输入读者编号：";
			cin >> reader_name;
			cout << "请输入想还的书的书号：";
			cin >> bno;
			h = head;//h=书籍链头指针

			b1 = found_reader(reader_name);//找到该读者名字
			if (b1 != nullptr)//若找到该读者
			{
				for (int i = 0; i < b1->count; i++)
				{
					if (b1->borrow1[i].bno == bno)
					{
						for (int t = i; t < b1->count; t++)
						{
							b1->borrow1[i].bno = b1->borrow1[i + 1].bno;//将其在读者文件中的书籍信息找到，删除信息
						}
						break;
					}
				}
				b1->count--;
				while (h->next != nullptr)//找到该读者想还书的书籍
				{
					if (h->next->bno == bno)
					{
						break;
					}
					h = h->next;
				}
				if (h->next != nullptr && h->next->borrow > 0)//若该书有被借
				{
					h->next->borrow--;
					h->next->book_count++;
				}
				else//若该书未被借过
				{
					cout << "\t\t**没有借此书**" << endl;
					break;
				}
			}
			else//若未找到读者，则
			{
				cout << "\t\t**没有借此书**" << endl;
				break;
			}

			cout << "\t\t**还书成功**" << endl;//还书成功后将信息保存下来
			outreader(read);
			break;
		case 4://通过读者编号查找读者所借书籍
			cout << '\n' << "请输入读者编号：";
			cin >> reader_name;
			b1 = read;
			while (b1->next != nullptr)//找到该读者编号信息
			{
				if (b1->next->reader_name == reader_name)
				{
					print_reader(b1->next);
					break;
				}
				b1 = b1->next;
			}
			break;
		case 5://保存读者信息

			flag = outreader(read);
			if (flag)cout << "\t\t**保存读者信息成功**" << endl;
			break;
		case 6://读取读者信息

			delete_node();
			head = new book;
			name_head = new book_name;
			author_head = new book_author;
			press_head = new book_press;
			read = new reader();
			flag = readbook();//调用读取函数

			if (flag) {
				cout << "\t\t**数据读取成功**" << endl;
				readreader();//调用读者信息读取函数
			}
			else
			{
				cout << "\t\t**还未有书籍信息**" << endl;
			}
			break;
		case 0:
			break;
		}
	}
}
bool inc_book(int bno, string name, string author, string press, string fenlei, int book_count)//添加书籍
{
	book* ptr = new book();//新书编入
	ptr->bno = bno;
	book* h = head;


	ptr->name = name;
	ptr->author = author;
	ptr->press = press;
	ptr->fenlei = fenlei;
	ptr->book_count = book_count;//录入图书信息

	book* a = found_book(name, author, press);//查看是否有相同书籍
	if (a != nullptr)//存在
	{
		cout << "该书已存在，库存增加" << endl;
		a->book_count += book_count;
	}
	else {//未存在
		while (h->next != nullptr)
		{
			if (h->next->bno == bno)
			{
				cout << "已有该编号的书，请重新输入编号:" << endl;
				cin >> ptr->bno;
				break;
			}
			h = h->next;
		}

		h = head;

		while (h->next != nullptr)//插入时直接按照书号排序
		{
			if (h->next->bno > ptr->bno)
			{
				ptr->next = h->next;
				h->next = ptr;//将新书编入主表中
				break;
			}
			h = h->next;
		}
		if (h->next == nullptr)
		{
			ptr->next = h->next;
			h->next = ptr;//将新书编入主表中
		}



		book_name* p = name_head;//书名索引建立
		bool flag = false;//false表示没有该书名索引
		while (p->next != nullptr)//循环结束若找到相同名字索引，则将其链接在索引中
		{
			if (p->next->name == ptr->name)
			{
				ptr->name_next = p->next->head;
				p->next->head = ptr;
				p->count++;
				flag = true;
			}
			p = p->next;
		}
		if (!flag)
		{
			book_name* ss = new book_name;//循环结束若没有找到相同名字索引，则新建名字索引
			ss->name = ptr->name;
			ss->head = ptr;
			ss->next = name_head->next;
			name_head->next = ss;
			flag = false;
		}

		flag = false;
		book_author* p1 = author_head;//作者索引建立
		while (p1->next != nullptr)//循环结束若找到相同作者索引，则将其链接在索引中
		{
			if (p1->next->name == ptr->author)
			{
				ptr->author_next = p1->next->head;
				p1->next->head = ptr;
				p1->count++;
				flag = true;
			}
			p1 = p1->next;
		}
		if (!flag)//循环结束若没有找到相同作者索引，则新建作者索引
		{
			book_author* ss = new book_author;
			ss->name = ptr->author;
			ss->head = ptr;
			ss->next = author_head->next;
			author_head->next = ss;
			flag = false;
		}

		flag = false;
		book_press* p2 = press_head;//出版社索引建立
		while (p2->next != nullptr)//循环结束若找到相同出版社索引，则将其链接在索引中
		{
			if (p2->next->name == ptr->press)
			{
				ptr->press_next = p2->next->head;
				p2->next->head = ptr;
				p2->count++;
				flag = true;
			}
			p2 = p2->next;
		}
		if (!flag)//循环结束若没有找到相同出版社索引，则新建出版社索引
		{
			book_press* ss = new book_press;
			ss->name = ptr->press;
			ss->head = ptr;
			ss->next = press_head->next;
			press_head->next = ss;
			flag = false;
		}
	}

	return true;
}

book* found_name(string name)//使用名字查找书籍
{
	book_name* p = name_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//利用索引查找书名对应链头指针
	{
		if (p->name == name) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\t未找到该书名的书籍" << endl;//未找到
	else
		while (b1 != nullptr)//找到，输出所有该名字书籍
		{
			print_book(b1);
			b1 = b1->name_next;
		}
	return nullptr;
}
book* found_author(string author)//使用作者名字查找书籍
{
	book_author* p = author_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//索引查找书名对应链头指针
	{
		if (p->name == author) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\t未找到该作者书籍" << endl;//未找到
	else
		while (b1 != nullptr)//输出所有该作者书籍
		{
			print_book(b1);
			b1 = b1->author_next;
		}
	return nullptr;
}
book* found_press(string press)//使用出版社名字查找书籍
{
	book_press* p = press_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//查找书名对应链头指针
	{
		if (p->name == press) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\t未找到该出版社书籍" << endl;//未找到
	else
		while (b1 != nullptr)//输出所有该出版社书籍
		{
			print_book(b1);
			b1 = b1->press_next;
		}
	return nullptr;
}
book* found_book(string name, string author, string press)
{

	book_name* p_name = name_head->next;
	book* b_name = nullptr;
	while (p_name != nullptr)//查找书名对应链头指针
	{
		if (p_name->name == name) {
			b_name = p_name->head;
			break;
		}
		p_name = p_name->next;
	}



	book_author* p_author = author_head->next;
	book* b_author = nullptr;
	while (p_author != nullptr)//查找作者对应链头指针
	{
		if (p_author->name == author) {
			b_author = p_author->head;
			break;
		}
		p_author = p_author->next;
	}


	book_press* p_press = press_head->next;
	book* b_press = nullptr;
	while (p_press != nullptr)//查找出版社对应链头指针
	{
		if (p_press->name == press) {
			b_press = p_press->head;
			break;
		}
		p_press = p_press->next;
	}

	for (; b_name != nullptr; b_name = b_name->name_next)
	{
		if (p_author != nullptr)
			b_author = p_author->head;
		for (; b_author != nullptr; b_author = b_author->author_next)
		{
			if (p_press != nullptr)
				b_press = p_press->head;
			for (; b_press != nullptr; b_press = b_press->press_next)
			{
				if (b_name->bno == b_author->bno && b_author->bno == b_press->bno)
					return b_name;
			}
		}
	}
	return nullptr;

}
book* found_bno(int bno)//通过书号查找图书
{
	book* h = head;
	while (h->next != nullptr)
	{
		if (h->next->bno == bno)
		{
			print_book(h->next);//输出该图书
			break;
		}
		h = h->next;
	}
	return h;
}
reader* found_reader(string name)//利用读者编号找到读者信息
{
	reader* q = read;
	while (q->next != nullptr)
	{
		if (q->next->reader_name == name)
			return q->next;//找到则返回该读者的指针
		q = q->next;
	}
	return nullptr;
}

void print_book(book* a1)//输出书籍信息
{
	if (a1 != nullptr)
	{
		cout << "书号:" << a1->bno << "    ";
		cout << "书名:" << a1->name << "    ";
		cout << "作者:" << a1->author << "    ";
		cout << "出版社:" << a1->press << "    ";
		cout << "分类" << a1->fenlei << "    ";
		cout << "库存:" << a1->book_count << "    ";
		cout << "借出数量:" << a1->borrow << endl;
	}
}
void print_reader(reader* a1)//输出读者借书信息
{
	for (int i = 0; i < a1->count; i++)//将其所借书籍输出
		cout << a1->reader_name << "  所借书号：" << a1->borrow1[i].bno << endl;
}


bool outbook(book* head)//保存书籍文件
{
	fstream file("book.txt", ios::out);
	if (!file)return false;
	book* t = head;
	while (t->next != nullptr)
	{
		file << t->next->bno << '\n'
			<< t->next->name << '\n'
			<< t->next->author << '\n'
			<< t->next->press << '\n' << t->next->fenlei << '\n'
			<< t->next->book_count << '\n';
		t = t->next;
	}
	file.close();
	return true;
	cout << "**保存图书信息成功**" << endl;
}
bool readbook()//读取书籍文件
{
	fstream file("book.txt", ios::in);
	if (!file)return false;
	book t;
	while (!file.eof())
	{

		file >> t.bno;
		file >> t.name;
		file >> t.author;
		file >> t.press;
		file >> t.fenlei;
		file >> t.book_count;
		if (file.eof())break;
		inc_book(t.bno, t.name, t.author, t.press, t.fenlei, t.book_count);
	}

	file.close();

}
bool outreader(reader* readerhead)//保存读者文件
{
	fstream file("reader.txt", ios::out);
	if (!file)return false;
	reader* t = readerhead;
	while (t->next != nullptr)
	{
		for (int i = 0; i < t->next->count; i++)
			file << t->next->reader_name << '\n'
			<< t->next->borrow1[i].bno << '\n';

		t = t->next;
	}
	file.close();
	return true;

}
bool readreader()//读取读者文件
{
	fstream file("reader.txt", ios::in);
	if (!file)return false;
	string reader_name;
	int bno;
	book* h;
	reader* b1;
	while (!file.eof())
	{
		file >> reader_name;
		if (file.eof())break;
		file >> bno;
		if (file.eof())break;//判断是否读到文件的结尾符

		h = head;
		while (h->next != nullptr)
		{
			if (h->next->bno == bno)
			{
				break;
			}
			h = h->next;
		}
		if (h->next != nullptr)
		{
			h->next->borrow++;
			if (h->next->book_count > 0)
				h->next->book_count--;

		}
		b1 = found_reader(reader_name);
		if (b1 != nullptr)
		{
			b1->borrow1[b1->count].bno = bno;
			b1->count++;
		}
		else
		{
			reader* q = read;
			reader* p = new reader();
			p->reader_name = reader_name;
			p->next = q->next;
			q->next = p;
			p->borrow1[p->count].bno = bno;
			p->count++;
		}

	}
	file.close();
	return true;

}

void delete_node()//链表删除函数
{
	while (head != nullptr)
	{
		book* p = head;
		head = p->next;
		delete p;
	}
	while (name_head != nullptr)
	{
		book_name* p = name_head;
		name_head = p->next;
		delete p;
	}
	while (author_head != nullptr)
	{
		book_author* p = author_head;
		author_head = p->next;
		delete p;
	}
	while (press_head != nullptr)
	{
		book_press* p = press_head;
		press_head = p->next;
		delete p;
	}
	while (read != nullptr)
	{
		reader* p = read;
		read = p->next;
		delete p;
	}
	//删除旧表


}

