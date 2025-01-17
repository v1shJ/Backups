def kthCharacter(k: int) -> str:
    
    s = "a"
    while len(s)<k:
        for i in s:
            #chartoadd
            c = (ord(i)-ord('a')+1)%26
            s += chr(c+ord('a'))
    return s, s[k-1]

print(kthCharacter(30000))