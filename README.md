# Unique Code Generator 

This software was tested on Ubuntu 18.04.6 LTS
## Dependencies for Running Locally
    * cmake >=3.5
    * sudo apt-get install libpng-dev

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./UCG
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./unit_tests
```
