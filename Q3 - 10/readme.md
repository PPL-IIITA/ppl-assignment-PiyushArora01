# IPPL Assignment
## Object Oriented Programming  
### Piyush Arora - IIT2015071

### Contents
* [Build Details](#build-details)
* [Testing Instructions](#testing-instructions)
* [Documentation and Class Diagrams](#documentation-and-class-diagrams)
* [Tools Used](#tools-used) 

## Build Details

### Language:

```
 C++
```

### Platform:

```
 VS Code Version 1.11.1
```

### Operating System:

```
 Windows 10 Insider Editor v1703 OS Build 15063.13
```

## Testing instructions

* Generate random set (Boys, Girls, Gifts):
```
    g++ GenerateBG.cpp && ./a.out
```

* Question 3:
``` 
    g++ Q03.cpp && ./a.out
```

* Question 4:
``` 
    g++ Q04.cpp && ./a.out
```

* Question 5:
``` 
    g++ Q05.cpp && ./a.out
```
>**NOTE**: For Q5, first run GenerateBG since couples have to be reset; 

* Question 6:
``` 
    g++ Q06.cpp && ./a.out
```
* Question 7:
``` 
    g++ Q07.cpp && ./a.out
```
* Question 8:
``` 
    g++ Q08.cpp && ./a.out
```
>**NOTE**: For Q8, first run GenerateBG since couples have to be reset and run Q03 first to make couples since if you run if after other questions and gifts may already be generated and have taken = 1, some data may be spoilt and may cause bugs.
    PS: just a precautionary step


* All gift exchange events will be logged in `CSV/GiftExchangeLog.csv`
* Utility functions are present in `QxUtility.cpp (x = 3 to 8)`
* .csv files are present in `CSV/`, and names used are present in `Names/`

## Documentation and Class Diagrams

### Documentation
* Documentation is available `documentation/html/index.html`

### Class Diagrams

* All diagrams are already included in html documentation 
* Class diagram is separately present in `ClassDiagram.png`

## Tools Used

* [doxygen](http://www.stack.nl/~dimitri/doxygen/)   :  Generates automatic documentation
* [Enterprise Architect](http://www.sparxsystems.com/products/ea/)  :  Generates class diagram 
