#pragma once
#include "TrainInfo.h"

#ifdef COURSEWORK_CORE_EXPORTS
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

namespace coursework::core
{
	/// Iterator class for traversing TrainInfo objects.
	class CORE_API TrainIterator
	{
		public:
			/// Constructs iterator pointing to given TrainInfo element.
			/// @param ptr Pointer to current TrainInfo in collection.
			TrainIterator(TrainInfo* ptr);

			/// Dereference operator.
			/// @return Reference to the current TrainInfo object.
			TrainInfo& operator*() const;

			/// Pre-increment operator to move to the next TrainInfo.
			/// @return Reference to the incremented TrainIterator.
			TrainIterator& operator++(); 

			/// Inequality operator to compare two TrainIterators.
			/// @param other Another TrainIterator to compare with.
			/// @return True if the iterators point to different TrainInfo objects, false otherwise.
			bool operator!=(const TrainIterator& other) const;

		private:
			TrainInfo* m_current;
	};
} // namespace coursework::core 