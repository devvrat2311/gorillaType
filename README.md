## **GorillaType**

### Description

_A typing test / game written in C, compiles and runs in the terminal._

I have taken huge inspiration from [Monkeytype](https://www.monkeytype.com) , and the game plan is to replicate it on the console(to some extent).

### Functionality (current)

- [x] Typing mechanics(Coloured)
- [x] String matching
- [x] Basic ui to navigate the program.
- [x] Timer to score the user and analyse the results(wpm).
- [x] Make and use a corpus of english words which will be the building blocks of the test string.
- [x] Larger Corpus (310 words)

### Functionality (to be added)

- [ ] Record a users statistics in some file and present last 5 scores along with average statistics and performance analysis for that round

## Build instructions

### **_Linux_**

1. Clone the repository

```bash
git clone https://github.com/devvrat2311/gorillaType.git
cd gorillaType
```

2. For this step _make_ sure you have the "make" utility installed on your system.(pun intended?)

```bash
make
```

3. Run the executable just created to get into the program.

```bash
./gorillaType
```

### **_Windows_**(current version doesn't support windows, PRs to make windows compatibility possible are much welcome, winMain.c has the workarounds needed to make linux library to windows library transition)

1. Install the make utility for windows

To use the "make" utility which is native to GNU, you can take one of the following steps,

i. install [chocolaty](https://chocolatey.org/install) and run,

```bash
choco install make
```

This method should work in most cases.

ii. use the `winget` command (window 10 and 11),

run the command

```bash
winget install ezwinports.make
```

in the command line or powershell to quickly install it,
restart the command line or powershell, then you can use the command make.

Note: If this does not work for your system, try adding `C:\Program Files (x86)\GnuWin32\bin` to the windows PATH environment variable.

By the end of this step you can hopefully run `make` command on your powershell. You can refer to [this](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows) link to resolve any problems you might have encountered during this step.

2. Clone the repository and run make in the directory

```bash
git clone https://github.com/devvrat2311/gorillaType.git
cd gorillaType
make
```

3. Run the executable by typing

```
  .\bin\run_gorillaType
```

or you can `cd \bin` and then `run_gorillaType`
