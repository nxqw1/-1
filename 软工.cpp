#include"��.h"

book* head = new book();
book_name* name_head = new book_name();
book_author* author_head = new book_author();
book_press* press_head = new book_press();
reader* read = new reader();

void usermain()
{

	int a1 = 1;//ͼ�����whileѭ��ѡ��
	int a2 = 1;//ͼ����Ϣwhileѭ��ѡ��
	bool flag = false;
	int bno;//���
	string name;//����
	string author;//����
	string press;//������
	string fenlei;//����
	int book_count;//����
	book* p1;
	reader* p;
	while (a1 != 0)
	{
		cout << endl << "\t\t\t**ͼ�����**" << endl;
		cout << "\t\t\t1.ͼ �� �� Ϣ �� �� " << endl;
		cout << "\t\t\t2.��ȡ�洢��ͼ����Ϣ" << endl;
		cout << "\t\t\t3.�鿴���ж�����Ϣ" << endl;
		cout << "\t\t\t0.�� �� " << endl;
		cout << " ��ѡ��";
		cin >> a1;
		switch (a1)
		{
		case 1:
			a2 = 1;
			while (a2 != 0)
			{
				cout << "\n\t\t\t** ͼ �� �� Ϣ **" << endl;
				cout << " \t\t\t1.�� �� " << endl;
				cout << "\t\t\t2.�������������� " << endl;
				cout << " \t\t\t3.������Ų��� " << endl;
				cout << " \t\t\t4.�������� " << endl;
				cout << " \t\t\t5.�������ֲ��� " << endl;
				cout << " \t\t\t6.���������ֲ��� " << endl;
				cout << " \t\t\t7.�������������ߡ���������Ϣ���� " << endl;
				cout << " \t\t\t8.����ͼ����Ϣ " << endl;
				cout << " \t\t\t0.�� �� " << endl;
				cout << " ��ѡ��";
				cin >> a2;

				switch (a2)
				{
				case 1://�鼮������

					cout << endl << "������ţ�";
					cin >> bno;
					cout << "����������";
					cin >> name;
					cout << "�������ߣ�";
					cin >> author;
					cout << "��������磺";
					cin >> press;
					cout << "������ࣺ";
					cin >> fenlei;
					cout << "����������";
					cin >> book_count;

					inc_book(bno, name, author, press, fenlei, book_count);//�ռ���Ϣ������⺯������������

					break;
				case 2://�������������������鼮

					p1 = head;//ָ��ָ�����ͷָ��
					if (p1->next == nullptr)cout << "δ��ȡ���鼮" << endl;
					while (p1->next != nullptr)
					{
						print_book(p1->next);
						p1 = p1->next;
					}
					break;
				case 3://������Ų���
					cout << '\n' << "������ţ�";
					cin >> bno;
					p1 = found_bno(bno);//������Ų��Һ���
					if (p1->next == nullptr)
					{
						cout << "δ�ҵ����鼮��" << endl;
					}
					break;
				case 4://������������
					cout << '\n' << "����������";
					cin >> name;
					found_name(name); //�����������Һ���������������������
					break;
				case 5://�����������ֲ���
					cout << '\n' << "������������:";
					cin >> author;
					found_author(author);//�����������ֲ��Һ���������������������
					break;
				case 6://���ճ��������ֲ���
					cout << '\n' << "�������������:";
					cin >> press;
					found_press(press);//���ó�������Һ��������ó�������������

					break;
				case 7://���������������
					cout << '\n' << "����������";
					cin >> name;
					cout << "������������:";
					cin >> author;
					cout << "�������������:";
					cin >> press;
					p1 = found_book(name, author, press);//���ò��Һ��������������������ٲ���
					if (p1 == nullptr)
					{
						cout << "δ�ҵ����鼮��" << endl;
					}
					else
					{
						cout << "�ҵ��鼮����Ϣ���£�" << endl;
						print_book(p1);
					}
					break;
				case 8://�����鼮��Ϣ���ļ�
					flag = outbook(head);

					if (flag)cout << "\t\t**�����鼮��Ϣ�ɹ�**" << endl;

					break;
				case 0:
					break;
				}
			}
			break;
		case 2://��ȡ�ļ���ͼ����Ϣ
			delete_node();
			head = new book;
			name_head = new book_name;
			author_head = new book_author;
			press_head = new book_press;
			read = new reader();
			flag = readbook();//���ö�ȡ����

			if (flag) {
				cout << "\t\t**���ݶ�ȡ�ɹ�**" << endl;
				readreader();//���ö�����Ϣ��ȡ����
			}
			else
			{
				cout << "\t\t**��δ���鼮��Ϣ**" << endl;
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
	int a1 = 1;//����whileѭ��ѡ��
	/*int a2 = 1;*///����whileѭ��ѡ��
	bool flag = false;
	int select = 1;
	int bno;//���
	string name;//����
	string author;//����
	string press;//������
	string fenlei;//����
	int book_count;//����
	string reader_name;//���߱��
	book* p1;
	reader* b1;
	book* h;

	delete_node();//��������ɾ��������ɾ�����������鼮��Ϣ
	head = new book();
	name_head = new book_name();
	author_head = new book_author();
	press_head = new book_press();
	readbook();//�����鼮��Ϣ��ȡ����
	read = new reader();
	readreader();//���ö�����Ϣ��ȡ����
	while (a1 != 0)
	{
		cout << endl << "\t\t\t**����**" << endl;
		cout << "\t\t\t1.�����鼮��Ϣ " << endl;
		cout << "\t\t\t2.����" << endl;
		cout << "\t\t\t3.����" << endl;
		cout << "\t\t\t4.���������Ϣ" << endl;
		cout << "\t\t\t5.��������ļ�" << endl;
		cout << "\t\t\t6.��ȡ�����ļ�" << endl;
		cout << "\t\t\t0.�� �� " << endl;
		cout << " ��ѡ��";
		cin >> a1;
		switch (a1)
		{
		case 1://�����鼮��Ϣ
			select = 1;
			while (select != 0)
			{
				cout << endl << "1����������ѯ��2�����������ֲ�ѯ��3���ó������ѯ��4����������Ϣ��ѯ��5���������ͼ����Ϣ��6������Ų�ѯ��0������" << endl;
				cout << " ��ѡ��";
				cin >> select;
				if (select == 1) {
					cout << "����������";
					cin >> name;
					p1 = found_name(name);//������������
					
				}
				else if (select == 2)
				{
					cout << "������������:";
					cin >> author;
					p1 = found_author(author);//�������߲���
					
				}
				else if (select == 3)
				{
					cout << "�������������:";
					cin >> press;
					p1 = found_press(press);//���ճ��������
					
				}
				else if (select == 4)
				{
					cout << "����������";
					cin >> name;
					cout << "������������:";
					cin >> author;
					cout << "�������������:";
					cin >> press;
					p1 = found_book(name, author, press);//�������������ߡ����������
					if (p1 == nullptr)
					{
						cout << "\t\t**δ�ҵ����鼮**" << endl;
					}
					else
					{
						cout << "\t\t**�ҵ��鼮����Ϣ����**" << endl;
						print_book(p1);
					}
				}
				else if (select == 5)
				{
					p1 = head;
					while (p1->next != nullptr)
					{
						print_book(p1->next);//��������鼮��Ϣ
						p1 = p1->next;
					}
				}
				else if (select == 6)
				{
					cout << "������ţ�";
					cin >> bno;
					p1 = found_bno(bno);//������Ų���
					if (p1->next == nullptr)
					{
						cout << "\t\t**û�и���ŵ��鼮**" << endl;
					}
				}
			}
			break;
		case 2://����
			cout << endl << "��������߱�ţ�";
			cin >> reader_name;
			cout << "���������������ţ�";
			cin >> bno;
			h = head;
			while (h->next != nullptr)//�����ҵ������鼮�ĵ�ַ
			{
				if (h->next->bno == bno)
				{
					break;
				}
				h = h->next;
			}
			if (h->next != nullptr)//���ҵ��鼮
			{

				if (h->next->book_count > 0)//���������0��
				{
					h->next->borrow++;//����������+1
					h->next->book_count--;//������-1
				}
				else
				{
					cout << "\t\t**�����޿��**" << endl;
					break;
				}
			}
			else
			{
				cout << "\t\t**û�и���**" << endl;
				break;
			}
			b1 = found_reader(reader_name);//���ն��߱�Ų����Ƿ��Ѵ��ڸö���
			if (b1 != nullptr)//�ҵ�
			{
				b1->borrow1[b1->count].bno = bno;//�������������ӽ�borrow1[]������

				b1->count++;//����������+1
			}
			else//δ�ҵ����½��ö�����Ϣ
			{
				reader* q = read;//����ͷָ�뿪ʼ����
				reader* p = new reader();
				p->reader_name = reader_name;//���߱��
				p->next = q->next;//�����������ͷ
				q->next = p;
				p->borrow1[p->count].bno = bno;//�������������ӽ�borrow1[]������
				p->count++;
			}
			cout << "**�� �� �� ��**" << endl;//����һ���������ж��߳ɹ��赽�鼮
			outreader(read);//����ɹ�����Ϣ��������
			break;
		case 3://����
			cout << '\n' << "��������߱�ţ�";
			cin >> reader_name;
			cout << "�������뻹�������ţ�";
			cin >> bno;
			h = head;//h=�鼮��ͷָ��

			b1 = found_reader(reader_name);//�ҵ��ö�������
			if (b1 != nullptr)//���ҵ��ö���
			{
				for (int i = 0; i < b1->count; i++)
				{
					if (b1->borrow1[i].bno == bno)
					{
						for (int t = i; t < b1->count; t++)
						{
							b1->borrow1[i].bno = b1->borrow1[i + 1].bno;//�����ڶ����ļ��е��鼮��Ϣ�ҵ���ɾ����Ϣ
						}
						break;
					}
				}
				b1->count--;
				while (h->next != nullptr)//�ҵ��ö����뻹����鼮
				{
					if (h->next->bno == bno)
					{
						break;
					}
					h = h->next;
				}
				if (h->next != nullptr && h->next->borrow > 0)//�������б���
				{
					h->next->borrow--;
					h->next->book_count++;
				}
				else//������δ�����
				{
					cout << "\t\t**û�н����**" << endl;
					break;
				}
			}
			else//��δ�ҵ����ߣ���
			{
				cout << "\t\t**û�н����**" << endl;
				break;
			}

			cout << "\t\t**����ɹ�**" << endl;//����ɹ�����Ϣ��������
			outreader(read);
			break;
		case 4://ͨ�����߱�Ų��Ҷ��������鼮
			cout << '\n' << "��������߱�ţ�";
			cin >> reader_name;
			b1 = read;
			while (b1->next != nullptr)//�ҵ��ö��߱����Ϣ
			{
				if (b1->next->reader_name == reader_name)
				{
					print_reader(b1->next);
					break;
				}
				b1 = b1->next;
			}
			break;
		case 5://���������Ϣ

			flag = outreader(read);
			if (flag)cout << "\t\t**���������Ϣ�ɹ�**" << endl;
			break;
		case 6://��ȡ������Ϣ

			delete_node();
			head = new book;
			name_head = new book_name;
			author_head = new book_author;
			press_head = new book_press;
			read = new reader();
			flag = readbook();//���ö�ȡ����

			if (flag) {
				cout << "\t\t**���ݶ�ȡ�ɹ�**" << endl;
				readreader();//���ö�����Ϣ��ȡ����
			}
			else
			{
				cout << "\t\t**��δ���鼮��Ϣ**" << endl;
			}
			break;
		case 0:
			break;
		}
	}
}
bool inc_book(int bno, string name, string author, string press, string fenlei, int book_count)//����鼮
{
	book* ptr = new book();//�������
	ptr->bno = bno;
	book* h = head;


	ptr->name = name;
	ptr->author = author;
	ptr->press = press;
	ptr->fenlei = fenlei;
	ptr->book_count = book_count;//¼��ͼ����Ϣ

	book* a = found_book(name, author, press);//�鿴�Ƿ�����ͬ�鼮
	if (a != nullptr)//����
	{
		cout << "�����Ѵ��ڣ��������" << endl;
		a->book_count += book_count;
	}
	else {//δ����
		while (h->next != nullptr)
		{
			if (h->next->bno == bno)
			{
				cout << "���иñ�ŵ��飬������������:" << endl;
				cin >> ptr->bno;
				break;
			}
			h = h->next;
		}

		h = head;

		while (h->next != nullptr)//����ʱֱ�Ӱ����������
		{
			if (h->next->bno > ptr->bno)
			{
				ptr->next = h->next;
				h->next = ptr;//���������������
				break;
			}
			h = h->next;
		}
		if (h->next == nullptr)
		{
			ptr->next = h->next;
			h->next = ptr;//���������������
		}



		book_name* p = name_head;//������������
		bool flag = false;//false��ʾû�и���������
		while (p->next != nullptr)//ѭ���������ҵ���ͬ��������������������������
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
			book_name* ss = new book_name;//ѭ��������û���ҵ���ͬ�������������½���������
			ss->name = ptr->name;
			ss->head = ptr;
			ss->next = name_head->next;
			name_head->next = ss;
			flag = false;
		}

		flag = false;
		book_author* p1 = author_head;//������������
		while (p1->next != nullptr)//ѭ���������ҵ���ͬ��������������������������
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
		if (!flag)//ѭ��������û���ҵ���ͬ�������������½���������
		{
			book_author* ss = new book_author;
			ss->name = ptr->author;
			ss->head = ptr;
			ss->next = author_head->next;
			author_head->next = ss;
			flag = false;
		}

		flag = false;
		book_press* p2 = press_head;//��������������
		while (p2->next != nullptr)//ѭ���������ҵ���ͬ����������������������������
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
		if (!flag)//ѭ��������û���ҵ���ͬ���������������½�����������
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

book* found_name(string name)//ʹ�����ֲ����鼮
{
	book_name* p = name_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//������������������Ӧ��ͷָ��
	{
		if (p->name == name) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\tδ�ҵ����������鼮" << endl;//δ�ҵ�
	else
		while (b1 != nullptr)//�ҵ���������и������鼮
		{
			print_book(b1);
			b1 = b1->name_next;
		}
	return nullptr;
}
book* found_author(string author)//ʹ���������ֲ����鼮
{
	book_author* p = author_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//��������������Ӧ��ͷָ��
	{
		if (p->name == author) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\tδ�ҵ��������鼮" << endl;//δ�ҵ�
	else
		while (b1 != nullptr)//������и������鼮
		{
			print_book(b1);
			b1 = b1->author_next;
		}
	return nullptr;
}
book* found_press(string press)//ʹ�ó��������ֲ����鼮
{
	book_press* p = press_head->next;
	book* b1 = nullptr;
	while (p != nullptr)//����������Ӧ��ͷָ��
	{
		if (p->name == press) {
			b1 = p->head;
			break;
		}
		p = p->next;
	}
	if (b1 == nullptr)cout << "\t\tδ�ҵ��ó������鼮" << endl;//δ�ҵ�
	else
		while (b1 != nullptr)//������иó������鼮
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
	while (p_name != nullptr)//����������Ӧ��ͷָ��
	{
		if (p_name->name == name) {
			b_name = p_name->head;
			break;
		}
		p_name = p_name->next;
	}



	book_author* p_author = author_head->next;
	book* b_author = nullptr;
	while (p_author != nullptr)//�������߶�Ӧ��ͷָ��
	{
		if (p_author->name == author) {
			b_author = p_author->head;
			break;
		}
		p_author = p_author->next;
	}


	book_press* p_press = press_head->next;
	book* b_press = nullptr;
	while (p_press != nullptr)//���ҳ������Ӧ��ͷָ��
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
book* found_bno(int bno)//ͨ����Ų���ͼ��
{
	book* h = head;
	while (h->next != nullptr)
	{
		if (h->next->bno == bno)
		{
			print_book(h->next);//�����ͼ��
			break;
		}
		h = h->next;
	}
	return h;
}
reader* found_reader(string name)//���ö��߱���ҵ�������Ϣ
{
	reader* q = read;
	while (q->next != nullptr)
	{
		if (q->next->reader_name == name)
			return q->next;//�ҵ��򷵻ظö��ߵ�ָ��
		q = q->next;
	}
	return nullptr;
}

void print_book(book* a1)//����鼮��Ϣ
{
	if (a1 != nullptr)
	{
		cout << "���:" << a1->bno << "    ";
		cout << "����:" << a1->name << "    ";
		cout << "����:" << a1->author << "    ";
		cout << "������:" << a1->press << "    ";
		cout << "����" << a1->fenlei << "    ";
		cout << "���:" << a1->book_count << "    ";
		cout << "�������:" << a1->borrow << endl;
	}
}
void print_reader(reader* a1)//������߽�����Ϣ
{
	for (int i = 0; i < a1->count; i++)//���������鼮���
		cout << a1->reader_name << "  ������ţ�" << a1->borrow1[i].bno << endl;
}


bool outbook(book* head)//�����鼮�ļ�
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
	cout << "**����ͼ����Ϣ�ɹ�**" << endl;
}
bool readbook()//��ȡ�鼮�ļ�
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
bool outreader(reader* readerhead)//��������ļ�
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
bool readreader()//��ȡ�����ļ�
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
		if (file.eof())break;//�ж��Ƿ�����ļ��Ľ�β��

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

void delete_node()//����ɾ������
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
	//ɾ���ɱ�


}

