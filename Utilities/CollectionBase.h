#pragma once
#include <string>
namespace Utilities::Containers
	{
		class CollectionBase
		{
			public:
				virtual int Count() = 0;
				virtual void Clear() = 0;
				virtual std::string ToString() = 0;
				virtual void Print() = 0;
		protected:
				int count = 0;
		};
	};

