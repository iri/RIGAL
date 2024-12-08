# RIGAL

RIGAL is a specialized programming language created for writing compilers. It was originally developed by M. Auguston and V. Engelson at the University of Latvia (USSR) during 1987-1993.

This repository includes RIGAL to C compiler, examples, detailed language description and user guide.

## Repository Structure

- **`origin` branch**: Contains the original release of the
  software, preserved in its unmodified form.
- **`main` branch**: Contains modifications to the original
  release.

## Documentation

### Language description
[\<RIGAL\>/docs/RIGAL_language_description.html](docs/RIGAL_language_description.pdf)

### Programmers guide
[\<RIGAL\>/docs/RIGAL_programmers_guide.html](docs/RIGAL_programmers_guide.pdf)

### Manual page
[\<RIGAL\>/docs/man/rigal_manpage.html](docs/rigal_manpage.pdf)

## Prerequisites 

`sudo apt-get install build-essential gcc-multilib csh`


## Build

This will build RIGAL executables and put them into bin/ directory
```bash
cd src
make
```

After build the folder with executables (bin/) contains the following executables:

rc - checks and compiles RIGAL file 

ic - interprets intermediate RIGAL code 

v - viewer for RIGAL data saved in file 

rig_crf - RIGAL cross -referencer 

rig_lint - RIGAL Lint (data type checker) 


## Install

To install you may add the folder with executables (bin/) to the $PATH environment variable
```bash
export PATH="<RIGAL>/bin:$PATH
```

