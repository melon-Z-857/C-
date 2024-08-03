#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

namespace zxy
{
	// List�Ľڵ���
	template<class T>
	struct ListNode
	{
		T _val;
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		ListNode(const T& val = T())
			:_val(val),
			_pPre(nullptr),
			_pNext(nullptr)
		{}
	};

	//List�ĵ�������
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		PNode _pNode;
		ListIterator(PNode pNode = nullptr) {
			_pNode = pNode;
		}
		ListIterator(const Self& l) {
			_pNode = l._pNode;
		}
		T& operator*() {
			return _pNode->_val;
		}
		T* operator->() {
			return &(_pNode->_val);
		}
		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int) {
			auto tmp = *this;
			_pNode = _pNode->_pNext;
			return tmp;
		}
		Self& operator--() {
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self& operator--(int) {
			auto tmp = *this;
			_pNode = _pNode->_pPre;
			return tmp;
		}
		bool operator!=(const Self& l) {
			return !(_pNode == l._pNode);
		}
		bool operator==(const Self& l) {
			return (_pNode == l._pNode);
		}
	};

	//list��
	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;
	public:
		///////////////////////////////////////////////////////////////
		// List�Ĺ���
		void CreateHead() {
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		list() {
			CreateHead();
		}
		list(int n, const T& value = T()) {
			void CreateHead();
			for (; n > 0; n--) {
				push_back(value);
			}
		}
		template <class Iterator>
		list(Iterator first, Iterator last) {
			void CreateHead();
			auto i = first;
			while (i != last) {
				push_back(*i);
				i++;
			}
		}
		list(const list<T>& l) {
			void CreateHead();
			for (auto& i : l) {
				push_back(i);
			}
		}
		list<T>& operator=(const list<T> l) {
			swap(l);
			return *this;
		}
		~list() {
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin() {
			return _pHead->_pNext;
		}
		iterator end() {
			return _pHead;
		}
		const_iterator begin() const {
			return _pHead->_pNext;
		}
		const_iterator end() const {
			return _pHead;
		}

		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t size()const {
			size_t sz = 0;
			auto i = begin();
			while (i != end()) {
				sz++;
				i++;
			}
			return sz;
		}
		bool empty()const {
			return (_pHead->_pNext == _pHead);
		}

		////////////////////////////////////////////////////////////
		// List Access
		T& front() {
			return _pHead->_pNext->_val;
		}
		const T& front()const {
			return _pHead->_pNext->_val;
		}
		T& back() {
			return _pHead->_pPre->_val;
		}
		const T& back()const {
			return _pHead->_pPre->_val;
		}

		////////////////////////////////////////////////////////////
		// List Modify
		void push_back(const T& val) { insert(end(), val); }
		void pop_back() { erase(--end()); }
		void push_front(const T& val) { insert(begin(), val); }
		void pop_front() { erase(begin()); }
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val) {
			PNode newnode = new Node(val);
			newnode->_pNext = pos._pNode;
			newnode->_pPre = pos._pNode->_pPre;
			newnode->_pPre->_pNext = newnode;
			newnode->_pNext->_pPre = newnode;
			return newnode;
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos) {
			assert(pos != end());
			PNode pre = pos._pNode->_pPre;
			PNode next = pos._pNode->_pNext;
			pre->_pNext = next;
			next->_pPre = pre;
			delete pos._pNode;
			return next;
		}
		void clear() {
			auto i = begin();
			while (i != end()) {
				i = erase(i);
			}
		}
		void swap(list<T>& l) {
			std::swap(_pHead, l._pHead);
		}
	private:
		PNode _pHead;
	};
	template<class Container>
	void print_container(const Container& con)
	{
		// const iterator -> �������������޸�
		// const_iterator -> ָ�����ݲ����޸�
		typename Container::const_iterator it = con.begin();
		//auto it = con.begin();
		while (it != con.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		print_container(lt);
	}
};