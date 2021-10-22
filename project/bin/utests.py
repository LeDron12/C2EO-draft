import os
import random
import sys
import unittest
import difflib
import inspect

integer = [
    ['lld', 'long long', 9223372036854775807, -9223372036854775808],
    ['ld', 'long', 9223372036854775807, -9223372036854775808],
    ['lu', 'unsigned long', 18446744073709551615, 0],
    ['d', 'signed', 2147483647, -2147483648],
    ['u', 'unsigned', 4294967295, 0],
    ['hd', 'short', 32767, -32768],
    ['hu', 'unsigned short', 65535, 0],
    ['c', 'char', 127, -128],
    # ['c', 'unsigned char', 255, 0],
]

directory = 'env'
filename1 = f'{directory}/code1.c'
filename2 = f'{directory}/code2.c'
logfile1 = f'{directory}/log1.txt'
logfile2 = f'{directory}/log2.txt'
eo_out = f'{directory}/eo_out.txt'
c_out = f'{directory}/c_out.txt'

resultDir = "../../result"


def whoami():
    frame = inspect.currentframe()
    return inspect.getframeinfo(frame).function


class GlobalTestCase(unittest.TestCase):
    def compile_run(self, test_name):
        if True:
            ans = os.system(' '.join(['echo', "#" * 10, f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
            ans = os.system(
                ' '.join(['echo', f'{"#" * 3} TEST-CASE#{test_name} {"#" * 3}', f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
            ans = os.system(' '.join(['echo', "#" * 10, f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
        ans = os.system(' '.join(['gcc', f'{filename2}', '-w', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not compile c-code')
        ans = os.system(' '.join(['./a.out', f'>{c_out}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not run c-code')
        ans = os.system(' '.join(['./launcher.py', f'{filename1}', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not transpile c-code to eo-code')
        ans = os.system(' '.join(['mvn -f', resultDir, 'clean compile', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not compile eo-code using mvn')
        ans = os.system(' '.join(['java', '-cp', f'{resultDir}/target/classes:'
                                                 f'{resultDir}/target/eo-runtime.jar',
                                  'org.eolang.Main', 'c2eo.app', f'>{eo_out}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not run eo-code')

    @staticmethod
    def generate(c_type, value):
        with open(filename1, 'w') as fout:
            print('\n'.join([f'{c_type[1]} var = {value};',
                             'int main() {', '\tvar;', '\treturn 0;', '}']),
                  file=fout)
        with open(filename2, 'w') as fout:
            print('\n'.join(['#include "stdio.h";', f'{c_type[1]} var = {value};',
                             'int main() {', f'\tprintf("%{c_type[0]}\\n", var);', '\treturn 0;', '}']),
                  file=fout)

    def compare(self):
        with open(c_out, 'r') as hosts0:
            with open(eo_out, 'r') as hosts1:
                diff = difflib.unified_diff(
                    hosts0.readlines(),
                    hosts1.readlines(),
                    fromfile=c_out,
                    tofile=eo_out,
                )
                for line in diff:
                    sys.stdout.write(line)
                self.assertEqual(len(list(diff)), 0, msg='there some diffs:')

    # Long Long Tests
    def test_long_long_min(self):
        type = integer[0]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_long_max(self):
        type = integer[0]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_long_rnd(self):
        type = integer[0]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    # Long Tests
    def test_long_min(self):
        type = integer[1]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_max(self):
        type = integer[1]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_rnd(self):
        type = integer[1]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    # Unsigned Long Tests
    def test_unsigned_long_min(self):
        type = integer[2]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_unsigned_long_max(self):
        type = integer[2]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_unsigned_long_rnd(self):
        type = integer[2]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()


class StaticTestCase(unittest.TestCase):
    def compile_run(self, test_name):
        if True:
            ans = os.system(' '.join(['echo', "#" * 10, f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
            ans = os.system(
                ' '.join(['echo', f'{"#" * 3} TEST-CASE#{test_name} {"#" * 3}', f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
            ans = os.system(' '.join(['echo', "#" * 10, f'>>{logfile1}', f'2>>{logfile2}']))
            self.assertEqual(ans, 0, msg='os-lib error')
        ans = os.system(' '.join(['gcc', f'{filename2}', '-w', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not compile c-code')
        ans = os.system(' '.join(['./a.out', f'>{c_out}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not run c-code')
        ans = os.system(' '.join(['./launcher.py', f'{filename1}', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not transpile c-code to eo-code')
        ans = os.system(' '.join(['mvn -f', resultDir, 'clean compile', f'>>{logfile1}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not compile eo-code using mvn')
        ans = os.system(' '.join(['java', '-cp', f'{resultDir}/target/classes:'
                                                 f'{resultDir}/target/eo-runtime.jar',
                                  'org.eolang.Main', 'c2eo.app', f'>{eo_out}', f'2>>{logfile2}']))
        self.assertEqual(ans, 0, msg='can not run eo-code')

    @staticmethod
    def generate(c_type, value):
        with open(filename1, 'w') as fout:
            print('\n'.join([f'static {c_type[1]} var = {value};',
                             'int main() {', '\tvar;', '\treturn 0;', '}']),
                  file=fout)
        with open(filename2, 'w') as fout:
            print('\n'.join(['#include "stdio.h";', f'static {c_type[1]} var = {value};',
                             'int main() {', f'\tprintf("%{c_type[0]}\\n", var);', '\treturn 0;', '}']),
                  file=fout)

    def compare(self):
        with open(c_out, 'r') as hosts0:
            with open(eo_out, 'r') as hosts1:
                diff = difflib.unified_diff(
                    hosts0.readlines(),
                    hosts1.readlines(),
                    fromfile=c_out,
                    tofile=eo_out,
                )
                for line in diff:
                    sys.stdout.write(line)
                self.assertEqual(len(list(diff)), 0, msg='there some diffs:')

    # Long Long Tests
    def test_long_long_min(self):
        type = integer[0]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_long_max(self):
        type = integer[0]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_long_rnd(self):
        type = integer[0]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    # Long Tests
    def test_long_min(self):
        type = integer[1]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_max(self):
        type = integer[1]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_long_rnd(self):
        type = integer[1]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    # Unsigned Long Tests
    def test_unsigned_long_min(self):
        type = integer[2]
        value = type[-1]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_unsigned_long_max(self):
        type = integer[2]
        value = type[-2]
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()

    def test_unsigned_long_rnd(self):
        type = integer[2]
        value = random.randint(type[-1], type[-2] + 1)
        self.generate(type, value)
        self.compile_run(whoami())
        self.compare()


class MixedTestCase(unittest.TestCase):
    def test_long_long(self):
        self.assertEqual(True, True)


if __name__ == '__main__':
    unittest.main()
