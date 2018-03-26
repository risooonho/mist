#pragma once

#include <rsbin/storage.hpp>
#include <osapi.hpp>
#include <common.hpp>
#include <map>
#include <memory>

namespace rsbin
{
	enum class [[ r::enum ]] fileopenmode
	{
		read, // open for read only, fail if doesn't exist
		update, // open for read and write, fail if doesn't exist
		create, // create or truncate for read and write
		provide, // create or open for read and write
		invalid,
	};

	class [[ r::class, r::name( "filestorage" ) ]] FileStorage: public Storage
	{
	private:
		struct page_t
		{
			uint8_t* m_buffer;
			int m_refcount;
			int m_writercount;
			bool m_isioactive;
#if defined( _WIN32 ) || defined( _WIN64 )
			OVERLAPPED m_overlapped;
#endif

			page_t( uint64_t offset );
			~page_t();
			page_t( page_t const& other ) = delete;
			page_t& operator=( page_t const& other ) = delete;
		};

	private:
#if defined( _WIN32 ) || defined( _WIN64 )
		HANDLE m_handle;
#else
#error FileStorage is not implemented
#endif
		std::map< uint64_t, page_t > m_pages;
		uint64_t m_limit;
		int m_mapcount;
		bool m_busy;
		bool m_isreadable;
		bool m_iswriteable;

	private:
		page_t* getpage( uint64_t pageoffset, bool& isloaded );
		void clearpages();
		bool pollpage( page_t* page );
		bool startread( page_t* page );
		bool startwrite( page_t* page );

	public:
		[[ r::method ]] FileStorage(
			char const* path [[ r::required ]], fileopenmode mode );
		~FileStorage();

		virtual StorageMap* map(
			uint64_t offset, uint32_t length,
			bool flagread, bool flagwrite ) override;
		virtual GetLimitTask* getlimit( uint64_t* plimit ) override;
		virtual Task* setlimit( uint64_t limit ) override;
		virtual Task* flush() override;
		virtual Task* close() override;

	public:
		friend class FileStorageMap;
		friend class FileStorageFlushTask;
	};
}
