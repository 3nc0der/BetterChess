#pragma once

//singleton class to make sure only one instance of a certain class exists
template <class T>
class c_singleton
{
protected:
	
	//holds the instance
	static T* mp_singleton;

public:

	virtual ~c_singleton() {};

	//returns the instance and creates a new one if no exists
	inline static T* mf_get()
	{
		if (!mp_singleton)
		{
			mp_singleton = new T();
		}

		return mp_singleton;
	}

	//safe deletes the instance
	inline static void mf_del()
	{
		if (mp_singleton)
		{
			delete mp_singleton;
			mp_singleton = nullptr;
		}

		return;
	}
};

template <class T>
T *c_singleton<T>::mp_singleton = 0;
