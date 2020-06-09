import os

testing = False
renaming_folders = False

if __name__ == '__main__':
    main_directory = os.path.dirname(os.path.realpath(__file__)) # getting curren script directory

    if renaming_folders:
        for root, dirs, files in os.walk(main_directory): # getting current subdirectories
            subdirectories = dirs
            break

        for directory in subdirectories: # for each subdirectory
            if len(directory) > 5: # to ignore .git folder
                split_directory_name = directory.split('.') # getting task number

                while len(split_directory_name[0]) < 4: # prepend to length 4
                    split_directory_name[0] = '0' + split_directory_name[0]

                new_directory_name = '.'.join(split_directory_name) # new directory name
                os.rename(os.path.join(main_directory, directory), os.path.join(main_directory, new_directory_name)) # renaming directory

                if testing:
                    break

    for root, dirs, files in os.walk(main_directory): # getting current subdirectories with new names
        subdirectories = dirs
        break

    for directory in subdirectories: # for each subdirectory
        if len(directory) > 5: # to ignore .git folder
            for root, dirs, files in os.walk(os.path.join(main_directory, directory)): # getting filenames
                current_files = files
                break

            for file in current_files: # for each file
                if '.' in file: # if file has an extension
                    file_full_path = os.path.join(main_directory, directory, file) # getting full filepath
                    extension = file.split('.')[1] # getting file extension

                    if extension == 'db': # there is no need in preview files (Thumbs.db) in the repo
                        os.remove(file_full_path)
                    elif extension == 'md' or extension == 'cpp' or extension == 'py': # do not touch other files
                        with open(file_full_path, 'r') as file: #read file data line
                            file_data = file.read().split('\n')

                        new_data = [] # new data
                        for s in file_data: # for each string in file
                            new_data.append(s.rstrip()) # rstrip that string

                        with open(file_full_path, 'w') as file: # write new data to file
                            file.write('\n'.join(new_data))

                    if extension == 'cpp': # if it happens to be a cpp file
                        with open(file_full_path, 'r') as file: #read file data line
                            file_data = file.read().split('\n')

                        new_data = ['static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();'] # new data
                        for s in file_data: # for each string in file
                            if s.find('static auto _') == -1: # only single copy of speedup
                                new_data.append(s.rstrip()) # rstrip that string

                        with open(file_full_path, 'w') as file: # write new data to file
                            file.write('\n'.join(new_data))

            if testing:
                break