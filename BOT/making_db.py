import json
import string
import datetime
import random
import time
class key_sistem():
    def __init__(self) -> None:
        self.path = "d:\python\hack4u\BOT\keys.json"
    def updater_json(self):
        try:
            pre_json = json.load(open(self.path))
            pre_json[int(self.user_id)]= self.dict_of_user
            upate = json.dump(pre_json,fp=open(self.path, "w"), indent=4 )
        except json.decoder.JSONDecodeError:
            print("No data")

    def create_user(self, username:str, ID:int, day:int):
        self.username = username
        self.user_id = ID
        expire =( datetime.datetime.now() + datetime.timedelta(days=int(day)) ).strftime("%Y-%m-%d %H:%M:%S")
        key = "".join(random.choice(string.ascii_letters) for _ in range(10))
        self.dict_of_user = {
            "Username": self.username, 
            "USER ID": self.user_id,
            "KEY": key,
            "MEMBERSHIP EXPIRATION":expire ,
            "CREDITS": random.randrange(10, 100),
            "ANTISPAM": random.randrange(10, 60)
        }

if __name__ == '__main__':
    usernames = [''.join(random.choices(string.ascii_letters+string.digits, k=10)) for _ in range(20)]
    for _ in range(len(usernames)):
        
        key_maker = key_sistem()
        key_maker.create_user(random.choice(usernames), random.randint(100000, 20000000),random.randrange(1,30))
        key_maker.updater_json()
