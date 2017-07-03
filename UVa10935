#include <iostream>
#include <deque>

using namespace std;

int main(){
	int n;
	deque<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++){
		v.push_back(i);
	}
	while (v.size() >= 2){
		int temp;
		temp = v[0];
		cout << temp << endl;
		v.pop_front();
		temp = v[0];
		v.pop_front();
		v.push_back(temp);
	}
	cout << endl << "输出剩余元素：";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
