#include <iostream>
#include <deque>

using namespace std;

const int max_size = 10000;
deque<int> q_iter;  //存放着任务编号的队列
int map_priority[max_size]; //存放着对应编号的优先级

bool if_complete(int iter){
	bool result = true;			//true代表能执行
	for (int i = 0; i < q_iter.size(); i++){
		if (iter == q_iter[i])
			continue;
		if (map_priority[iter] < map_priority[q_iter[i]]){
			result = false;
			break;
		}
	}
	return result;
}

int main(){
	int priority, n1, n2, time = 0;
	cin >> n1;
	for (int i = 0; i < n1; i++){
		cin >> priority;
		q_iter.push_back(i);
		map_priority[i] = priority;
	}
	cin >> n2;
	while (true){
		bool result = if_complete(q_iter.front());
		if (!result){
			int temp = q_iter.front();
			q_iter.pop_front();
			q_iter.push_back(temp);
		}
		else if (result){
			q_iter.pop_front();
			time += 1;
		}
		if (q_iter.front() == n2 && if_complete(n2)){
			time += 1;
			break;
		}
	}
	cout << time;
	return 0;
}
