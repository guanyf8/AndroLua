---
--- Generated by EmmyLua(https://github.com/EmmyLua)
--- Created by guan.
--- DateTime: 2025/3/28 16:16
---

local Util=java.import("com.lockheed.parallelLJ.Util")


local m={}

m.throw=function(params,proxy)
    print("task throwed here I send it to Java")
    Util:testComplex(params,false,proxy)
end

return m
