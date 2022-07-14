# Unique Code Generator 
Given a set of IDs we can generate a set of specially crafted PNG image files that encode the IDs with checksum validation.

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
Running the command above should build the executable as well as  pull down the [Google Test Framework ](https://github.com/google/googletest) is used for testing.
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./UCG
```
I have placed the generated output png files from my runs in 'Resources/results'/

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./unit_tests
```
