#pragma once

#include <renderer-d3d9/resource.hpp>
#include <common/databuffer.hpp>
#include <common/ref.hpp>
#include <common.hpp>
#include <d3d9.h>

namespace graphics
{
	R_ENUM( name = vertexelementformat )
	enum class vertexelementformat
	{
		float1 = 0,
		float2 = 1,
		float3 = 2,
		float4 = 3,
		ubyte4 = 4,
		short2 = 5,
		short4 = 6,
		ubyte4n = 7,
		short2n = 8,
		short4n = 9,
		ushort2n = 10,
		ushort4n = 11,
		invalid = 12,
	};

/*
R_EMIT( target = lua_beforemetatypes )
	vertexdeclaration.format = vertexelementformat
R_END()
*/

	R_STRUCT( name = vertexdeclelement )
	struct VertexDeclElement
	{
		int attribute;
		int offset;
		int format;
	};

	R_CLASS( name = vertexdeclaration )
	class VertexDeclaration: public Resource
	{
	private:
		Ref< IDirect3DVertexDeclaration9 > m_vertexdeclaration;
		AtomicRef< DataBuffer > m_data;
		size_t m_vertexsize;

	protected:
		virtual void doadvance() override;

	public:
		VertexDeclaration( DataBuffer* data, size_t vertexsize );
		~VertexDeclaration();
		VertexDeclaration( VertexDeclaration const& ) = delete;
		VertexDeclaration& operator=( VertexDeclaration const& ) = delete;

		bool bind( size_t* vertexsize );

		R_METHOD() static VertexDeclaration* create(
			DataBuffer* data, size_t vertexsize )
		{
			return new VertexDeclaration( data, vertexsize );
		}
	};
}
