import unittest
from system_vars import *
import random
import fun


class GlobalTestCase(unittest.TestCase):
    # Long Long Tests
    def test_long_long_min(self):
        c_type = integer[0]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_long_max(self):
        c_type = integer[0]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_long_min_overflow(self):
        c_type = integer[0]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        print(fun.compile_run())
        fun.compare()

    def test_long_long_max_overflow(self):
        c_type = integer[0]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_long_rnd(self):
        c_type = integer[0]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Long Tests
    def test_long_min(self):
        c_type = integer[1]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_max(self):
        c_type = integer[1]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_min_overflow(self):
        c_type = integer[1]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_max_overflow(self):
        c_type = integer[1]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_long_rnd(self):
        c_type = integer[1]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Unsigned Long Tests
    def test_unsigned_long_min(self):
        c_type = integer[2]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_long_max(self):
        c_type = integer[2]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_long_min_overflow(self):
        c_type = integer[2]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_long_max_overflow(self):
        c_type = integer[2]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_long_rnd(self):
        c_type = integer[2]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Signed Tests
    def test_signed_min(self):
        c_type = integer[3]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_signed_max(self):
        c_type = integer[3]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_signed_min_overflow(self):
        c_type = integer[3]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_signed_max_overflow(self):
        c_type = integer[3]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_signed_rnd(self):
        c_type = integer[3]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Unsigned Tests
    def test_unsigned_min(self):
        c_type = integer[4]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_max(self):
        c_type = integer[4]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_min_overflow(self):
        c_type = integer[4]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_max_overflow(self):
        c_type = integer[4]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_rnd(self):
        c_type = integer[4]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Short Tests
    def test_short_min(self):
        c_type = integer[5]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_short_max(self):
        c_type = integer[5]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_short_min_overflow(self):
        c_type = integer[5]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_short_max_overflow(self):
        c_type = integer[5]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_short_rnd(self):
        c_type = integer[5]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Unsigned Short Tests
    def test_unsigned_short_min(self):
        c_type = integer[6]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_short_max(self):
        c_type = integer[6]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_short_min_overflow(self):
        c_type = integer[6]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_short_max_overflow(self):
        c_type = integer[6]
        value = c_type[-2] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_unsigned_short_rnd(self):
        c_type = integer[6]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    # Char Tests
    def test_char_min(self):
        c_type = integer[7]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max(self):
        c_type = integer[7]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_min_overflow(self):
        c_type = integer[7]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max_overflow(self):
        c_type = integer[7]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_rnd(self):
        c_type = integer[7]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()


    # Unsigned Char Tests
    def test_char_min(self):
        c_type = integer[7]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max(self):
        c_type = integer[7]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_min_overflow(self):
        c_type = integer[7]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max_overflow(self):
        c_type = integer[7]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_rnd_overflow(self):
        c_type = integer[7]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()


    # Bool Tests
    def test_char_min(self):
        c_type = integer[7]
        value = c_type[-1]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max(self):
        c_type = integer[7]
        value = c_type[-2]
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_min_overflow(self):
        c_type = integer[7]
        value = c_type[-1] - 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_max_overflow(self):
        c_type = integer[7]
        value = c_type[-2] + 18
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()

    def test_char_rnd(self):
        c_type = integer[7]
        value = random.randint(c_type[-1], c_type[-2] + 1)
        fun.generate(c_type, value)
        fun.compile_run()
        fun.compare()
