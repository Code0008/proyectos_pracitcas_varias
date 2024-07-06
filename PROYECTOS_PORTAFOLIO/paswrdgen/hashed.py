import hashlib

class HashedEmail:
    def hashed_sha1(self,password):
        hashed_password = hashlib.sha1(password.encode("utf-8")).hexdigest().upper()
        return hashed_password
    def hashed_md5(self,password):
        hashed_password = hashlib.md5(password.encode("utf-8")).hexdigest().upper()
        return hashed_password
    def hashed_sha256(self, password):
        hashed_password = hashlib.sha256(password.encode("utf-8")).hexdigest().upper()
        return hashed_password
    

if __name__ == "__main__":
    inter = HashedEmail()

    
