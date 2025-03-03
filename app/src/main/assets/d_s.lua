
--local s = require "serialize"

local table
local data
local t=taskqueue.poptask()
table,a,b=seri.unpack(t)


print(table,a,b)