"""Only a programm to make example for executions
"""

import time

open("testfile.txt", "w+").write(f"{int(round(time.time() * 1000))}\ndefault\nhttps://github.com/CastellaniDavide/create_structure/blob/master/.github/workflows/test.yml\ntest\nn\nn\n")
print("File created")
