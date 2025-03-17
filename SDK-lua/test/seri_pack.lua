--local s = require "serialize"



local function temp()
    local a=2
end

local rr=888

local addressbook = {
    name = "Alice",
    id = 12345,
    phone = {
        { number = "1301234567" },
        { number = "87654321", type = "WORK" },
    },
    rr
}

local num=3
local name="happy"

local p,size=seri.pack(addressbook,num,name)
local pushtask=taskqueue.pushtask(p,size,1)