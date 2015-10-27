#ifndef RSBIN_FSTHREAD_HPP__
#define RSBIN_FSTHREAD_HPP__ 1

#include <utils/mpscqueue.hpp>
#include <utils/singleton.hpp>
#include <utils/string.hpp>
#include <utils/refobject.hpp>
#include <utils/ref.hpp>
#include <thread>
#include <atomic>
#include <cstdio>

namespace rsbin
{
	class FileIo;

	enum IoDirection: int
	{
		IoActionRead = 0,
		IoActionWrite = 1,
		IoActionTruncate = 2,
	};

	struct FsTask: public utils::RefObject
	{
		utils::Ref< FileIo > m_target;
		uint64_t m_offset;
		int m_length;
		uint8_t* m_buffer;
		IoDirection m_direction;
		int m_result;
		utils::String m_error;
		std::atomic< bool > m_finished;

		inline FsTask() : m_finished( false ) {}
		virtual ~FsTask() = default;
	};

	class FsThreadClass
	{
	private:
		std::atomic< bool > m_terminate;
		std::thread m_thread;
		utils::MPSCQueue< utils::Ref< FsTask > > m_highqueue;
		utils::MPSCQueue< utils::Ref< FsTask > > m_mainqueue;

		void threadfunc();

	public:
		FsThreadClass();
		~FsThreadClass();
		FsThreadClass( FsThreadClass const& other ) = delete;
		FsThreadClass( FsThreadClass&& other ) = delete;
		FsThreadClass& operator=( FsThreadClass const& other ) = delete;
		FsThreadClass& operator=( FsThreadClass&& other ) = delete;

		void pushmain( FsTask* task );
		void pushhigh( FsTask* task );
	};

	extern utils::Singleton< FsThreadClass > FsThread;

	extern "C"
	{
		bool rsbin_fstask_promote( FsTask* task ) noexcept;
		int rsbin_fstask_isfinished( FsTask* task ) noexcept;
		int rsbin_fstask_getresult( FsTask* task ) noexcept;
		char const* rsbin_fstask_geterror( FsTask* task ) noexcept;
	}
}

#endif
