//UVa230		还没debug
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> books_shelved;
vector<string> books_borrowed;
vector<string> books_returned;

void parse_book(const string& s, string& book_name, string& book_author){
	int k = s.find('#');
	book_name = s.substr(0, k);
	book_author = s.substr(k + 1);
}

bool compare1(string& s1, string& s2){		//按作者名排序
	string author1, name1;
	string author2, name2;
	parse_book(s1, name1, author1);
	parse_book(s2, name2, author2);
	return author1 < author2;
}

bool compare2(string& s1, string& s2){		//按书名排序
	string author1, name1;
	string author2, name2;
	parse_book(s1, name1, author1);
	parse_book(s2, name2, author2);
	return name1 < name2;
}

void sort_book(vector<string>& v){
	////按照作者名来排序
	//sort(v.begin(), v.end(), compare1);
	////按照书名来排序
	//sort(v.begin(), v.end(), compare2);
	sort(v.begin(), v.end(), compare2);
}

void borrow_book(string& s){
	auto it = books_shelved.begin();
	while (it != books_shelved.end()){
		if (*it == s){
			books_shelved.erase(it);
			books_borrowed.push_back(s);
			break;
		}
		else
			++it;
	}
	if (it == books_shelved.end()){
		cout << "This book has been borrowed or is not on the shelves." << endl;
	}
}

void return_book(string& s){
	auto it = books_borrowed.begin();
	while (it != books_borrowed.end()){
		if (*it == s){
			books_borrowed.erase(it);
			break;
		}
		else
			++it;
	}
	books_returned.push_back(s);
}

void shelve_book(){
	auto it = books_returned.begin();
	while (it != books_returned.end()){
		string temp = *it;
		vector<string>::iterator it2 = books_shelved.begin();
		while (it2 != books_shelved.end()){
			string temp2 = *it2;
			int count = 0;
			if (compare2(temp2, temp)){
				count++;
				++it2;
				continue;
			}
			else{
				cout << temp << " location:" << count << endl;
				break;
			}
		}
		++it;
	}
}

int main(){
	string s;
	int n_op;
	while (cin >> s && s != "END"){			//书名与作者的输入方式是这样的：HarryPotter#Rolly
		books_shelved.push_back(s);
	}
	sort_book(books_shelved);
	cout << "enter the numbers of operation." << endl;
	cin >> n_op;
	for (int i = 0; i < n_op; i++){
		string op, s_book;
		cin >> op;
		if (op[0] == 'B'){
			cin >> s_book;
			borrow_book(s_book);
		}
		if (op[0] == 'R'){
			cin >> s_book;
			return_book(s_book);
		}
		if (op[0] == 'S'){
			shelve_book();
		}
	}
	return 0;
}
