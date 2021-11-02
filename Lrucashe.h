#ifndef lab
#define lab

#include<iostream>
#include<map>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

template <typename T>

class LRUcashe {
private:
	size_t size;
	size_t count;
	list <T> qlist;
	map <T, int> qmap;
public:
	LRUcashe(size_t size1);
	~LRUcashe();
	void delete_check();
	void add_to(const T& address);
	void change_pos(const T& address);
	bool find_and_add1(const T& address);
	friend ostream& operator << (ostream& os, LRUcashe<T>& a);
};



#endif









