#include <bits/stdc++.h>
using namespace std;
int dq[100001];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int how = 0, head = 0, tail = 0, size, num;
		string oper;
		char ch;
		cin >> oper;
		cin >> size;
		cin >> ch;

		for (int i = 0; i < size; i++)
		{
			cin >> num;
			cin >> ch;
			dq[tail++] = num;
		}
		if (size == 0)
			cin >> ch;

		for (char c : oper) {
			if (c == 'R') how = how > 0 ? 0 : 1;
			else {
				if (head == tail)
				{
					how = -1;
					break;
				}
				else if (how > 0) --tail;
				else ++head;
			}
		}
		if (how < 0)
			printf("error\n");
		else if (size==0 || head==tail) {
			printf("[]\n");
			continue;
		}
		else {
			printf("[");
			if (how == 0) {
				while (1) {
					printf("%d", dq[head++]);
					if (head == tail) break;
					else printf(",");
				}
			}
			else {
				while (1) {
					printf("%d", dq[--tail]);
					if (head == tail) break;
					else printf(",");
				}
			}
			printf("]\n");
		}
	}
}