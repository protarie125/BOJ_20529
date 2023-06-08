#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int t;
int n;
vector<string> strs;

int ans;
vector<string> check;

int dist(int a, int b) {
	auto ret = 0;
	for (auto i = 0; i < 4; ++i) {
		if (check[a][i] != check[b][i]) {
			ret += 1;
		}
	}

	return ret;
}

int calc() {
	auto ret = 0;
	ret += dist(0, 1);
	ret += dist(1, 2);
	ret += dist(2, 0);

	return ret;
}

void part(int b) {
	if (3 == check.size()) {
		const auto na = calc();
		if (na < ans) {
			ans = na;
		}

		return;
	}

	for (auto i = b; i < n; ++i) {
		check.push_back(strs[i]);
		part(i + 1);
		check.pop_back();
	}
}

int solve() {
	if (32 < n) {
		return 0;
	}

	ans = 1000;
	check.clear();

	part(0);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> t;
	while (0 < (t--)) {
		cin >> n;
		strs = vector<string>(n);
		for (auto&& str : strs) {
			cin >> str;
		}

		cout << solve() << '\n';
	}

	return 0;
}