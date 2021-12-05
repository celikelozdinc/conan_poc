# INSTRUCTIONS

+  pip3 install -v conan

## search a package
+  conan search #lists packages in local cache or local repository
+ conan search gtest -r=all

## manual installation from command line
+ conan install libpcap/1.10.0@

## Automatic installation via conanfile.txt
Installing dependencies using conanfile.txt method is very simple, execute:  <br>
```bash
conan install <path> 
```
from build directory. <path> should point to the location of the conanfile.txt file. <br>

```
cd build ; conan install ..
```



# REFERENCES
+ [Introduction](https://kubasejdak.com/introduction-to-conan-package-manager)
+ [bincrafters github](https://bincrafters.github.io/)
