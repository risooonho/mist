local modname = ...
local ffipure = require('base.ffipure')
local tbase = ffipure:module(modname)
local token = require('exlb.token')

tbase.fields = [[
	uint32_t code;
]]

function tbase:create(ct)
	return self:new(ct.code)
end

function tbase.instmeta:__tostring()
	local name = token.codemap[self.code].name
	if name == 'v_function_body' then
		return '\t\t\t...)'
	elseif name == 'v_function_end' then
		return '\t\tend --[[function]]'
	else
		return string.format('%16s',
			name)
	end
end