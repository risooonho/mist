#ifndef RSBIN_FILEIO_HPP__
#define RSBIN_FILEIO_HPP__ 1

#include <utils/refobject.hpp>
#include <utils/string.hpp>
#include <common.hpp>
#include <cinttypes>

namespace rsbin
{
	class FsTask;

	R_ENUM()
	enum class fileopenmode
	{
		read = 0, // "r", open for read only, fail if doesn't exist
		update = 1, // "r+", open for read and write, fail if doesn't exist
		create = 2, // "w", create or truncate for write only
		clear = 3, // "w+", create or truncate for read and write
		provide = 4, // "r+"/"w+", create or open for read and write
		invalid = 5,
	};

	R_CLASS( name = fileio )
	class FileIo: public utils::RefObject
	{
	public:
#if defined( _WIN32 ) || defined( _WIN64 )
		void* m_handle;
		void* m_mapping;
#elif defined( __ANDROID__ )
		int m_handle;
#endif
		uint8_t* m_view;
		uint64_t m_viewsize;

	public:
		FileIo() = delete;
		FileIo( char const* path, fileopenmode mode );
		virtual ~FileIo() override;
		FileIo( FileIo const& other ) = delete;
		FileIo( FileIo&& other ) = delete;
		FileIo& operator=( FileIo const& other ) = delete;
		FileIo& operator=( FileIo&& other ) = delete;

		R_METHOD() static FileIo* create( char const* path, fileopenmode mode )
		{
			return new FileIo( path, mode );
		}
		R_METHOD() FsTask* startread(
			uint64_t offset, int length, void* buffer );
		R_METHOD() FsTask* startwrite(
			uint64_t offset, int length, void const* buffer );
		R_METHOD() void setsize( uint64_t size );
	};
}

#endif
