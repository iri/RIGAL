# RIGAL

Rigal is compiler construction language developed at the University of Latvia, Institute of Mathematics and Computer Science in 1987. The main data structures are atoms, lists and labelled trees. The control structures are based on advanced pattern matching. All phases of compilation, including parsing, optimization and code generation, can be programmed in this language in short and readable form.

This repository includes RIGAL to C compiler, examples, detailed language description and user guide.

## Repository Structure

- **`origin` branch**: Contains the original release of the
  software, preserved in its unmodified form.
- **`main` branch**: Contains modifications to the original
  release.

## Documentation

### Language description
[RIGAL_language_description.html](docs/RIGAL_language_description.pdf)

### Programmers guide
[RIGAL_programmers_guide.html](docs/RIGAL_programmers_guide.pdf)

### Manual page
[rigal_manpage.html](docs/rigal_manpage.pdf)

## Prerequisites 

`sudo apt-get install build-essential gcc-multilib csh`


## Build

This will build RIGAL executables and put them into bin/ directory
```bash
cd src
make
```

After build the folder with executables (bin/) contains the following executables:

`rc` - checks and compiles RIGAL file 

`ic` - interprets intermediate RIGAL code 

`v` - viewer for RIGAL data saved in file 

`rig_lint` - RIGAL Lint (data type checker) 


## Install on Debian/Ubuntu Linux as package

```bash
sudo dpkg -i distr/rigal_4.45.1_amd64.deb
```

## Install (manually, from source)

To install you may compile and add the folder with executables (`bin`) to the `$PATH` environment variable
```bash
cd src
make
export PATH="<rigal-path>/bin:$PATH
```
