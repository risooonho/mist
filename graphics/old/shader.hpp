#ifndef GRAPHICS_SHADER_HPP__
#define GRAPHICS_SHADER_HPP__ 1

#include "resource.hpp"
#include "texture.hpp"
#include <utils/databuffer.hpp>
#include <utils/ref.hpp>
#include <utils/counterlock.hpp>
#include <d3dx9shader.h>
#include <mutex>

namespace graphics
{
	class Shader: public Resource
	{
	public:
		enum
		{
			ShaderFormat_GLSL_100 = 0,
			ShaderFormat_HLSL_3_0_Source = 1,
			ShaderFormat_HLSL_3_0_Bytecode = 2,
		};

	private:
		typedef utils::CounterLock mutex_t;
		typedef std::lock_guard< mutex_t > lock_t;

	private:
		mutex_t m_mutex;
		utils::Ref< Texture > m_textures[ 8 ];
		int m_samplerindex[ 8 ];
		IDirect3DVertexShader9* m_vertexshader;
		IDirect3DPixelShader9* m_pixelshader;
		ID3DXBuffer* m_vertexshaderdata;
		ID3DXConstantTable* m_vertexshaderconstants;
		ID3DXBuffer* m_pixelshaderdata;
		ID3DXConstantTable* m_pixelshaderconstants;

	protected:
		virtual void doadvance() override;

	public:
		Shader();
		virtual ~Shader() override;
		Shader( Shader const& ) = delete;
		Shader& operator=( Shader const& ) = delete;

		void bind( utils::Ref< Texture > const* textures, int* worldmatrixindex );
		void settexture( int stage, Texture* texture );
	};

	Shader* graphics_shader_new(
		int format,
		char const* vert, char const* frag, char const* texnames ) noexcept;
	bool graphics_shader_settexture(
		Shader* sh, int stage, Texture* texture ) noexcept;
	int graphics_shader_isformatsupported( int format ) noexcept;
}

#endif