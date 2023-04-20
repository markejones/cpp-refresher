

#            "command": "/usr/bin/clang++",
#           "args": [
#                "-std=c++17",
#                "-fcolor-diagnostics",
#                "-fansi-escape-codes",
#                "-g",
#                "${file}",
#                "-o",
#                "${fileDirname}/${fileBasenameNoExtension}.out"

/usr/bin/clang++ -std=c++17 -fcolor-diagnostics -fansi-escape-codes -g $1 -o "${1%.*}".out