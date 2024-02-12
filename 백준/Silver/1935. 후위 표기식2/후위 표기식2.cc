#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int main() {
	double nums[27];
	stack<double> st;
	int n;
	double ans = 0.0;
	double x, y;
	string q;

	cin >> n;
	cin >> q;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < q.length(); i++) {
		if (q[i] >= 'A' && q[i] <= 'Z') {
			st.push(nums[q[i] - 'A']);
		}
		else {
			if (q[i] == '+') {
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				ans = x + y;
				st.push(ans);
			}
			if (q[i] == '-') {
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				ans = x - y;
				st.push(ans);
			}
			if (q[i] == '*') {
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				ans = x * y;
				st.push(ans);
			}
			if (q[i] == '/') {
				y = st.top();
				st.pop();
				x = st.top();
				st.pop();
				ans = (double)x / y;
				st.push(ans);
			}
		}
	}


	printf("%.2f\n", ans);
	return 0;
}