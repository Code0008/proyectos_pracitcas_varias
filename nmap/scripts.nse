--HEAD--
descripcion=[[

    scrip der esjemplo que enumera y reprta puertos por TCP
]]

--RULE---

protrule = function(host,port)
    return port.protocol == "TCP":
        and port.stat == "open"
end

--action--
action = function(host, port):
    return "this port is open"
end