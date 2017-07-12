#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000 + 5;
int right_pos[maxn], left_pos[maxn];

void link(int L, int R){
	right_pos[L] = R;
	left_pos[R] = L;
}

void op_1(int num1, int num2){
	/*int temp1 = left_pos[num1];
	right_pos[temp1] = right_pos[num1];
	right_pos[num1] = num2;
	int temp2 = left_pos[num2];
	right_pos[temp2] = num1;*/
	int num1_l = left_pos[num1];
	int num1_r = right_pos[num1];
	int num2_l = left_pos[num2];
	link(num1_l, num1_r);
	link(num2_l, num1);
	link(num1, num2);
}

void op_2(int num1, int num2){
	int num1_l = left_pos[num1];
	int num1_r = right_pos[num1];
	int num2_r = right_pos[num2];
	link(num1_l, num1_r);
	link(num2, num1);
	link(num1, num2_r);
}

void op_3(int num1, int num2){
	int num1_l = left_pos[num1];
	int num1_r = right_pos[num1];
	int num2_l = left_pos[num2];
	int num2_r = right_pos[num2];
	link(num2_l, num1);
	link(num1, num2_r);
	link(num1_l, num2);
	link(num2, num1_r);
}

int main(){
	int n, m, inv=0, count_n = 0;
	while (scanf_s("%d %d", &n, &m) == 2){
		memset(right_pos, 0, maxn);
		memset(left_pos, 0, maxn);
		for (int i = 1; i <= n; i++){
			left_pos[i] = i - 1;
			right_pos[i] = (i + 1)%(n+1);
		}
		left_pos[0] = n;
		right_pos[0] = 1;
		while (m--){
			int op, X, Y;
			scanf_s("%d", &op);
			if (op == 4) inv = !inv;
			else{
				scanf_s("%d %d", &X, &Y);
				if (op != 3 && inv) op = 3 - op;

				if (op == 1){
					if (X == left_pos[Y])
						continue;
					else{
						op_1(X, Y);
					}
				}
				if (op == 2){
					if (right_pos[X] == Y)
						continue;
					else{
						op_2(X, Y);
					}
				}
				if (op == 3){
					if (right_pos[X] == Y){
						int temp1 = left_pos[X];
						int temp2 = right_pos[Y];
						link(Y, X);
						link(temp1, Y);
						link(X, temp2);
					}
					else{
						op_3(X, Y);
					}
				}
			}
		}
		int b = 0;
		long long result = 0;
		for (int i = 1; i <= n; i++){
			b = right_pos[b];
			if (i % 2 == 1) result += b;
		}
		if (inv && n % 2 == 0){
			result = (long long)n*(n + 1) / 2 - result;
		}
		printf("Case %d: %lld\n", ++count_n, result);
	}
	return 0;
}
