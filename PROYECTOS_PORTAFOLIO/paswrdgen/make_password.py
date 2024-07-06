import random
import hashed

def random_selec():
    letter = [chr(i) for i in range(ord('A'), ord('Z')+1)]
    letters_upper = [chr(i) for i in range(ord('a'), ord('z')+1)]
    spcecial_chars =[chr(i) for i in range(33, 127) if chr(i).isprintable() and not chr(i).isalnum()]
    nums = [chr(i) for i in range(ord("0"), ord("9")+1)]
    yield random.choice(letter), random.choice(letters_upper), random.choice(spcecial_chars), random.choice(nums)

def make_password(longitud=None):
        temp_gen=[]
        pswd= []
        while len(temp_gen)<longitud:
            for i in random_selec():
                temp_gen.append(i)
        while len(pswd)<longitud:
            pswd.append(temp_gen[random.randrange(0,12)][random.randrange(0,4)])
        return ''.join(pswd)    

if  __name__ == "__main__":
    lista_pasword=[make_password(12) for _ in range(12)]
    hasheder = hashed.HashedEmail()
    sta_pasword = [hasheder.hashed_md5(lista_pasword[i]) for i in range(0, 12)]
    print('\n'.join(sta_pasword))
    