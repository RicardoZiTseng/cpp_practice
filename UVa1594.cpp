#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int fab_int(int a){
	if (a < 0) return -a;
	else return a;
}

void gener_gucci(const vector<int>& v1, vector<int>& v2){
	for (int i = 0; i < v1.size(); i++){
		if (i == v1.size()-1 ){
			v2.push_back(fab_int(v1[0] - v1[i]));
		}
		else{
			v2.push_back(fab_int(v1[i + 1] - v1[i]));
		}
	}
}

void print(const vector<int>& v){
	cout << "(";
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << ",";
	}
	cout << ")->";
}

bool equal_vector(const vector<int>& a1, const vector<int>& a2){
	int iter_num = a1.size();
	bool result = true;		//true代表相等
	for (int i = 0; i < iter_num; i++){
		if (a1[i] != a2[i])
		{
			result = false;		//false代表不相等
			break;
		}
	}
	return result;
}


int main(){
	int n;
	vector<int>v00,v0, v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++){
		int num;
		cin >> num;
		v1.push_back(num);
		v0.push_back(num);
		v00.push_back(0);
	}
	print(v1);
	gener_gucci(v1, v2);
	print(v2);
	while (!equal_vector(v00, v2) && !equal_vector(v0, v2)){
		v1 = v2;
		v2.clear();
		gener_gucci(v1, v2);
		print(v2);
	}
	cout << endl;
	if (equal_vector(v00, v2)) cout << "最终会变成0.";
	else if (equal_vector(v0, v2)) cout << "会循环.";
	return 0;
}
