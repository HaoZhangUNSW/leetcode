#include <iostream>
using namespace std;
class CPtr;
class CPtrUser{
	public:
		CPtrUser():m_pPtr(nullptr){}
		~CPtrUser(){delete m_pPtr;}
		void setPtr(CPtr* p){m_pPtr = p;}
	private:
		CPtr* m_pPtr;
};
int main(){
	CPtrUser user = new CPtrUser();
	CPtr* p = new CPtr();
	user->setPtr(p);
	return 0;
}
