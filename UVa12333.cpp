#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int fibo(int n){
	if (n == 0 || n == 1){
		return 1;
	}
	else{
		return fibo(n - 1) + fibo(n - 2);
	}
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
