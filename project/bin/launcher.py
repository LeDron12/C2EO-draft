#! /usr/bin/python3
# launcher.py - запуск транспилятора и сборщика, очистка промежуточных хранилищ.

#------------------------------------------------------------------------------
import os
import sys
import glob
import shutil

#------------------------------------------------------------------------------
# Каталог для размещения файлов на EO, полученных в ходе транспиляции и сборки
# Указан относительно текущего каталога
resultDir = "../../result/eo/c2eo/src/"

#------------------------------------------------------------------------------
# Каталог в котором формируется файл global.eo для последующей пересылки в
# каталог проекта на EO
assemblyDir = "../assembly/"

#------------------------------------------------------------------------------
if __name__ == '__main__':
    argc = len(sys.argv)
    print(f'argc = {argc}')
    argv = sys.argv
    print(f'argv = {argv}')

    pathToCurrDir = argv[0].replace('launcher.py', '')

    # Получение текущего каталога
    print(f'Current Working Directory is: {os.getcwd()}')
    # Проверка наличия нужного каталога
    if os.path.exists(pathToCurrDir + resultDir):
        print(f'Result Directory is: {pathToCurrDir + resultDir}')

    # Получение содержимого каталога
    print(f'Directory {pathToCurrDir + resultDir} contain: {os.listdir(pathToCurrDir + resultDir)}')
    print(f'Directory {pathToCurrDir + assemblyDir} contain: {os.listdir(pathToCurrDir + assemblyDir)}')
    #globFileList = glob.globlist(glob(os.path.join('sample_data', '*.csv')))
    resultFileList = list(glob.glob(os.path.join(pathToCurrDir + resultDir, '*.eo')))
    print(f'Directory {pathToCurrDir + resultDir} contain: {resultFileList}')
    assemlyFileList = list(glob.glob(os.path.join(pathToCurrDir + assemblyDir, '*.c')))
    print(f'Directory {pathToCurrDir + assemblyDir} contain: {assemlyFileList}')

    # Удаление всех файлов, находящихся в каталоге pathToCurrDir + assemblyDir
    for file in list(glob.glob(os.path.join(pathToCurrDir + assemblyDir, '*'))):
        os.remove(file)
    # Запуск транспилятора

    if argc < 2:
        print(f'Incorrect number of argument = {argc}')
        exit(1)

    c2eoProgram = pathToCurrDir + '/c2eo ' + argv[1] + ' static01'
    print(f'c2eoProgram = {c2eoProgram}')


    os.system(c2eoProgram)
    #os.startfile(c2eoProgram)
    
    #for file in list(glob.glob(os.path.join(pathToCurrDir + assemblyDir, '*.c'))):
    #    shutil.move(file, pathToCurrDir + resultDir)

    # Запуск сборщика
    collectorScript = pathToCurrDir + '/collector.py'
    os.system(collectorScript)
    #os.startfile(r'./collector')

   # Удаление всех файлов, находящихся в каталоге pathToCurrDir + resultDir
    for file in list(glob.glob(os.path.join(pathToCurrDir + resultDir, '*'))):
        os.remove(file)

    # Проверка наличия файла global.eo в каталоге assembly
    if os.path.exists(os.path.join(pathToCurrDir + assemblyDir, 'global.eo')):
        shutil.move(os.path.join(pathToCurrDir + assemblyDir, 'global.eo'), pathToCurrDir + resultDir)
    else:
        print(f'File global.eo is absence in: {pathToCurrDir + assemblyDir}')
        exit(2)

    print('Launcher: OK!')

