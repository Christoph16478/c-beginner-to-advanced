## :newspaper: About the project ##

**C programming form beginner to advanced:**

Examples, which will introduce up to advanced C programming. Goal is to get deeper understanding of programming concepts in the C Programming language.

The name of the projects are shon in the 'Folder structure' section and inform about the concept.

## :heavy_check_mark: Prerequisites ##

Project created with the help of:

* [Code::Blocks IDE](https://www.codeblocks.org/)

## :pencil2: Usage

Run and debug (Windows 11 only):

1. [Download and install MSYS2](https://www.msys2.org/)
1. Install the [GCC via the MSYS2 homepage](https://www.msys2.org/)
1. [Download and install Code::Blocks IDE](https://www.codeblocks.org/downloads/)
1. Run <code>mingw64.exe</code> and install gcc via <code>pacman -S --needed base-devel mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain \git subversion mercurial \mingw-w64-i686-cmake mingw-w64-x86_64-cmake</code>
1. Add GCC to path:
    1. go to <code>environment variables</code>
    1. in system variables section add a new entry to PATH/ path.
    1. add the following two lines <code>C:\msys64\mingw64\bin</code> and <code>C:\msys64\ming32\bin</code>
1. In Code::BLocks IDE go to __Settings__ -> __Debugger...__ -> __Default__ -> enter full path to compiler in __Executable path__ (e.g.: __C:\msys64\ucrt64\bin\gcc.exe__): 
1. Open all projects or a single one in the IDE
1. Select a virutal folder
1. Press run or debug button to execute program

## :file_folder: Folder structure ##

    c-beginner-to-advanced
    ├── LICENSE
    ├── README.md
    ├── 10_structs_and_type_deff
        └── ...      
    ├── 11_read_and_write_files
        └── ...      
    ├── 12_advanced_techniques
        └── ...      
    ├── 13_vector
        └── ...      
    ├── 14_1_single_linked_list
        └── ...  
    ├── 15_inner_outer_functions
        └── ...  
    ├── 16_csv_reader
        └── ...  
    ├── 17_morearrays
        └── ...  
    ├── 18_setting_and_reading_bits
        └── ...  
    ├── 19_using_bit_fields_to_pack
        └── ...  
    ├── 1_1_rectangle
        └── ...         
    ├── 1_variables_and_data
        └── ...    
    ├── 20_bitwise_operators
        └── ...  
    ├── 21_binary_numbers_and_bits
        └── ...  
    ├── 22_linked_lists
        └── ...   
    ├── 23_recursion
        └── ...  
    ├── 24_useful_c_libraries
        └── ...  
    ├── 25_unions
        └── ...  
    ├── 26_unions
        └── ...   
    ├── 27_advanced_control_flow
        └── ...    
    ├── 28_advanced_debugging_analysis_compiler_and_operations
        └── ...  
    ├── 29_advanced_pointers
        └── ...  
    ├── 2_logic
        └── ...        
    ├── 30_adnvanced_function_concepts
        └── ...  
    ├── 31_double_pointer
        └── ...  
    ├── 32_function_pointers
        └── ...  
    ├── 33_macros
        └── ...  
    ├── 34_networking
        └── ...  
    ├── 35_interprocess_communication_and_signals
        └── ...  
    ├── 36_string_functions
        └── ...  
    ├── 37_character_functions
        └── ...  
    ├── 38_formatting_functions
        └── ...  
    ├── 39_dynamic_library
        └── ...  
    ├── 3_loops
        └── ...   
    ├── 40_dynamic_loading
        └── ...  
    ├── 41_static_library
        └── ...  
    ├── 42_stack_and_queue
        ├── 42_stack_and_queue.cbp
        ├── balanced-parentheses.c
        ├── circular-queue.c
        ├── deque.c
        ├── infix-to-postfix.c
        ├── main.c
        ├── priority-queue.c
        ├── queue-using-array.c
        ├── queue-using-circular-linked-list.c
        ├── stack-using-array.c
        └── stack-using-linked-list.c
    ├── 43_trees
        ├── binary-search-tree-non-recursive-op.c
        ├── binary-search-tree-recursive-op.c
        ├── binary-tree.c
        ├── build-heap.c
        ├── heap.c
        ├── main.c
        └── trees.cbp
    ├── 44_sorting_algorithm
        ├── 44_sorting_algorithm.cbp
        ├── address-calculation-sort.c
        ├── binary-tree-sort.c
        ├── bubble-sort.c
        ├── heap-sort.c
        ├── insertion-sort.c
        ├── main.c
        ├── merge-sort-iterative.c
        ├── merge-sort-recursive.c
        ├── merging.c
        ├── quick-sort.c
        ├── radix-sort.c
        ├── selection-sort.c
        ├── shell-sort.c
        └── sorting-records.c
    ├── 45_linked_lists
        └── ...  
    ├── 46_algorithms_with_recursions
        └── ...  
    ├── 47_searching_and_hashing
        └── ...  
    ├── 4_1_functions_and_header
        └── ...           
    ├── 4_2_functions_and_headers
        └── ...            
    ├── 5_simple_pointer
        └── ...           
    ├── 7_arrays
        └── ...    
    ├── 8_pointer_arrays
        └── ...
    └── 9_Strings
        └── ...

## :books: Useful markdown resources ##

* [Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Complete list of github markdown emojis](https://dev.to/nikolab/complete-list-of-github-markdown-emoji-markup-5aia)
* [Awesome template](https://github.com/ma-shamshiri/Human-Activity-Recognition/blob/main/README.md)
* [.gitignore file](https://git-scm.com/docs/gitignore)