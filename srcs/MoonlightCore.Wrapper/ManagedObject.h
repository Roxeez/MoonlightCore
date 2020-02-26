#pragma once
using namespace System;

namespace Moonlight
{
	template<class T>
	public ref class ManagedObject
	{
	protected:
		T* _instance;
	public:
		ManagedObject(T* instance) : _instance(instance)
		{

		}

		virtual ~ManagedObject()
		{
			if (_instance != nullptr)
			{
				delete _instance;
			}
		}

		!ManagedObject()
		{
			if (_instance != nullptr)
			{
				delete _instance;
			}
		}

		T* GetInstance()
		{
			return _instance;
		}
	};
}