#ifndef lab
#define lab

#include<iostream>
#include<map>
#include<list>


using namespace std;

template <typename T>

class LRUcashe {
private:
	size_t size;
	size_t count;
	list <T> qlist;
	map <T, decltype(qlist.begin())> qmap;
public:

	LRUcashe(size_t size1) {
		size = size1;
		count = 0;
	}

	void delete_check() {
		if (count == size) {
			typename  list<T>::iterator it = qlist.end();
			--it;
			qmap.erase(qmap.find(*it));
			qlist.pop_back();
			count--;
		}
	}

	void add_to(const T& address) {
		qlist.push_front(address);
		qmap.insert(pair<T,qlist.begin()>(address, qlist.begin()));
	}

	void change_pos(const T& address) {
		typename list<T>::iterator it;
		for (it = qlist.begin(); it != qlist.end(); ++it) {
			if (*it == address) {
				qlist.erase(it);
				break;
			}
		}
		qlist.push_front(address);
	}

	bool find_and_add1(const T& address) {
		if (qmap.find(address) == qmap.end()) {
			delete_check();
			add_to(address);
			count++;
			return false;
		}
		else {
			change_pos(address);
		}
		return true;
	}

	friend ostream& operator << (ostream& os, const LRUcashe<T>& a) {
		for (T data : a.qlist) {
			os << data << '\n';
		}
		return os;
	}
};



#endif











