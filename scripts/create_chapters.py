import os
from shutil import copytree


project_name_template_text = '<project_name>'
master_cmake_path = os.path.join('CMakeLists.txt')


def main():
    working_dir = os.path.join('..')
    os.chdir(working_dir)
    for ch in range(1,2):
        day_name = f'day_{ch}'
        copytree('template', day_name, dirs_exist_ok=True)

        day_cmake = os.path.join(day_name, 'CMakeLists.txt')
        with open(day_cmake, 'r') as cmake_file:
            cmake_text = cmake_file.read()

        
        modified = cmake_text.replace(project_name_template_text, day_name)
        with open(day_cmake, 'w') as cmake_file:
            cmake_file.write(modified)

            
if __name__ == "__main__":
    main()

