import datetime
import system_vars
from global_tests import *

if __name__ == '__main__':
    system_vars.fulllog = datetime.datetime.now().strftime("%y-%m-%d#%H-%M.log")
    unittest.main()
