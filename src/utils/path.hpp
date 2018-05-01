#pragma once

#include <common/databuffer.hpp>
#include <common/ref.hpp>
#include <common/refobject.hpp>
#include <common.hpp>
#include <utils/console.hpp>

namespace utils
{
/*
	This facility is responcible for converting abstract Mist paths into actual
host OS's paths. It aims to reach the following objectives:
	- abstract away the differences between paths in different hosts, such as
node separators and character encodings,
	- confine the possible effects of client scripts to a specified subset of
the host's filesystem,
	- mitigate some limitations of the simpler APIs, such as MAX_PATH limit of
default C functions under Windows and their inability to handle Unicode.
	A path like "root/dir/subdir/file" is represented by a sequence of objects:
		Path{
			m_point = resolveroot( "root" ),
			m_base = nullptr }
		Path{
			m_point = utf8tonative( "dir" ) }
		Path{
			m_point = utf8tonative( "subdir" ) }
		Path{
			m_point = utf8tonative( "file" ) }
	Path::m_base points to the object above.
	Path::m_fullpath caches the full combined path,
which is later passed down to OS facilities.
	Path::m_point contains the string value of each node
in the OS's native encoding.
	For the non-root nodes, this is simply a trimmed and transcoded
point name from the corresponding position in the source string.
	For the root, this value is looked up in the internal table,
which maps each name to a directory in the user's filesystem.
	It might looks like this:
		"scripts" -> "D:\Program Files\mist\scripts"
		"assets" -> "C:\Program Files\mist\assets"
		"saves" -> "C:\Users\JohnSmith\Documents\mist\saves"
		"" -> "C:\Users\JohnSmith\Documents\mist\local"
	This table is filled from mainconfig's 'path' table.
	An unmapped root makes an invalid path.
	When parsing the source string, any sequence of
whitespace and at least a single forward or backward slash is treated
as a single separator.
Each part of the path has its leading and trailing whitespace trimmed.

	Additionally, "." nodes are skipped by the parser, while ".." nodes cause it
to remove the currently rightmost node, effectively turning them into aliases
for the current and the upper directory respectively. Raising above the root
node with ".." elements makes an invalid source path.
	Several examples of the transformations performed:
		"scripts/rs/util.lua"
		"D:\Program Files\Mist\scripts\rs\util.lua"
	^ the actual value for "scripts" is substituted, path separators are
converted into the host OS's preferred variant
		"scripts\ \crc32.lua"
		"D:\Program Files\Mist\scripts\crc32.lua"
	^ several separators are merged into one
		"\scripts\abc.lua"
		"C:\Users\JohnSmith\Documents\Mist\local\abc.lua"
	^ the first separator is not skipped, instead, it's treated as delimiting
a root named "" (empty string)

	Notes for Windows:
	The target format for the paths is an absolute Win32 namespace path.
An example of such a path looks like this:
		"\\?\D:\Program Files\Mist\scripts\rs\util.lua"
	This allows Mist to work with extremely long paths, as well as
with paths containing arbitraty Unicode symbols. For additional information,
look here:
https://msdn.microsoft.com/en-us/library/windows/desktop/aa365247(v=vs.85).aspx
	Additionally, non-UTF-16-conformant paths may be directly generated by
prefixing the source string with UTF-16 BOM '\xff\xfe'.
In this case, the rest of the source string is treated as a wchar_t sequence
without any transcoding. However, splitting and root expanding still
proceeds as normal.
*/
	class [[ r::class, r::name( "path" ) ]] Path: public RefObject
	{
	public:
#if defined( _WIN32 ) || defined( _WIN64 )
		typedef wchar_t char_t;
#else
		typedef char char_t;
#endif

	private:
		Ref< DataBuffer > m_point;
		Ref< DataBuffer > m_fullpath;

	public:
		Ref< Path > m_base;

	public:
		Path() = delete;
		Path( DataBuffer* point, Path* base );
		Path( Path const& other );
		Path( Path&& other );
		~Path();
		Path& operator=( Path const& other ) = delete;

		char_t const* combine();

	public:
		static Ref< Path > create( void const* path );
		static void initialize();

		[[ r::method ]] static void test( void const* path )
		{
			externalassert( path );
			Ref< Path > p = create( path );
			LOG( "%ls", p ? p->combine() : L"< invalid path >" );
		}
	};
}