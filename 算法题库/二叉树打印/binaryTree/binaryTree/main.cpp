/** 有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。
 *
 *  给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。
 *	保证结点数小于等于500。
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		vector<vector<int> > res;
		if (root == NULL)
			return res;
		TreeNode* last = root;
		TreeNode* nLast = NULL;
		queue<TreeNode*> q;
		q.push(root);
		vector<int> tmp;
		while (!q.empty()) {
			TreeNode* treeTemp = q.front();
			q.pop();
			if (treeTemp->left) {
				q.push(treeTemp->left);
				nLast = treeTemp->left;
			}
			if (treeTemp->right) {
				q.push(treeTemp->right);
				nLast = treeTemp->right;
			}
			tmp.push_back(treeTemp->val);
			if (treeTemp == last) {
				last = nLast;
				res.push_back(tmp);
				tmp.clear();
			}
		}

		return res;
	}
};

int main() {
	TreeNode* root = new TreeNode(0);
	TreeNode* node = NULL;
	queue<TreeNode*> q;
	q.push(root);
	for (int i = 0; i < 20; i++) {
		TreeNode* treeTemp = q.front();
		q.pop();
		if (treeTemp->left == NULL) {
			treeTemp->left = new TreeNode(2 * i + 1);
			q.push(treeTemp->left);
		}
		if (treeTemp->right == NULL) {
			treeTemp->right = new TreeNode(2 * i + 2);
			q.push(treeTemp->right);
		}
	}

	TreePrinter TP;
	vector<vector<int> > res = TP.printTree(root);
	/*cout << res.size() << endl;
	cout << res[0].size() << endl;*/
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << "  ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}