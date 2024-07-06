import json
class funcionalidades:
    def __init__(self) -> None:
        self.db= json.load(open("d:\python\hack4u\BOT\keys.json"))
    def premiun_user(self, user_id: str) -> bool:
        if(user_id in self.db.keys()):
            return True
        return False
    def get_user_data(self, user_id: str)-> dict[str]:
        response = f"""
        Username: { self.db[user_id]["Username"]}
        {self.db[user_id]["KEY"]}
        Membreship expires: {self.db[user_id]["MEMBERSHIP EXPIRATION"]}
        Credis: {self.db[user_id]["CREDITS"]}
        """
        return response
    
if __name__ == "__main__":
    funcionalidad = funcionalidades()
    print(funcionalidad.g