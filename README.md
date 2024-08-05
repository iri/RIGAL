# RIGAL

RIGAL is a programming language for compiler writing, developed by Mikhail Auguston and Vadim Engelson. RIGAL was designed and implemented in 1987–1988 at the Institute of Mathematics and Computer Science, University of Latvia (Rainis Blvd. 29, Riga, LV-1459, Latvia)

This repository includes RIGAL to C compiler, examples, detailed language description and user guide.

## Documentation

### Language description
[\<RIGAL\>/docs/RIGAL_language_description.html](docs/RIGAL_language_description.html)

### Programmers guide
[\<RIGAL\>/docs/RIGAL_programmers_guide.html](docs/RIGAL_programmers_guide.html)

### Manual page
[\<RIGAL\>/docs/man/rigal_manpage.html](docs/man/rigal_manpage.html)

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

