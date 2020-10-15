#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > words;
vector<vector<bool> > edge;

int ComputeParity(const string& word) {
	int num_reverse = 0;
	for (int i = 0; i < word.size(); ++i) {
		for (int j = i + 1; j < word.size(); ++j) {
			if (word[i] > word[j]) {
				++num_reverse;
			}
		}
	}
	return num_reverse % 2;
}

bool Swappable(const string& a, const string& b) {
	int num_diff = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			++num_diff;
		}
	}
	return num_diff == 2;
}

bool Find(const int i, const vector<vector<bool> >& edge, vector<bool>& visited, vector<int>& result) {
	for (int j = 0; j < edge[i].size(); ++j) {
		if (edge[i][j] && !visited[j]) {
			visited[j] = true;
			if (result[j] == -1 || Find(result[j], edge, visited, result)) {
				result[j] = i;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch(const vector<vector<bool> >& edge, const int m, const int n) {
	int max_match = 0;
	vector<int> result(n, -1);
	for (int i = 0; i < m; ++i) {
		vector<bool> visited(n, false);
		if (Find(i, edge, visited, result)) {
			++max_match;
		}
	}
	return max_match;
}

int main() {
	words.resize(2);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		int parity = ComputeParity(word);
		words[parity].push_back(word);
	}
	edge.resize(words[0].size());
	for (int i = 0; i < words[0].size(); ++i) {
		edge[i].resize(words[1].size());
		for (int j = 0; j < words[1].size(); ++j) {
			edge[i][j] = Swappable(words[0][i], words[1][j]);
		}
	}
	int max_match = MaxMatch(edge, words[0].size(), words[1].size());
	cout << n - max_match << endl;
	return 0;
}