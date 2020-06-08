import os

if __name__ == '__main__':
    main_directory = os.path.dirname(os.path.realpath(__file__))
    
    for root, dirs, files in os.walk(main_directory):
        subdirectories = dirs
        break

    for directory in subdirectories:
        if len(directory) > 5: # to ignore .git folder
            for root, dirs, files in os.walk(os.path.join(main_directory, directory)):
                current_files = files
                break
            
            print(current_files)
            
            for file in current_files:
                if '.' in file:
                    file_full_path = os.path.join(main_directory, directory, file)
                    extension = file.split('.')[1]
                    
                    if extension == 'db': # there is no need in preview files (Thumbs.db) in the repo
                        os.remove(file_full_path)
                    elif extension == 'md' or extension == 'cpp' or extension == 'py': # do not touch other files
                        with open(file_full_path, 'r') as file:
                            file_data = file.read().split('\n')
                        
                        new_data = []
                        for s in file_data:
                            new_data.append(s.rstrip())
                        
                        with open(file_full_path, 'w') as file:
                            file.write('\n'.join(new_data))
  
                    if extension == 'cpp':
                        pass
                        
                        # insert at the beginning
                        # static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
                        # and delete it (find with start static auto) from any other position
            
            break #just in case not to erase everything during a try