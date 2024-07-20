#include <iostream>

using namespace std;



class SingleObject
{
private:
	static SingleObject* pSingleObject;
	int m_data=5;
	SingleObject()
	{
		cout << "SingleTon 생성자" << endl;

		cout << "m_data: " << m_data << endl;
	}
public:
	static SingleObject* GetInstance()
	{
		if (pSingleObject == NULL)
		{
			pSingleObject = new SingleObject();
		}
		return pSingleObject;
	}
	void ShowMessage()
	{
		if (pSingleObject == NULL)
			cout << "싱글톤화 되지 않았습니다 >> " << typeid(this).name() << endl;
		else
			cout << "싱글톤화 되었습니다" << endl;
	}
	static void Release()
	{
		// typeid(@).name() >> @라는 어떠한 대상에 대한 정보를 
		cout << "SingleTon 소멸자>> "<< typeid(m_data).name() << endl;
	}
};

//이 선언을 해주지 않으면 오류가 난다
//클래스 외부에서 static변수에 대해 null처리를 해주어야한다
//이유는 스스로 찾지는 못했고 검색해보니 그렇다고함
//C++에서 클래스의 처리 방식이 다르기 때문에(?) 발생하는 오류라고함
SingleObject* SingleObject::pSingleObject = NULL;

/*
SingleObject* SingleObject::getInstance()
{
	if (pSingleObject == NULL)
	{
		pSingleObject = new SingleObject();
	}
	return pSingleObject;
}

void SingleObject::ShowMessage()
{
	cout << "SingleTon" << endl;
}

void SingleObject::Release()
{

}
*/

int main()
{
	SingleObject::Release();
	SingleObject* so = NULL;
	//so = SingleObject::GetInstance();
	so->ShowMessage();
	so->GetInstance();
	//SingleObject::GetInstance();
	so->ShowMessage();
	//so->getInstance();
}

#pragma region 스스로 한 거 아님

/*
#include <iostream>

using namespace std;

//싱글톤: 객체가 한개 이상 생성되지않는 클래스
class CSingleObject
{
	int m_nData; // 은닉된 변수
	//public :
	CSingleObject()
	{
		cout << "CSingleObject[" << this << "]:" << m_nData << endl;
	}
public:
	CSingleObject GetInstance()
	{
		static CSingleObject cSingleObject;
		return cSingleObject;
	}

	~CSingleObject()
	{
		cout << "~CSingleObject[" << this << "]:" << m_nData << endl;
	}
	void Display()
	{
		cout << typeid(*this).name() << ":Display(" << m_nData << ")" << endl;
	}
};

void main()
{
	////다음과 같이 객체가 생성가능하다면 이 객체를 싱글톤이라 부를 수 없다.
	//CSingleObject cSingeObject; //객체를 정적할당한다.
	//CSingleObject arrSingleObject[2];
	//객체의 포인터만 선언했으므로, 객체가 생성되지않았다.

	CSingleObject* pSingeObject = NULL;
	CSingleObject* pArrSingleObject[2] = {};

	pSingeObject = &pSingeObject->GetInstance();

	pSingeObject->Display(); //객체(인스턴스)가 아직 생성되지않았으므로, 멤버인 data에 접근 할 수없다.
}
*/

#pragma endregion