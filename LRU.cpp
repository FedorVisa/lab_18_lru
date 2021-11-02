#include "Lrucashe.h"
using namespace std;
template <typename T>


LRUcashe<T>::LRUcashe(size_t size1) {
	size = size1;
	count = 0;

}

template <typename T> LRUcashe<T>::~LRUcashe() {
	qmap.clear();
	qlist.clear();
}

template <typename T> void LRUcashe<T>::add_to(const T& address) {
	qlist.push_front(address);
	qmap.insert(pair<T, int>(address, 1));

}

template <typename T> void LRUcashe<T>::change_pos(const T& address) {
	typename list<T>::iterator it;
	for (it = qlist.begin(); it != qlist.end(); ++it) {
		if (*it == address) {
			qlist.erase(it);
			break;
		}
	}
	qlist.push_front(address);
}

template <typename T> void LRUcashe<T>::delete_check() {
	if (count == size) {
		typename  list<T>::iterator it=qlist.end();
		--it;
		qmap.erase(qmap.find(*it));
		qlist.pop_back();
		count--;
	}
}

template <typename T> bool LRUcashe<T>::find_and_add1(const T& address) {

    auto result = this->qmap.find(address);

	if (result == this->qmap.end()) {
		this->delete_check();
		this->add_to(address);
		count++;
		return false;
	}
	else {
		this->change_pos(address);
		
	}

	return true;
}

template <typename T> ostream& operator << (ostream& os, LRUcashe<T>& a) {
	for (T str : a.qlist) {
		os << str << '\n';
	}
	return os;
}



