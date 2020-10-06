# Program development template

* Build system: cmake
* Tests: gtest
* Code style check: cpplint
* Continuous integration: travis-ci


## Merging an upstream repository into your fork (master branch)
```
 git checkout master
 git pull https://github.com/UsovaMA/Development-Template.git master
```
## Update working branch
```
 git checkout <your branch>
 git rebase master
```
## Build project with cmake
cmake -DCMAKE_CXX_FLAGS=/D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING -G "Visual Studio 15 2017" <path to sourse files>
 
## Table with results
https://docs.google.com/spreadsheets/d/13DTrH4Rbk5AZt6FhW_V7x2uIs4Mv9kiON-GnYClocWk/edit?usp=sharing
