#pragma once
#include<assert.h>
//模拟实现vector类，并完成测试

namespace zxy
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;

		typedef const T* const_iterator;

		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}

		const_iterator cbegin() {
			return _start;
		}

		const_iterator cend() const {
			return _finish;
		}

		// construct and destroy

		vector()
			: _start(nullptr),
			_finish(nullptr),
			_endOfStorage(nullptr) 
		{}

		vector(int n, const T& value = T())
			: _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++) {
				push_back(value);
			}
		}

		template<class InputIterator>

		vector(InputIterator first, InputIterator last)
			: _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(last - first);
			auto& i = first;
			while (i != last) {
				push_back(*i);
				i++;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			for (auto& i : v) {
				push_back(i);
			}
		}

		vector<T>& operator= (vector<T> v) {
			swap(v);
			return *this;
		}

		~vector() {
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		// capacity

		size_t size() const {
			return _finish - _start;
		}

		size_t capacity() const {
			return _endOfStorage - _start;
		}

		void reserve(size_t n) {
			if (n <= capacity()) {
				return;
			}
			T* tmp = new T[n];
			size_t oldsize = size();
			if (_start)

			{
				for (size_t i = 0; i < oldsize; ++i)

					tmp[i] = _start[i];
			}
			delete[]_start;
			_start = tmp;
			_finish = _start + oldsize;
			_endOfStorage = _start + n;
		}

		void resize(size_t n, const T& value = T()) {
			if (n <= size()) {
				_finish = _start + n;
			}
			else {
				reserve(n); as:
				for (size_t i = 0; i < n; i++) {
					push_back(value);
				}
			}
		}

		///////////////access///////////////////////////////

		T& operator[](size_t pos) {
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos)const {
			assert(pos < size());
			return _start[pos];
		}

		///////////////modify/////////////////////////////

		void push_back(const T& x) {
			if (_finish == _endOfStorage) {
				reserve(capacity() == 0 ? 1 : 2 * capacity());
			}
			*_finish = x;
			_finish++;
		}

		void pop_back() {
			assert(size() > 0);
			_finish--;
		}

		void swap(vector<T>& v) {
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		iterator insert(iterator pos, const T& x) {
			assert(pos >= begin() && pos <= end());
			if (capacity() == size()) {
				reserve(capacity() == 0 ? 1 : 2 * capacity());
			}
			auto i = end();
			while (i != pos) {
				*i = *(i - 1);
				i--;
			}
			*pos = x;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)

		{
			// 挪动数据进行删除

			iterator begin = pos + 1;

			while (begin != _finish)

			{
				*(begin - 1) = *begin;

				++begin;
			}

			--_finish;

			return pos;
		}
	private:

		iterator _start; // 指向数据块的开始

		iterator _finish; // 指向有效数据的尾

		iterator _endOfStorage; // 指向存储容量的尾
	};
}