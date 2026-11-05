# C Programming Language Exercises & Solutions
- **Student ID**: 20268500
- **Name**: Dovydas Udalcovas (도비다스 우달초바스)
- **Department**: Dept. of Game Dev. / International College, Dongseo University
- **Environment**: Windows 11, Visual Studio 2022 / MSVC Compiler

---

## 📂 Chapters Overview
- [x] **ch1**: Tutorial Introduction (Variables, for loops, symbolic constants, functions)
- [x] **ch2**: Types, Operators & Expressions (Data types, bitwise operators, type conversion)
- [x] **ch3**: Control Flow (if-else, switch, loops, break & continue)
- [x] **ch4**: Functions & Program Structure (External variables, scope rules, header files)
- [x] **ch5**: Pointers & Arrays (Pointer arithmetic, swap, line sort, CLI arguments)

File names are `<order>.ex-<exercise>_<name>.c`: the order in the chapter, then,
for textbook exercises, the exercise number (e.g. `8.ex-1.13_...` = Exercise 1-13).
Files that are not textbook exercises use `<order>.ex_<name>.c`.

---

### ch1 – Tutorial Introduction
| File | Section, exercise | Purpose |
|------|--------------------|--------------|
| `1.ex-1.1_hello_world.c` | 1.1, Ex 1-1 | Prints "hello, world" |
| `2.ex-1.3_fahrenheit_to_celsius.c` | 1.2, Ex 1-3 | Fahrenheit ~> Celsius |
| `3.ex-1.4_celsius_to_fahrenheit.c` | 1.2, Ex 1-4 | Celsius ~> Fahrenheit |
| `4.ex-1.5_reverse_temperature_table.c` | 1.3–1.4, Ex 1-5 | Descending temperature table using `for` |
| `5.ex_word_count.c` | 1.5.4 | Line, word, and character counting |
| `6.ex-1.8_count_blanks_tabs_newlines.c` | 1.5.3, Ex 1-8 | Blank, tab and newline counting |
| `7.ex_count_digits_whitespace_array.c` | 1.6 | Counts digits, white space, and other symbol using arrays |
| `8.ex-1.13_word_length_histogram.c` | 1.6, Ex 1-13 | Horizontal and vertical histograms of word lengths |
| `9.ex_power_function.c` | 1.7–1.8 | Power function |
| `10.ex-1.15_temperature_conversion_function.c` | 1.7, Ex 1-15 | Temperature table using a function |
| `11.ex_longest_line.c` | 1.9 | Print longest input line |
| `12.ex-1.17_print_lines_over_80_chars.c` | 1.9, Ex 1-17 | Print lines over 80 characters |
| `13.ex-1.19_reverse_lines.c` | 1.9, Ex 1-19 | reverse input line (excl. newline) |
| `14.ex-1.20_detab.c` | 1.9, Ex 1-20 | Replace tab with `_` (defined symbol) up to the next tab stop |
| `15.ex_longest_line_extern.c` | 1.10 | Longest line using external variable |

---

### ch2 – Types, Operators & Expressions
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `1.ex-2.1_type_ranges.c` | 2.2, Ex 2-1 | Ranges of common variable types |
| `2.ex_leap_year.c` | 2.5–2.6 | Leap year, using `%`, `&&`, `\|\|` |
| `3.ex-2.3_htoi.c` | 2.7, Ex 2-3 | Hex string to integer |
| `4.ex-2.4_squeeze.c` | 2.8, Ex 2-4 | Squeeze function |
| `5.ex-2.5_any.c` | 2.8, Ex 2-5 | Get first position of any char of s2 in s1 |
| `6.ex-2.6_2.7_2.8_bit_operations.c` | 2.9, Ex 2-6/2-7/2-8 | `setbits`, `invert`, `rightrot` |

---

### ch3 – Control Flow
| File | Section / Exercise | What it does |
|------|--------------------|--------------|
| `1.ex_binary_search.c` | 3.3 | Binary search |
| `2.ex_count_digits_switch.c` | 3.4 | Digit & white space counting using `switch` |
| `3.ex-3.2_escape_unescape.c` | 3.4, Ex 3-2 | `escape` / `unescape` for `\n` and `\t` |
| `4.ex_itoa_do_while.c` | 3.6 | `itoa(n, s)` using do-while and `reverse` |
| `5.ex_trim_break_continue.c` | 3.7 | `trim` with `break`, using `continue` |
| `6.ex_goto_nested_loops.c` | 3.8 | `goto` to leave nested loops |

---

## 🛠️ How to Compile & Run
*This guide assumes you have Visual Studio 2022 installed.*

1. Set up MSVC in your cmd window (skip this if you have MSVC set up in your PATH):
```cmd
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
```

2. Build the program with the compiler:
```cmd
cl ch1/1.ex-1.1_hello_world.c
```
3. Run it
```cmd
1.ex-1.1_hello_world.exe
```