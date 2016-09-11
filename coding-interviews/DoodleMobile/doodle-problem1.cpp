#include <iostream>
#include <vector>
using namespace std;


struct node {
	struct node *next;
	int value;
};
struct node *swap(struct node *list);

// 将链表中的所有元素为奇数的节点移到元素为偶数节点的前面，
// 并使奇数之间顺序反转，
// 偶数之间顺序反转。
struct node* swap(struct node *list) {
	// 如果链表为空或者只有一个节点
	if (list == NULL || list->next == NULL) return list;
	struct node *oddhead = NULL;
	struct node *oddtail = NULL;
	struct node *evenhead = NULL;
	while (list != NULL) {
		struct node *pNode = list;
		list = list->next;

		// odd case
		if (pNode->value & 0x01) {
			pNode->next = oddhead;
			oddhead = pNode;
			if (oddtail == NULL) {
				oddtail = pNode;
			}
		}
		// even case
		else {
			pNode->next = evenhead;
			evenhead = pNode;
		}
	}

	// 奇数列表非空
	if (oddhead) {
		oddtail->next = evenhead;
		return oddhead;
	} else {
		return evenhead;
	}
}


// =====================================
// 测试
// =====================================
node* createList(const vector<int> &nums) {
	node* list = NULL;
	for (auto it = nums.rbegin(); it != nums.rend(); it++) {
		node* pNode = new node;
		pNode->value = *it;
		pNode->next = list;
		list = pNode;
	}
	return list;
}

void printList(node* list) {
	if (!list) return;
	cout << list->value;
	list = list->next;
	while (list) {
		cout << "->" << list->value;
		list = list->next;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> tests {{4, 5, 7, 1, 6}, {1}, {2, 1}, {}};
	for (int i = 0; i < tests.size(); i++) {
		cout << "\n=======================\n";
		cout << "test cast #" << i << endl;
		node* list = createList(tests[i]);
		cout << "Origin list:" << endl;
		printList(list);

		list = swap(list);
		cout << "After swap:" << endl;
		printList(list);
	}
	return 0;
}