/***
 *
 *https://www.cnblogs.com/cxjchen/p/3148582.html
 *
 * 声明static对象（指针），构造函数等全部私有化。
 * ***/
#include <iostream>
using namespace std;

class Singleton{
	public:
		static Singleton* getInstance();
	private:
		Singleton();
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	static Singleton* instance;

};

Singleton::Singleton(){}
Singleton::Singleton(const Singleton&){}
Singleton& Singleton::operator=(const Singleton&){}

Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance(){return instance;}

int main(){
	Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();
	if(singleton1 == singleton2){
		cout << "==" << endl;
	}
	return 0;
}

