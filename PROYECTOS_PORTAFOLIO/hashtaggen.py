#It must start with a hashtag (#). Debe iniciar con hashtag
#All words must have their first letter capitalized. Letras iniciales en mayusucla
#If the final result is longer than 140 chars it must return false. Sis e ingresa mas de 140 caracteres false
#If the input or the result is an empty string it must return false. si es cadena vacia false

def generate_hashtag(s):
    if s:
        s = s.split()
        w=[ _.capitalize() for _ in s ]
        r=f"#{''.join(w)}"
        if 140<len(r): return False
        else: return r
    else:return False

print(generate_hashtag())
