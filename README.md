# Sample Application in C
A simple solution to a larger set of requirements in building a web-application with a networked system method patent. This project was a mock up for investors to see how we could create a raffle to participate in with randomly generated ticket numbers, select a winner, and notify them via their mobile device. 

## Requirements from Admit Split LLC

* Aggregated list/group of users.
* A mock up raffle for participants to "play" their luck with. 
* A random way to selecting a winner.
* An email or text generated to inform the winning ticket holder. 

The build was not designed to be platform agnostic, or even cloud based. It was built on a bare bones Debian machine.

The entry point to main is in raf_main.c. I am still looking for the Makefile, but I do believe this project is in its entirety and could be rebuilt and run with little modification. 

## [VSCode build with Clang](https://code.visualstudio.com/docs/cpp/config-clang-mac)

The helloworld.cpp is C++. Start with reading [this](https://github.com/rolandrgarceau/Fix-a-hosed-MBP/blob/master/vscode-clang.md).

### Create task.json

1. Have the helloworld.cpp as the active file.
2. In VSCode Terminal > Configure Default Build Task
3. Select clang++ build active file to populate the .json file in a .vscode directory.

### VSCode options
The JSON above differs from the default template JSON in the following ways:

* "args" is updated to compile with C++17 because our helloworld.cpp uses C++17 language features.
* Changes the current working directory directive ("cwd") to the folder where helloworld.cpp is.
* The command setting specifies the program to run. In this case, "clang++" is the driver that causes the Clang compiler to expect C++ code and link against the C++ standard library.

* The args array specifies the command-line arguments that will be passed to clang++. These arguments must be specified in the order expected by the compiler.

* This task tells the C++ compiler to compile the active file (${file}), and create an output file (-o switch) in the current directory (${fileDirname}) with the same name as the active file (${fileBasenameNoExtension}), resulting in helloworld for our example.

* The label value is what you will see in the tasks list. Name this whatever you like.

* The problemMatcher value selects the output parser to use for finding errors and warnings in the compiler output. For clang++, you'll get the best results if you use the $gcc problem matcher.

* The "isDefault": true value in the group object specifies that this task will be run when you press ⇧⌘B. This property is for convenience only; if you set it to false, you can still build from the Terminal menu with Terminal > Run Build Task.

## Run the Build

1. Set the hellowworld.cpp as active again.
2. Shift + command + B or from the Terminal main menu choose Run Build Task.

* The terminal should output a success or fail with an Executing Task:
* There should be an -o and a .dSYM file in the cwd too. 
* We should be able to run in terminal ./helloworld

## Debug [issue with Catalina](https://github.com/microsoft/vscode-cpptools/issues/3829)

* We can create a launch.json to launch the LLDB debugger.
* Run > Add Configuration... and then choose C++ (GDB/LLDB).
  Then select clang++ build and debug active file.
* Run > Start Debugging.

See step over and set a watch for more debug options

## c_cpp_properties.json

We may also change settings such as the path to the compiler, include paths, which C++ standard to compile against (such as C++17), and more.

View the C/C++ configuration UI by running the command C/C++: Edit Configurations (UI) from the Command Palette.

We only need to modify the Include path setting if our program includes header files that are not in our workspace or the standard library path.

## More Steps to modernize

* Describe steps necessary to cmake and test with clang. 
* Look into llvm, Docker, Openshift, K8's, pods, Jenkins, Ansible, Kafka, confluent build, or whatever micro-service solution to show knowledge of these technologies. 
* Look at docker hub for other images I have for c_test.