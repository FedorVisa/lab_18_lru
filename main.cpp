#include "Lrucashe.h"

 int main(){
	 LRUcashe<std::string> a(3);


	 a.find_and_add1("AA");
	 a.find_and_add1("AB");
	 std::cout << a;
	 std::cout << '\n';
	 a.find_and_add1("AG");
	 std::cout << a;
	 std::cout << '\n';
	 a.find_and_add1("AA");
	 std::cout << a;
	 std::cout << '\n';
	 a.find_and_add1("AE");
	 std::cout << a;
	 std::cout << '\n';
	 a.find_and_add1("AA");
	 std::cout << a;

	 return 0;
}