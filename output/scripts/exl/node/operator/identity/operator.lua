local modname = ...
local opbase = package.relrequire(modname, 2, 'base.operator')
local opidentity = opbase:create{
	filename = 'system',
}
package.modtable(modname, opidentity)
local invidentity

function opidentity:invoke(it)
	log('-')
	if #it.args ~= 1 then
		return
	end
	local value = it.args[1]
	local vft = value:getfulltype()
	if not vft.rvalue then
		return
	end
	return invidentity:create{
		spos = it.spos,
		epos = it.epos,
		filename = it.filename,
		-- context = it.context,
		args = it.args,
		ti = vft.ti,
	}
end

invidentity = package.relrequire(modname, 1, 'invocation')