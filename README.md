# C Development Environment Generator

This tool generates a directory and file structure specifically designed for C development. It creates the required directories, makefile, and helper files for a smooth development experience.

## Usage

To use this tool, compile the provided C code and run the generated executable with the desired project names as arguments:

```console
foo@bar:~$ make mkcodedir
foo@bar:~$ ./mkcodedir project1 project2 project3
```

This will create directories for `project1`, `project2`, and `project3`, each with the following structure:

```bash
project_name/
  ├── code/
  │   ├── libs/
  │   │   ├── helpers.h
  │   │   └── helpers.c
  │   └── main.c
  └── output/
```

It will also generate a makefile with 2 basic scripts for compiling the C code, including the helper files, and cleaning up the object files.

- The first script just generates the executable with debug information.
- The second one generates the executable and moves it to the output directory

## License

This code is open source and available under the MIT License.
