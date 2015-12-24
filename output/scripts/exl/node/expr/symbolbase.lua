local modname = ...
local ebase = package.relrequire(modname, 1, 'base')
local esymbolbase = ebase:module(modname)
local common

function esymbolbase:init(pr)
	ebase.init(self, pr)
end

function esymbolbase:build(pc)
	self.fulltype = self.target:getfulltype()
	self.constvalue = self.target:getconstvalue()
end

function esymbolbase:lcompile(stream, source)
	self.target:lcompile(stream, source)
end

function esymbolbase:rcompile(stream)
	if self.constvalue and self.constvalue.bsimplevalue then
		return self.constvalue:rcompile(stream)
	else
		if not self.retname then
			self.retname = self.target:rcompile(stream)
		end
		return self.retname
	end
end

common = package.relrequire(modname, 3, 'common')