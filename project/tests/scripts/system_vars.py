integer = [
    ['lld', 'long long', 9223372036854775807, -9223372036854775808],
    ['ld', 'long', 9223372036854775807, -9223372036854775808],
    ['lu', 'unsigned long', 18446744073709551615, 0],
    ['d', 'signed', 2147483647, -2147483648],
    ['u', 'unsigned', 4294967295, 0],
    ['hd', 'short', 32767, -32768],
    ['hu', 'unsigned short', 65535, 0],
    ['c', 'char', 127, -128],
    ['c', 'unsigned char', 255, 0],
    ['d', '_Bool', 1, 0],
]

directory = 'env'
filename1 = f'{directory}/code1.c'
filename2 = f'{directory}/code2.c'
logfile1 = f'{directory}/log1.txt'
logfile2 = f'{directory}/log2.txt'
eo_out = f'{directory}/eo_out.txt'
c_out = f'{directory}/c_out.txt'
launcher = '../../bin/launcher.py'
fulllog = None
resultDir = "../../../result"