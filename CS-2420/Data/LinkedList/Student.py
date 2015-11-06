
class Student:
    def __init__(self, first, last, ssn, email, age):
        self.first = first
        self.last = last
        self.ssn = ssn
        self.email = email
        self.age = age
        return

    def get_ssn(self):
        return self.ssn

    def __eq__(self, rhs):
        return self.ssn == rhs.ssn
