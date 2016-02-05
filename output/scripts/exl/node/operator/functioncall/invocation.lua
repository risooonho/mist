local modname = ...
local invbase = package.relrequire(modname, 2, 'base.invocation')
local invfunctioncall = invbase:module(modname)
local fulltype

function invfunctioncall:init(it)
	invbase.init(self, it)
	-- self.context = it.context
	self.base = it.base
	self.outargs = it.outargs
	self.inargs = it.inargs
	if it.ti then
		self.fulltype = fulltype:create(it.ti, false, true)
	else
		self.fulltype = fulltype:create(invbase:getfulltype().ti, false, false)
	end
end

function invfunctioncall:rcompile(stream)
	if not self.retname then
		local basename = self.base:rcompile(stream)
		local args = {}
		for i, iarg in ipairs(self.inargs) do
			args[i] = {'ssa', iarg:rcompile(stream)}
		end
		local results = {}
		if self.fulltype.rvalue then
			self.retname = stream:genname()
			results[1] = self.retname
		else
			self.retname = 0
		end
		for i, oarg in ipairs(self.outargs) do
			table.append(results, stream:genname())
		end
		local resultargs = {}
		for i, rarg in ipairs(results) do
			table.append(resultargs, {'ssa', rarg})
		end
		stream:writetoken{
			op = 'call',
			args = {
				{'ssa', basename}, -- function
				{'list', items = args}, -- args
				{'list', items = resultargs}, -- results
			},
		}
		for i, oarg in ipairs(self.outargs) do
			if self.fulltype.rvalue then
				oarg:lcompile(stream, results[i+1])
			else
				oarg:lcompile(stream, results[i])
			end
		end
	end
	return self.retname
end

fulltype = package.relrequire(modname, 4, 'fulltype')