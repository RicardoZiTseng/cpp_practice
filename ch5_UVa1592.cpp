#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef set<int> Set;
const int max_num = 10000 * 10;
vector<string> data_string;
map<string, int> IDcache;
map<Set, int> set_map;

int main(){
	int n, m;
	
	cout << "enter the col and row of this database." << endl;
	cin >> n >> m;
	cout << "enter " << n*m << "'s data" << endl;

	for (int i = 0; i < n*m; i++){				//这个循环是为了给字符串匹配ID
		string temp;
		cin >> temp;
		data_string.push_back(temp);
		if (!IDcache.count(temp)) IDcache[temp] = data_string.size() - 1;
		//cout << IDcache[temp] << endl;
	}
	
	for (int r = 1; r <= n; r++){
		for (int c1 = 1; c1 <= m; c1++){
			int idx1 = (r - 1) * m + c1 - 1;
			int ID1 = IDcache[data_string[idx1]];
			for (int c2 =c1+1; c2 <= m; c2++){
				Set s;
				int idx2 = (r - 1)*m + c2 - 1;
				int ID2 = IDcache[data_string[idx2]];
				s.insert(ID1);
				s.insert(ID2);

				if (!set_map.count(s)){
					set_map[s] = r;
				}
				else{
					cout << "exist:" << "r1=" << r << ", r2=" << set_map[s] << ",and c1=" << c1 << ",c2=" << c2;
					break;
				}
			}
		}
		if (r == n)
			cout << "not find." << endl;
	}

	return 0;
}
