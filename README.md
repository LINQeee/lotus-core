# Lotus core

Native runtime library for the [Lotus compiler](https://github.com/LINQeee/lotus).
| Path | Purpose |
| --- | --- |
| `lotus.h` | Native ABI: values, strings and registration macros |
| `library.c` | Functions registered with the language |
| `src/` | I/O, conversions and random numbers |
| `internal/` | Compiler runtime functions prefixed with `_` |
| `utils/` | C helpers for library development; not registered with the language |

`utils/string_utils.h` provides `lotusStringCreate` for creating owned strings inside the library.
Its symbol is hidden from the shared library export table. `_` functions remain available to the JIT.

Requires CMake 4.2+ and a C11 compiler.

```sh
cmake -S . -B build
cmake --build build --target lotus_core
```

The library is written to `../libs/`, matching the compiler's runtime loader layout.
In the compiler repository, this repository is mounted at `lotus-core/` as a Git submodule.
Run `lotus-test` from the compiler checkout to test the runtime together with the compiler.
