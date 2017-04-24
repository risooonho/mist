#pragma once

#include <common/refobject.hpp>
#include <common/ref.hpp>
#include <common.hpp>

R_CLASS( name = databuffer )
class DataBuffer: public RefObject
{
public:
	size_t m_length;
	size_t const m_capacity;
	uint8_t m_data[ 8 ];

	R_METHOD( name = create ) static DataBuffer* newinstance(
		size_t length, size_t capacity, void const* data )
	{
		DataBuffer* db;
		db = ( DataBuffer* )operator new(
			offsetof( DataBuffer, m_data ) + capacity );
		try
		{
			new( db )DataBuffer( length, capacity, data );
			return db;
		}
		catch( ... )
		{
			operator delete( db );
			throw;
		}
	}

	static Ref< DataBuffer > create(
		size_t length, size_t capacity, void const* data )
	{
		return Ref< DataBuffer >( newinstance( length, capacity, data ), 0 );
	}

	static Ref< DataBuffer > create( size_t length, void const* data )
	{
		return Ref< DataBuffer >( newinstance( length, length, data ), 0 );
	}

	static Ref< DataBuffer > create( size_t length )
	{
		return Ref< DataBuffer >( newinstance( length, length, nullptr ), 0 );
	}

	static Ref< DataBuffer > create()
	{
		return Ref< DataBuffer >();
	}

private:
	DataBuffer( size_t length, size_t capacity, void const* data )
		: m_length( length )
		, m_capacity( capacity )
	{
		if( data )
		{
			memcpy( m_data, data, length );
		}
	}

public:
	virtual ~DataBuffer() override
	{
	}

	virtual void destroy() override
	{
		this->~DataBuffer();
		operator delete( this );
	}

	DataBuffer( DataBuffer const& ) = delete;
	DataBuffer& operator=( DataBuffer const& ) = delete;

	R_METHOD() void* getdata() NOEXCEPT { return m_data; }
	R_METHOD() size_t getlength() NOEXCEPT { return m_length; }
	R_METHOD() void setlength( size_t length ) NOEXCEPT { m_length = length; }
	R_METHOD() size_t getcapacity() NOEXCEPT { return m_capacity; }
};

inline Ref< DataBuffer > operator"" _db( char const* str, size_t len )
{
	return DataBuffer::create( len, str );
}
