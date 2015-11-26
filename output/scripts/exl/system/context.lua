local modname = ...
local context = require('exl.context')
local scontext = context:create()
package.modtable(modname, scontext)
local aofunc = require('exl.system.assignoperator.func')
local common = require('exl.common')
local etypedef = require('exl.system.typedef')
local fulltype = require('exl.fulltype')
local nofunc = require('exl.system.nativeoperator.func')
local numberti = require('exl.system.ti.number')
local prototype = require('exl.prototype')
local stringti = require('exl.system.ti.string')
local symconst = require('exl.symbol.const')
local utility = require('base.utility')

local env = {}
function env:log(...)
	print('=', ...)
end

scontext.env = env

scontext:setsymbol('number', symconst:create{
	context = scontext,
	fulltype = fulltype:create(nil, false, false),
	constvalue = etypedef:create{
		typeinfo = numberti,
	},
})

scontext:setsymbol('string', symconst:create{
	context = scontext,
	fulltype = fulltype:create(nil, false, false),
	constvalue = etypedef:create{
		typeinfo = stringti,
	},
})

local function binopconstf(name, valf)
	return function(args)
		local node = common.createnode{
			name = name,
			spos = args[1].spos,
			epos = args[2].epos,
			value = valf(args[1].value, args[2].value),
		}
		return node
	end
end

local function rvpt(ti)
	return fulltype:create(ti, false, true)
end

local function lvpt(ti)
	return fulltype:create(ti, true, false)
end

local function lrvpt(ti)
	return fulltype:create(ti, true, true)
end

local opset = scontext:getopset()

opset:insert(
	'concat',
	prototype:create{rvpt(stringti), rvpt(stringti)},
	nofunc:create{
		rettype = rvpt(stringti),
		constfunc = binopconstf('expr.string', utility.operator.concat),
		opcode = 'a_concat',
	})

opset:insert(
	'mul',
	prototype:create{rvpt(numberti), rvpt(numberti)},
	nofunc:create{
		rettype = rvpt(numberti),
		constfunc = binopconstf('expr.number', utility.operator.mul),
		opcode = 'a_mul',
	})

opset:insert(
	'div',
	prototype:create{rvpt(numberti), rvpt(numberti)},
	nofunc:create{
		rettype = rvpt(numberti),
		constfunc = binopconstf('expr.number', utility.operator.div),
		opcode = 'a_div',
	})

opset:insert(
	'add',
	prototype:create{rvpt(numberti), rvpt(numberti)},
	nofunc:create{
		rettype = rvpt(numberti),
		constfunc = binopconstf('expr.number', utility.operator.add),
		opcode = 'a_add',
	})

opset:insert(
	'sub',
	prototype:create{rvpt(numberti), rvpt(numberti)},
	nofunc:create{
		rettype = rvpt(numberti),
		constfunc = binopconstf('expr.number', utility.operator.sub),
		opcode = 'a_sub',
	})

numberti:getopset():insert(
	'assign',
	prototype:create{lvpt(numberti), rvpt(numberti)},
	aofunc:create{
		rettype = rvpt(numberti),
		opcode = 'a_setl',
	})

stringti:getopset():insert(
	'assign',
	prototype:create{lvpt(stringti), rvpt(stringti)},
	aofunc:create{
		rettype = rvpt(stringti),
		opcode = 'a_setl',
	})