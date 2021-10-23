import os
import sys
import difflib
from system_vars import *


def compile_run():
    if os.system(' '.join(['gcc', f'{filename2}', '-w', f'>>{logfile1}', f'2>>{logfile2}'])) != 0:
        return False, 'can not compile c-code'
    if os.system(' '.join(['./a.out', f'>{c_out}', f'2>>{logfile2}'])) != 0:
        return False, 'can not run c-code'
    if os.system(' '.join([launcher, f'{filename1}', f'>>{logfile1}', f'2>>{logfile2}'])) != 0:
        return False, 'can not transpile c-code to eo-code'
    if os.system(' '.join(['mvn -f', resultDir, 'clean compile', f'>>{logfile1}', f'2>>{logfile2}'])) != 0:
        return False, 'can not compile eo-code using mvn'
    # todo: show global.eo
    if os.system(' '.join(['java', '-cp', f'{resultDir}/target/classes:'
                                          f'{resultDir}/target/eo-runtime.jar',
                           'org.eolang.Main', 'c2eo.app', f'>{eo_out}', f'2>>{logfile2}'])) != 0:
        return False, 'can not run eo-code'
    return True, 'too easily'


def generate(c_type, value, static=False):
    code = '\n'.join([f'{"static " if static else ""}{c_type[1]} var = {value};',
                      'int main() {', '\t%svar%s;', '\treturn 0;', '}'])
    with open(filename1, 'w') as fout:
        print(code % ('', ''),
              file=fout)
    # todo: show code1
    code = '\n'.join(['#include "stdio.h"', code])
    with open(filename2, 'w') as fout:
        print(code % (f'printf("%{c_type[0]}\\n", ', ')'),
              file=fout)
    # todo: show code2


def compare():
    with open(c_out, 'r') as f1:
        with open(eo_out, 'r') as f2:
            diff = difflib.unified_diff(
                f1.readlines(),
                f2.readlines(),
                fromfile=c_out,
                tofile=eo_out,
            )
            # todo: show diff
            # print(list(diff))
            # for line in diff:
            #    print(line)
            # self.assertEqual(len(list(diff)), 0, msg='there are some diffs:')
            return len(list(diff)) == 0, 'there are some diffs'
