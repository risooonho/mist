#pragma once

#include <common/refobject.hpp>
#include <common.hpp>
#include <atomic>
#include <cinttypes>

namespace graphics
{
	R_CLASS( name = resource )
	class Resource: public RefObject
	{
	protected:
		std::atomic< size_t > m_lastframe;

	protected:
		virtual void doadvance() = 0;

	public:
		Resource();
		virtual ~Resource() override;
		virtual void destroy() override;
		Resource( Resource const& ) = delete;
		Resource& operator=( Resource const& ) = delete;

		void advance();
	};
}
