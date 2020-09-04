#pragma once

//singleton class to make sure only one instance of a certain class exists
template <class T>
class singleton
{
protected:
	
	//holds the instance
	static T* m_singleton;

public:

	virtual ~singleton() {};

	//returns the instance and creates a new one if no exists
	inline static T* get()
	{
		if (!m_singleton)
		{
			m_singleton = new T();
		}

		return m_singleton;
	}

	//safe deletes the instance
	inline static void del()
	{
		if (m_singleton)
		{
			delete m_singleton;
			m_singleton = nullptr;
		}

		return;
	}
};

template <class T>
T* singleton<T>::m_singleton = 0;
