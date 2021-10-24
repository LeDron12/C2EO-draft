import datetime
import system_vars
from global_tests import *
import sys

if __name__ == '__main__':
    argc = len(sys.argv)
    argv = sys.argv
    system_vars.path = argv[0].replace('utests.py', '')
    system_vars.full_log = datetime.datetime.now().strftime("%y-%m-%d#%H-%M.log")
    sys.stdout = open(system_vars.path + system_vars.full_log, 'w')
    unittest.main()
    sys.stdout.close()
