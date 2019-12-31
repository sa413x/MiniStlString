#include "Vector.h"

class String
{
public:
	String(const char* szValue)
	{
		for (int i = 0; szValue[i] != '\0'; i++)
			this->m_vBuffer.Push(szValue[i]);
	}

	char& At(int i)
	{
		return this->m_vBuffer[i];
	}

	void Push(char cValue)
	{
		return this->m_vBuffer.Push(cValue);
	}

	char& operator[](int i)
	{
		return this->m_vBuffer[i];
	}

	int Size()
	{
		return this->m_vBuffer.Size();
	}

	String operator+(String szInputValue)
	{
		String szResult = "";

		for (auto cIt : *this)
			szResult.Push(cIt);
		for (auto cIt : szInputValue)
			szResult.Push(cIt);

		return szResult;
	}

	String operator+(const char* szValue)
	{
		String szResult = "";

		for (auto cIt : *this)
			szResult.Push(cIt);
		for (auto cIt : String(szValue))
			szResult.Push(cIt);

		return szResult;
	}

	const char* Data()
	{
		char* szTemp = new char[this->m_vBuffer.Size() + 1];
		for (int i = 0; i < this->m_vBuffer.Size(); i++)
			szTemp[i] = this->m_vBuffer[i];

		szTemp[this->m_vBuffer.Size()] = '\0';
		return szTemp;
	}

	char* begin()
	{
		return this->m_vBuffer.GetBuffer();
	}

	char* end()
	{
		return this->m_vBuffer.GetBuffer() + this->m_vBuffer.Size();
	}

private:
	Vector<char> m_vBuffer;
};