# DMF — Domain Modelling Framework

Bachelor thesis by Alexander Brand. A DSL (`.dmf` files) → code generation for Java, TypeScript, and SQL schemas, with LSP support.

## Repo structure (monorepo)

| Module | Dir | Language | Entrypoint |
|--------|-----|----------|------------|
| Grammar | `grammar/` | tree-sitter DSL (JS) + C parser + Go bindings | `grammar/grammar.js` |
| Semantic | `semantic/` | Go | `semantic/api.go` — `ParseNewFile` / `ParseEdit` |
| Generator | `generator/` | Go | `generator/main.go` — CLI `--basePath --modelFile --mode` |
| LSP | `lsp/` | Go | `lsp/main.go` — `--std` for stdio, `--port` for TCP |
| Relay | `relay/` | Go | `relay/main.go` — TCP→stdio bridge |
| VS Code plugin | `vscode-plugin/` | TypeScript | `client/src/extension.ts` — ships LSP binary |
| IntelliJ plugin | `intellijPlugin/` | Java/Gradle | LSP4IJ, requires IntelliJ 2024.1 |
| Maven plugin | `Maven-Plugin/` | Java/Maven | `dmf-generator-plugin` |
| Example | `BeispielProjekt/` | DMF + Java + TS + Maven | `Modell/domain.dmf` imports `Modell/base.dmf` |

All five Go modules are wired in `go.work`.

## Build & test commands

```sh
# Go workspace — build/test all Go modules at once
go build ./...
go test ./...

# Grammar regeneration (run after editing grammar.js)
cd grammar && tree-sitter generate

# Generator CLI usage
go run ./generator/... --mode java --modelFile ./Modell/domain.dmf --basePath ./gen

# LSP server (stdio mode)
go run ./lsp/... --std

# Full release build (cross-compiles LSP/generator/relay for Linux + Windows via mingw)
./fullBuild.sh
```

## Critical quirks

- **CGo dependency**: tree-sitter Go bindings use CGo. The generated C parser `grammar/src/parser.c` is **checked in** — edit `grammar.js`, run `tree-sitter generate`, then rebuild. Go tests require a C compiler (`gcc`) for the CGo bridge.
- **Cross-compilation requires mingw**: `fullBuild.sh` uses `/usr/bin/x86_64-w64-mingw32-gcc` for Windows builds.
- **Generator modes**: `java`, `javaDelegates`, `ts`, `tsDelegates`, `database`. Delegates mode skips existing files.
- **DSL syntax**: files start with `dmf 1.0.0` then `model "name" version x.y.z`, imports use `import pkg.name from "./relative.dmf"`, package types are `entity`, `struct`, `interface`, `enum`.
- **Exporting config**: `config/maven.xml` adds `de.alex-brand.dmf` plugin group — needed for Maven plugin consumers.
- **No CI**: no `.github/` directory.
- **Semantic rules doc**: `semantic/sem_rules.md` (German) documents validation rules — some marked TODO, cross-check with actual code before relying on them.
