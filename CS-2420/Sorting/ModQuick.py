
from Quick import Quick


class ModQuick(Quick):
    def __init__(self, size=100, debug=False, unique=False):
        Quick.__init__(self, size, debug, unique)
        self.modified = True
        return
