#pragma once
#include<string>
#include<iostream>
using namespace std;
template<class K, class V>
struct BSTreeNode {
	K _key;
	V _value;
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	BSTreeNode(K key,V value)
		:_key(key),
		_value(value),
		_left(nullptr),
		_right(nullptr)
	{}
};
template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value) {
		if (_root == nullptr) {
			_root = new Node(key, value);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		if (key > parent->_key) {
			parent->_right = new Node(key, value);
			return true;
		}
		else {
			parent->_left = new Node(key, value);
			return true;
		}
	}
	Node* Find(const K& key) {
		Node* cur = _root;
		while (cur) {
			if (key > cur->_key) {
				cur = cur->_right;
			}

			else if (key < cur->_key) {
				cur = cur->_left;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}
	bool Erase(const K& key) {
		if (key == _root->_key) {
			delete _root;
			_root == nullptr;
			return true;
		}
		Node* parent = _root;
		Node* cur = _root;
		while (cur) {
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else {// 找到了，进行删除
				if (cur->_left == nullptr) {
					if (cur == parent->_left) {
						parent->_left = cur->_right;
						delete cur;
						return true;
					}
					else {
						parent->_right = cur->_right;
						delete cur;
						return true;
					}
				}
				else if (cur->_right == nullptr) {
					if (cur == parent->_left) {
						parent->_left = cur->_left;
						delete cur;
						return true;
					}
					else {
						parent->_right = cur->_left;
						delete cur;
						return true;
					}
				}
				else {// 被删除的节点有两棵子树,找到被删节点右子树的最小节点，也就是右子树的最左节点，替代被删节点位置
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left) {
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					cur->_key = rightMin->_key;
					cur->_value = rightMin->_value;
					if (rightMin == rightMinParent->_left) {
						rightMinParent->_left = rightMin->_right;
					}
					else {
						rightMinParent->_right = rightMin->_right;
					}
					delete rightMin;
					return true;
				}
			}
		}
		return false;
	}
	void _InOrder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_left);
		cout << root->_value << " ";
		_InOrder(root->_right);
	}
	void InOrder() {
		_InOrder(_root);
	}
private:
	Node* _root = nullptr;
};

void TestBSTree()
{


	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
	cout << endl;

	countTree.Erase("西瓜");
	countTree.InOrder();
	cout << endl;

	BSTree<string, string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "单词拼写错误" << endl;
		}
	}
}