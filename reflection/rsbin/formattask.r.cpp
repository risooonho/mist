#include <src/rsbin/formattask.hpp>
#include <reflection.hpp>
#include <common.hpp>
namespace
{
/*
	src/rsbin/formattask.hpp:13:2:
	rsbin> FormatTask = class(Task) [[r::class]] [[r::name("formattask")]]
*/
	struct r_ptr_t
	{
/*
	src/rsbin/formattask.hpp:13:2:
	rsbin> FormatTask = class(Task) [[r::class]] [[r::name("formattask")]]
*/
	};
	r_ptr_t r_ptr = {
/*
	src/rsbin/formattask.hpp:13:2:
	rsbin> FormatTask = class(Task) [[r::class]] [[r::name("formattask")]]
*/
	};
	uint8_t const r_chunk[] = {
		0x1b, 0x4c, 0x4a, 0x01, 0x00, 0x21, 0x72, 0x65,
		0x66, 0x6c, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e,
		0x2f, 0x72, 0x73, 0x62, 0x69, 0x6e, 0x2f, 0x66,
		0x6f, 0x72, 0x6d, 0x61, 0x74, 0x74, 0x61, 0x73,
		0x6b, 0x2e, 0x72, 0x2e, 0x6c, 0x75, 0x61, 0xb9,
		0x05, 0x02, 0x00, 0x0a, 0x00, 0x13, 0x00, 0x26,
		0x86, 0x01, 0x00, 0x26, 0x43, 0x00, 0x00, 0x02,
		0x34, 0x01, 0x00, 0x00, 0x25, 0x02, 0x01, 0x00,
		0x3e, 0x01, 0x02, 0x02, 0x34, 0x02, 0x00, 0x00,
		0x25, 0x03, 0x02, 0x00, 0x3e, 0x02, 0x02, 0x02,
		0x34, 0x03, 0x00, 0x00, 0x25, 0x04, 0x03, 0x00,
		0x3e, 0x03, 0x02, 0x02, 0x34, 0x04, 0x00, 0x00,
		0x25, 0x05, 0x04, 0x00, 0x3e, 0x04, 0x02, 0x02,
		0x37, 0x05, 0x05, 0x01, 0x25, 0x06, 0x06, 0x00,
		0x25, 0x07, 0x07, 0x00, 0x24, 0x06, 0x07, 0x06,
		0x3e, 0x05, 0x02, 0x01, 0x25, 0x05, 0x08, 0x00,
		0x25, 0x06, 0x09, 0x00, 0x24, 0x05, 0x06, 0x05,
		0x37, 0x06, 0x0a, 0x01, 0x10, 0x07, 0x05, 0x00,
		0x10, 0x08, 0x00, 0x00, 0x3e, 0x06, 0x03, 0x02,
		0x34, 0x07, 0x0b, 0x00, 0x37, 0x07, 0x0c, 0x07,
		0x37, 0x07, 0x0d, 0x07, 0x10, 0x08, 0x07, 0x00,
		0x37, 0x07, 0x0e, 0x07, 0x25, 0x09, 0x0f, 0x00,
		0x3e, 0x07, 0x03, 0x02, 0x25, 0x08, 0x11, 0x00,
		0x3a, 0x08, 0x10, 0x07, 0x10, 0x09, 0x07, 0x00,
		0x37, 0x08, 0x12, 0x07, 0x3e, 0x08, 0x02, 0x01,
		0x47, 0x00, 0x01, 0x00, 0x12, 0x62, 0x75, 0x69,
		0x6c, 0x64, 0x6d, 0x65, 0x74, 0x61, 0x74, 0x79,
		0x70, 0x65, 0x1b, 0x72, 0x5f, 0x72, 0x73, 0x62,
		0x69, 0x6e, 0x5f, 0x66, 0x6f, 0x72, 0x6d, 0x61,
		0x74, 0x74, 0x61, 0x73, 0x6b, 0x5f, 0x62, 0x6f,
		0x78, 0x0c, 0x74, 0x79, 0x70, 0x65, 0x64, 0x65,
		0x66, 0x15, 0x72, 0x73, 0x62, 0x69, 0x6e, 0x2e,
		0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x74, 0x61,
		0x73, 0x6b, 0x0b, 0x6d, 0x6f, 0x64, 0x75, 0x6c,
		0x65, 0x09, 0x74, 0x61, 0x73, 0x6b, 0x0b, 0x6c,
		0x6f, 0x61, 0x64, 0x65, 0x64, 0x0c, 0x70, 0x61,
		0x63, 0x6b, 0x61, 0x67, 0x65, 0x09, 0x63, 0x61,
		0x73, 0x74, 0x09, 0x09, 0x7d, 0x2a, 0x0a, 0x0e,
		0x09, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x7b,
		0x0a, 0xce, 0x01, 0x09, 0x74, 0x79, 0x70, 0x65,
		0x64, 0x65, 0x66, 0x20, 0x76, 0x6f, 0x69, 0x64,
		0x20, 0x72, 0x73, 0x62, 0x69, 0x6e, 0x5f, 0x66,
		0x6f, 0x72, 0x6d, 0x61, 0x74, 0x74, 0x61, 0x73,
		0x6b, 0x3b, 0x0a, 0x09, 0x74, 0x79, 0x70, 0x65,
		0x64, 0x65, 0x66, 0x20, 0x73, 0x74, 0x72, 0x75,
		0x63, 0x74, 0x20, 0x72, 0x5f, 0x72, 0x73, 0x62,
		0x69, 0x6e, 0x5f, 0x66, 0x6f, 0x72, 0x6d, 0x61,
		0x74, 0x74, 0x61, 0x73, 0x6b, 0x5f, 0x62, 0x6f,
		0x78, 0x20, 0x7b, 0x0a, 0x09, 0x09, 0x72, 0x73,
		0x62, 0x69, 0x6e, 0x5f, 0x66, 0x6f, 0x72, 0x6d,
		0x61, 0x74, 0x74, 0x61, 0x73, 0x6b, 0x2a, 0x20,
		0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x3b, 0x0a,
		0x09, 0x09, 0x76, 0x6f, 0x69, 0x64, 0x28, 0x2a,
		0x63, 0x66, 0x72, 0x65, 0x65, 0x70, 0x74, 0x72,
		0x29, 0x28, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74,
		0x20, 0x72, 0x5f, 0x72, 0x73, 0x62, 0x69, 0x6e,
		0x5f, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x74,
		0x61, 0x73, 0x6b, 0x5f, 0x62, 0x6f, 0x78, 0x2a,
		0x20, 0x73, 0x65, 0x6c, 0x66, 0x29, 0x3b, 0x0a,
		0x09, 0x09, 0x76, 0x6f, 0x69, 0x64, 0x2a, 0x20,
		0x66, 0x72, 0x65, 0x65, 0x70, 0x74, 0x72, 0x3b,
		0x0a, 0x09, 0x7d, 0x20, 0x72, 0x5f, 0x72, 0x73,
		0x62, 0x69, 0x6e, 0x5f, 0x66, 0x6f, 0x72, 0x6d,
		0x61, 0x74, 0x74, 0x61, 0x73, 0x6b, 0x5f, 0x62,
		0x6f, 0x78, 0x3b, 0x0a, 0x05, 0x09, 0x63, 0x64,
		0x65, 0x66, 0x1c, 0x72, 0x65, 0x66, 0x6c, 0x65,
		0x63, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x75, 0x6e,
		0x77, 0x72, 0x61, 0x70, 0x6f, 0x62, 0x6a, 0x65,
		0x63, 0x74, 0x1a, 0x72, 0x65, 0x66, 0x6c, 0x65,
		0x63, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x77, 0x72,
		0x61, 0x70, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74,
		0x1c, 0x72, 0x65, 0x66, 0x6c, 0x65, 0x63, 0x74,
		0x69, 0x6f, 0x6e, 0x2e, 0x65, 0x78, 0x63, 0x65,
		0x70, 0x74, 0x69, 0x6f, 0x6e, 0x62, 0x6f, 0x78,
		0x08, 0x66, 0x66, 0x69, 0x0c, 0x72, 0x65, 0x71,
		0x75, 0x69, 0x72, 0x65, 0x01, 0x02, 0x02, 0x02,
		0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05,
		0x05, 0x06, 0x07, 0x11, 0x11, 0x06, 0x14, 0x19,
		0x19, 0x1a, 0x1a, 0x1a, 0x1a, 0x1f, 0x1f, 0x1f,
		0x1f, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x25, 0x25,
		0x25, 0x25, 0x72, 0x70, 0x74, 0x72, 0x00, 0x02,
		0x25, 0x66, 0x66, 0x69, 0x00, 0x03, 0x22, 0x72,
		0x5f, 0x65, 0x78, 0x63, 0x65, 0x70, 0x74, 0x69,
		0x6f, 0x6e, 0x62, 0x6f, 0x78, 0x00, 0x03, 0x1f,
		0x72, 0x5f, 0x77, 0x72, 0x61, 0x70, 0x6f, 0x62,
		0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x1c, 0x72,
		0x5f, 0x75, 0x6e, 0x77, 0x72, 0x61, 0x70, 0x6f,
		0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x19,
		0x70, 0x74, 0x72, 0x74, 0x79, 0x70, 0x65, 0x00,
		0x08, 0x11, 0x72, 0x00, 0x04, 0x0d, 0x72, 0x73,
		0x62, 0x69, 0x6e, 0x5f, 0x66, 0x6f, 0x72, 0x6d,
		0x61, 0x74, 0x74, 0x61, 0x73, 0x6b, 0x00, 0x07,
		0x06, 0x00, 0x00,	};
}
extern r::module const r_rsbin_formattask_module;
r::module const r_rsbin_formattask_module = {
	&r_ptr,
	&r_chunk,
	sizeof( r_chunk ),
	"rsbin/formattask.r.lua" };
