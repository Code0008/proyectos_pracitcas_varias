import requests

class scraper_of_cc:
    def __init__(self, cc) -> None:
        self.bin = cc.split("|")[0][0:6]
        self.api_info = dict(requests.get(f"https://bins.antipublic.cc/bins/{self.bin}").json())
    def get_info_of_cc_bin(self)->str:
        message = f"""
    bin: {self.bin}
    brand: {self.api_info["brand"]}
    country: {self.api_info["country"]}
    country_currencies: {",".join(self.api_info["country_currencies"])}
    level: {self.api_info["level"]}
    type:{self.api_info["type"]}
"""
        return message


if __name__ == "__main__":
    user = scraper_of_cc("4436280000528020|01|2025|572")
    print(user.get_info_of_cc_bin())

