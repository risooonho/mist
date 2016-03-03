#include "flaglock.hpp"
#include <thread>

namespace utils
{
	FlagLock::FlagLock()
	{
		m_flag.clear( std::memory_order_release );
	}

	FlagLock::~FlagLock()
	{
	}

	void FlagLock::lock() NOEXCEPT
	{
		while( m_flag.test_and_set( std::memory_order_acquire ) )
		{
		}
	}

	void FlagLock::unlock() NOEXCEPT
	{
		m_flag.clear( std::memory_order_release );
	}
}
