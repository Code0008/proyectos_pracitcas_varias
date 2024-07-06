import json
from making_db import key_sistem

class Functions_admin:
    def info_new_user(self, username, day, ID):
        maker = key_sistem()
        maker.create_user(username, ID, day)
        maker.updater_json()


if __name__ == "__main__":
    admin  = Functions_admin()
    admin.info_new_user("TILIN INSANO", 20, 1232231312321)

