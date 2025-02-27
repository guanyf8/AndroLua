local s = require "serialize"

local addressbook = {
    name = "Alice",
    id = 12345,
    phone = {
        { number = "1301234567" },
        { number = "87654321", type = "WORK" },
    }
}
print(addressbook)

s.pack(addressbook)