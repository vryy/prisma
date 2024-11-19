from __future__ import print_function, absolute_import, division #makes KratosMultiphysics backward compatible with python 2.6 and 2.7
import sys
if sys.platform.startswith('linux'):
    try:
        import DLFCN as dl
        mode = dl.RTLD_NOW | dl.RTLD_GLOBAL
    except ImportError:  # For Python 3
        import os
        mode = os.RTLD_NOW | os.RTLD_GLOBAL
    flags = sys.getdlopenflags()
    sys.setdlopenflags(mode)
    import mpipython
    sys.setdlopenflags(flags)
else:
    import mpipython

#__all__ = ['mpi']

mpi = mpipython.GetMPIInterface()
