import os


# WARNING: This script leaves cumulative side effects. Only run once. Reset main CMakeLists.txt if you wish to run again. 
def main():
    working_dir = os.path.join('..')
    os.chdir(working_dir)
    with open('CMakeLists.txt', 'a') as cmake_file:
        sub_dir_lines = [f'add_subdirectory(\"day_{day}\")\n' for day in range(1,26)]
        cmake_file.writelines(sub_dir_lines)


if __name__ == '__main__':
    main()