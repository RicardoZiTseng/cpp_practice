#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int a[100000];
int fibo(int n){
	a[0] = 1;
	a[1] = 1;
	a[n] = a[n - 1] + a[n - 2];
	return a[n];
}

void to_string_1(string& result, const int& t){
	stringstream oss;
	oss << t;
	oss >> result;
}

int main(){
	int n=0, count=0;
	string n_str;
	cin >> n;
	to_string_1(n_str, n);
	while (count <= 100000){
		//cout << count << endl;
		int int_temp = fibo(count);
		string str_temp;
		to_string_1(str_temp, int_temp);
		if (str_temp.find(n_str) == 0){
			cout << count;
			break;
		}
		else{
			count++;
		}
		if (count > 100000){
			cout << "Not found." << endl;
		}
	}
	return 0;
}
