
class Student:
    def __init__(self, ssn, first="", last="", email="", age=""):
        self.first = first
        self.last = last
        self.ssn = ssn
        self.email = email
        self.age = age
        return

    def get_ssn(self):
        return self.ssn

    def get_age(self):
        return self.age

    def __int__(self):
        return int(self.ssn.replace('-', ''))

    def __eq__(self, rhs):
        return self.ssn == rhs.ssn

    def __ne__(self, rhs):
        return self.ssn != rhs.ssn

    def __lt__(self, rhs):
        return

    def __le__(self, rhs):
        return

    def __gt__(self, rhs):
        return

    def __ge__(self, rhs):
        return
