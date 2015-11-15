#ifndef GRAPHICS_RENDERTARGET_HPP__
#define GRAPHICS_RENDERTARGET_HPP__ 1

#include "shape.hpp"
#include "texture.hpp"
#include <utils/ref.hpp>
#include <utils/counterlock.hpp>
#include <mutex>

namespace graphics {
	class RenderTarget: public Texture {
	private:
		typedef utils::CounterLock mutex_t;
		typedef std::lock_guard< mutex_t > lock_t;
		
	private:
		mutex_t m_mutex;
		IDirect3DSurface9* m_dssurface;
		int m_width;
		int m_height;
		utils::Ref< Shape > m_shape;
		bool m_dsuse;
		int m_clearflags;
		uint32_t m_clearcolor;
		float m_cleardepth;
		int m_clearstencil;
		
	protected:
		virtual void update( IDirect3DDevice9* device ) override;
		
	public:
		virtual bool query( int id, void** target ) override;
		RenderTarget() = delete;
		RenderTarget( int width, int height );
		virtual ~RenderTarget();
		RenderTarget( RenderTarget const& ) = delete;
		RenderTarget( RenderTarget&& ) = delete;
		RenderTarget& operator=( RenderTarget const& ) = delete;
		RenderTarget& operator=( RenderTarget&& ) = delete;
		
		void setdepthstenciluse( bool use );
		void setshape( Shape* shape );
		void setclearcolor( bool flag, float const* value );
		void setcleardepth( bool flag, float value );
		void setclearstencil( bool flag, int value );
	};
}

DEFINE_REFID( graphics::RenderTarget, graphics::Texture, 0x1dfbe3c7 )

namespace graphics {
	extern "C" {
		RenderTarget* graphics_rendertarget_new( int width, int height ) noexcept;
		bool graphics_rendertarget_setdepthstenciluse( RenderTarget* rt, bool use ) noexcept;
		bool graphics_rendertarget_setshape( RenderTarget* rt, Shape* shape ) noexcept;
		bool graphics_rendertarget_setclearcolor( RenderTarget* rt, bool flag, float const* value ) noexcept;
		bool graphics_rendertarget_setcleardepth( RenderTarget* rt, bool flag, float value ) noexcept;
		bool graphics_rendertarget_setclearstencil( RenderTarget* rt, bool flag, int value ) noexcept;
	}
}

#endif