#include <bits/stdc++.h>
using namespace std;
// 函数用于检查两行是否可以通过一次翻转相等
bool canEqualByFlip(const string& row1, const string& row2) {
	int mismatches = 0;
	for (size_t i = 0; i < row1.size(); ++i) {
		if (row1[i] != row2[i]) {
			++mismatches;
		}
	}
	// 如果不匹配的数量为0或4，那么可以通过翻转使其相等
	return mismatches == 0 || mismatches == 4;
}
int main() {	
	vector<string> matrix1(4), matrix2(4);
	// 读取第一个矩阵
	for (int i = 0; i < 4; ++i) {
		cin >> matrix1[i];
	}
	// 忽略空行
	string dummy;
	getline(cin, dummy);
	// 读取第二个矩阵
	for (int i = 0; i < 4; ++i) {
		cin >> matrix2[i];
	}
	// 尝试翻转行和列，检查是否可以使矩阵相等
	bool canEqual = true;
	for (int i = 0; i < 4 && canEqual; ++i) {
		canEqual &= canEqualByFlip(matrix1[i], matrix2[i]);
		if (!canEqual) {
			// 尝试翻转当前行
			for (char &ch : matrix1[i]) {
				ch = ch == '0' ? '1' : '0';
			}
			canEqual = canEqualByFlip(matrix1[i], matrix2[i]);	
		}
	}
	if (canEqual) {	
		cout << "Yahaha! You found me!" << endl;
	} else {
		// 检查所有列是否可以相等
		canEqual = true;
		for (int col = 0; col < 4 && canEqual; ++col) {
			string col1, col2;
			for (int row = 0; row < 4; ++row) {
				col1 += matrix1[row][col];
				col2 += matrix2[row][col];
			}
			canEqual &= canEqualByFlip(col1, col2);
			if (!canEqual) {
				// 尝试翻转当前列
				for (int row = 0; row < 4; ++row) {
					char &ch = matrix1[row][col];
					ch = ch == '0' ? '1' : '0';
				}
				canEqual = canEqualByFlip(col1, col2);
			}
		}
		cout << (canEqual ? "Yahaha! You found me!" : "Boo!") << endl;
	}
	return 0;
}
