#include "pch.h"
#include "TrainIterator.h"

namespace coursework::core
{
	TrainIterator::TrainIterator(TrainInfo* ptr) : m_current(ptr)
	{
	}

	TrainInfo& TrainIterator::operator*() const
	{
		return *m_current;
	}

	TrainIterator& TrainIterator::operator++()
	{
		++m_current;
		return *this;
	}

	bool TrainIterator::operator!=(const TrainIterator& other) const
	{
		return m_current != other.m_current;
	}
} // namespace coursework::core