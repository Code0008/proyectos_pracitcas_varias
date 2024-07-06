import datetime



def make_logos(*args):
    if args:
        with open("logs.txt", "a") as logs:
            for data in args:
                logs.write(f"{datetime.datetime.now()}{'='*5}>{data}")




if __name__ == "__main__":
    make_logos("XD", "ASDVSC", 1212312312312321)