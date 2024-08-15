#pragma once
//模拟实现priority_queue类，并完成测试
template<class T>
class less {
public:
	operator()(T& x, T& y) {
		return x < y;
	}
};

template<class T>
class greater {
public:
	operator()(T& x, T& y) {
		return x > y;
	}
};

namespace zxy
{
#include<vector>
#include<functional>
	template <class T, class Container = std::vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		void AjustUp(T* a, int child) {
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (com(a[parent], a[child])) {
					auto tmp = &a[child];
					&a[child] = &a[parent];
					&a[parent] = tmp;
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		void AjustDown(T* a, int size, int parent) {
			int child = parent * 2 + 1;
			while (child < size) {
				if (child + 1 < size && com(a[child]), a[child + 1]) {
					child++;
				}
				if (com(a[parent], a[child])) {
					auto tmp = &a[child];
					&a[child] = &a[parent];
					&a[parent] = tmp;
					child = parent;
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		priority_queue(){}

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			auto i = first;
			while (i != last) {
				push(*i);
				i++;
			}
		}

		bool empty() const {return c.empty();}
		size_t size() const {return c.size();}
		T& top() const {return c.front();}

		void push(const T& x) {
			c.push(x);
			AjustUp(c, c.size() - 1);
		}
		void pop() {
			swap(c.front(), c.back());
			AjustDown(c, c.size() - 1, 0);
		}
	private:
		Container c;
		Compare comp;
	};
};