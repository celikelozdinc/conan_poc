# NOTES
+ Conan is distributed as a Python package
+ Conan packages(`=recipes`) : <br>

    - can fetch source code from remote sources such as Github, Gitlab, Sourceforge, FTP or *conan server* in local network

# INSTRUCTIONS

+  pip3 install -v conan
+  pip3 install -v conan --upgrade

## search a package
+  conan search &rarr; lists packages in local cache or local repository
+  conan search gtest -r=all

## common commands
+ conan profile list
+ conan remote list
+ conan config &rarr; Manages configuration, installs config files
+ conan install &rarr; Install the _requirements_ specified in the conanfile(py or txt)

# INSTALLATION
## Manual installation from command line
+ conan install libpcap/1.10.0@

## Automatic installation via conanfile.txt
Installing dependencies using conanfile.txt method is very simple, execute:  <br>
```bash
conan install <path> 
```
from build directory. `<path>` should point to the location of the conanfile.txt file. <br>

```
cd build
conan profile new default --detect  # Generates default profile detecting GCC and sets old ABI
conan profile update settings.compiler.libcxx=libstdc++11 default  # Sets libcxx to C++11 ABI
conan install ..
cmake ..
```


# REFERENCES
+ [Introduction](https://kubasejdak.com/introduction-to-conan-package-manager)
+ [bincrafters github](https://bincrafters.github.io/)
+ [mocking non-virtual and free functions by Sandor Dargo](https://www.sandordargo.com/blog/2022/03/09/mocking-non-virtual-and-free-functions)

## RUNTIME ERROR while invoking unit tests: munmap_chunk(): invalid pointer 
+ [gtest via conan](https://stackoverflow.com/questions/60874183/how-to-use-gtest-via-conan)
    + [Warning in the Getting Started Docs. ](https://docs.conan.io/en/latest/getting_started.html)
