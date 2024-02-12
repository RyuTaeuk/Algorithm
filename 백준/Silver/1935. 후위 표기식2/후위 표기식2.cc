#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

double operate(double x, double y, char op) {
	double ans;
	if (op == '+') {
		ans = x + y;
	}
	else if (op == '-') {
		ans = x - y;
	}
	else if (op == '*') {
		ans = x * y;
	}
	else if (op == '/') {
		ans = x / y;
	}
	else {
		printf("An error occured.\n");
		ans = 0;
	}
	return ans;
}

int main() {
	double nums[27];
	double x, y, ans;
	int n;
	string q;
	stack<double> st;

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
			y = st.top();
			st.pop();
			x = st.top();
			st.pop();
			ans = operate(x, y, q[i]);
			st.push(ans);
		}
	}

	printf("%.2f\n", ans);
	return 0;
}