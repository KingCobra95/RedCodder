#include <bits/stdc++.h>
using namespace std;

void initialize_portion(map<string, int> &portion) {
	portion["FAT"] = 2;
	portion["FIBER"] = 4;
	portion["CARB"] = 2;
}
string get_cat(string ing) {
	if (ing[0] == 'C') return "CARB";
	if (ing[0] == 'F') {
		if (ing[1] == 'I') return "FIBER";
		return "FAT";
	}

	return NULL;
}
void remove_ing(map<string, multiset<int, greater <int> > > &store, int ing_to_use, string cat) {
	multiset<int, greater<int> >::iterator it;

	while (ing_to_use--) {
		it = store[cat].begin();

		int val = *it;
		store[cat].erase(it);
		if (val > 1) {
			store[cat].insert(val-1);	
		}
	}	
}
void print_c(map<string, multiset<int, greater <int> > > store, string cat) {
	cout << cat << " size: " << store[cat].size() << endl;

	multiset<int, greater <int> >::iterator it = store[cat].begin();
	while (it != store[cat].end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main() {

	int N, M;
	string ingredient, ans;
	char prev = 'Z';
	map<string, multiset<int, greater <int> > > store;
	map<string, int> portion;

	initialize_portion(portion);

	cin >> N;
	cin >> M;
	for (int i = 0 ; i < N ; i++) {
		cin >> ingredient;

		string cat = get_cat(ingredient);
		store[cat].insert(portion[cat]);

		if (prev != 'X' && store["FAT"].size() > 1 && store["FAT"].size()+store["FIBER"].size() >= M) {
			ans += "X";

			remove_ing(store, 2, "FAT");
			int cnt = M-2;
			while (cnt--) {
				if (store["FAT"].size()) {
					remove_ing(store, 1, "FAT");
				} else if (store["FIBER"].size()) {
					remove_ing(store, 1, "FIBER");
				}
			}

			prev = 'X';
		} else if (prev != 'Y' && store["FIBER"].size() > 0 && store["CARB"].size() > 0 && store["CARB"].size()+store["FIBER"].size() >= M) {
			ans += "Y";

			remove_ing(store, 1, "FIBER");
			remove_ing(store, 1, "CARB");

			int cnt = M-2;
			while (cnt--) {
				if (store["CARB"].size()) {
					remove_ing(store, 1, "CARB");
				} else if (store["FIBER"].size()) {
					remove_ing(store, 1, "FIBER");
				}
			}

			prev = 'Y';
		} else {
			ans += "-";
		}
		
		//rint_c(store, "FAT");
		//print_c(store, "FIBER");
		//print_c(store, "CARB");
		//cout << endl;
	}

	cout << ans << endl;

	return 0;
}