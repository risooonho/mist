local modname = ...
-- use:
--   client-console
--   client-main
--   renderer-d3d9
--   renderer-gles
local sources = {
	{
		type = 'native',
		name = 'common',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'osapi',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'utils/cbase',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/configset',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/console',
		use = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/cyclicbuffer',
		use = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/databuffer',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/encoding',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/flaglock',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'utils/mpsclist',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'utils/mpscqueue',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'utils/path',
		use = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/ref',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'utils/refobject',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/singleton',
		headeronly = true,
		use = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'utils/strexception',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'utils/string',
		headeronly = true,
		use = 'client-console;client-main;renderer-d3d9;renderer-gles',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'rsbin/common',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/fileio',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/flaccommon',
		headeronly = true,
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/flacreader',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/flacwriter',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/fsthread',
		use = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/io',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/iotask',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/memoryio',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/pngcommon',
		headeronly = true,
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/pngreader',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
	{
		type = 'native',
		name = 'rsbin/pngwriter',
		use = 'client-console;client-main',
		methodlist = 'client-console;client-main',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'client-console/main',
		noheader = true,
		use = 'client-console',
	},
	{
		type = 'native',
		name = 'client-console/window',
		use = 'client-console',
		methodlist = 'client-console',
	},
	{
		type = 'native',
		name = 'client-console/windowinfo',
		headeronly = true,
		use = 'client-console',
		methodlist = 'client-console',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'renderer-state/common',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/context',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/context-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/interface',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/interface-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
		methodlist = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-base',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-functions',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-generators',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-shaders',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-state',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-step',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/programtranslator-swizzles',
		use = 'renderer-d3d9;renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-state/resource',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
		methodlist = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/resource-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/shape',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
		methodlist = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/shape-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/shapegroup',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
		methodlist = 'renderer-d3d9;renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-state/shapegroup-cpp',
		headeronly = true,
		use = 'renderer-d3d9;renderer-gles',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'renderer-d3d9/clearshape',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/common',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/context',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/display',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/interface',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/primitiveshape',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/programtranslator',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/resource',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/shape',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/shapegroup',
		use = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/staticvertexbuffer',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/vertexbuffer',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
	{
		type = 'native',
		name = 'renderer-d3d9/vertexdeclaration',
		use = 'renderer-d3d9',
		methodlist = 'renderer-d3d9',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'renderer-gles/clearshape',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/common',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/context',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/display',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/gl2',
		use = 'renderer-gles',
		headeronly = true,
	},
	{
		type = 'native',
		name = 'renderer-gles/interface',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/primitiveshape',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/programtranslator',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/resource',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/shape',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/shapegroup',
		use = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/staticvertexbuffer',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/vertexbuffer',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
	{
		type = 'native',
		name = 'renderer-gles/vertexdeclaration',
		use = 'renderer-gles',
		methodlist = 'renderer-gles',
	},
--------------------------------------------------------------------------------
	{
		type = 'native',
		name = 'client-main/event',
		headeronly = true,
		use = 'client-main',
		methodlist = 'client-main',
	},
	{
		type = 'native',
		name = 'client-main/main',
		noheader = true,
		use = 'client-main',
	},
	{
		type = 'native',
		name = 'client-main/window',
		use = 'client-main',
		methodlist = 'client-main',
	},
	{
		type = 'native',
		name = 'client-main/windowinfo',
		headeronly = true,
		use = 'client-main;renderer-d3d9;renderer-gles',
		methodlist = 'client-main',
	},
--------------------------------------------------------------------------------
	{
		type = 'luainit',
		name = 'luainit/main',
	},
	{
		type = 'luainit',
		name = 'luainit/baselib',
	},
	{
		type = 'luainit',
		name = 'luainit/object',
	},
	{
		type = 'luainit',
		name = 'luainit/ffipure',
	},
	{
		type = 'luainit',
		name = 'luainit/hostlib',
	},
}

package.modtable(modname, sources)