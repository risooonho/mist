#pragma once

#include <renderer-state/context.hpp>

namespace graphics
{
	namespace
	{
		void resource_advance( void* ud )
		{
			Resource* res = ( Resource* )ud;
			res->advance();
		}

		void resource_delete( void* ud )
		{
			Resource* res = ( Resource* )ud;
			delete res;
		}
	}

	void Resource::deferadvance()
	{
		Context::defer( &resource_advance, this, this );
	}

	Resource::Resource()
		: m_lastframe( 0 )
	{
	}

	Resource::~Resource()
	{
	}

	void Resource::destroy()
	{
		Context::defer( &resource_delete, this, nullptr );
	}

	void Resource::advance()
	{
		size_t drawnframe = Context::DrawnFrame.load( std::memory_order_relaxed );
		if( m_lastframe < drawnframe )
		{
			m_lastframe = drawnframe;
			doadvance();
		}
	}
}
