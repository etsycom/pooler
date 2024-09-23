import os
import sys

if len(sys.argv) < 2:
    path = input('enter input file: ')
    out = input('enter output file: ')

    if os.path.exists(path):
        with open(path, 'rb') as file:
            a = bytearray(b ^ b'x'[i % len(b'x')] for i, b in enumerate(file.read()))
            file.close()

        with open(out, 'wb') as file:
            file.write(a)
            file.close()

    else:
        print('invalid input path!')
        input('press any enter to continue...')

else:
    if os.path.exists(sys.argv[1]):
        with open(sys.argv[1], 'rb') as file:
            a = bytearray(b ^ b'x'[i % len(b'x')] for i, b in enumerate(file.read()))
            file.close()

        with open(sys.argv[2], 'wb') as file:
            file.write(a)
            file.close()

    else:
        if not os.path.exists(sys.argv[1]):
            print(f'{sys.argv[1]} does not exist!')
            
        print('usage: pooler [input path] [output path]')