

class Mpi:

    class World:
        def __init__(self):
            pass

        def barrier(self):
            pass

    def __init__(self):
        self.size = 1
        self.rank = 0
        self.world = Mpi.World()

    def allgather(self, comm, thislist):
        return thislist

# mpi = Mpi()
