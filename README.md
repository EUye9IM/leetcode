# leetcode

LeetCode 解题记录，支持 C++20 / Go / Rust 多语言实现。

## 依赖

- [xmake](https://xmake.io) (构建系统)
- 语言工具链 (按需安装):
  - clang++ (推荐) 或 gcc — C++
  - go — Go
  - rustc / cargo — Rust
- doctest (仅 C++，由 xmake 自动下载，无需手动安装)

## 运行测试

```bash
# 运行全部题目测试
xmake test

# 运行指定语言的指定题目
xmake run valid-parentheses-cpp
xmake run valid-parentheses-go
xmake run valid-parentheses-rs
```

## LSP 支持

xmake 管理的依赖（如 doctest）不在系统 include 路径中，LSP（clangd）会报缺失头文件。生成编译数据库来解决：

```bash
xmake project -k compile_commands
```

这将生成 `compile_commands.json`，clangd 读取后即可正确解析所有头文件。

## 目录结构

```
problem-name/
  main.cpp   -- C++20 + doctest 测试
  main.go    -- Go + 手写断言
  main.rs    -- Rust + 手写断言
```

同一目录可同时存在多种语言实现，`xmake.lua` 自动扫描 `main.{cpp,go,rs}` 注册为构建目标。

## 新增题目

```bash
bash new_promblems.sh <problem-name>        # C++ (默认)
bash new_promblems.sh <problem-name> go     # Go
bash new_promblems.sh <problem-name> rs     # Rust
```

无需修改 `xmake.lua`。
