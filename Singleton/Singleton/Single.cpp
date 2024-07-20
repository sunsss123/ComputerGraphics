#include <iostream>

using namespace std;



class SingleObject
{
private:
	static SingleObject* pSingleObject;
	int m_data=5;
	SingleObject()
	{
		cout << "SingleTon ������" << endl;

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
			cout << "�̱���ȭ ���� �ʾҽ��ϴ� >> " << typeid(this).name() << endl;
		else
			cout << "�̱���ȭ �Ǿ����ϴ�" << endl;
	}
	static void Release()
	{
		// typeid(@).name() >> @��� ��� ��� ���� ������ 
		cout << "SingleTon �Ҹ���>> "<< typeid(m_data).name() << endl;
	}
};

//�� ������ ������ ������ ������ ����
//Ŭ���� �ܺο��� static������ ���� nulló���� ���־���Ѵ�
//������ ������ ã���� ���߰� �˻��غ��� �׷��ٰ���
//C++���� Ŭ������ ó�� ����� �ٸ��� ������(?) �߻��ϴ� ���������
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

#pragma region ������ �� �� �ƴ�

/*
#include <iostream>

using namespace std;

//�̱���: ��ü�� �Ѱ� �̻� ���������ʴ� Ŭ����
class CSingleObject
{
	int m_nData; // ���е� ����
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
	////������ ���� ��ü�� ���������ϴٸ� �� ��ü�� �̱����̶� �θ� �� ����.
	//CSingleObject cSingeObject; //��ü�� �����Ҵ��Ѵ�.
	//CSingleObject arrSingleObject[2];
	//��ü�� �����͸� ���������Ƿ�, ��ü�� ���������ʾҴ�.

	CSingleObject* pSingeObject = NULL;
	CSingleObject* pArrSingleObject[2] = {};

	pSingeObject = &pSingeObject->GetInstance();

	pSingeObject->Display(); //��ü(�ν��Ͻ�)�� ���� ���������ʾ����Ƿ�, ����� data�� ���� �� ������.
}
*/

#pragma endregion