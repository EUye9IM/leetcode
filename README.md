# leetcode

LeetCode 解题记录，使用 C++20 实现。

## 依赖

- [xmake](https://xmake.io) (构建系统)
- clang++ (推荐) 或 gcc (备选)
- doctest (由 xmake 自动下载，无需手动安装)

## 运行测试

```bash
# 运行全部题目测试
xmake test

# 运行指定题目测试
xmake run valid-parentheses
```

## LSP 支持

xmake 管理的依赖（如 doctest）不在系统 include 路径中，LSP（clangd）会报缺失头文件。生成编译数据库来解决：

```bash
xmake project -k compile_commands
```

这将生成 `compile_commands.json`，clangd 读取后即可正确解析所有头文件。

## 新增题目

```bash
mkdir <problem-name>
touch <problem-name>/solution.cpp   # Solution 类实现
touch <problem-name>/test.cpp       # doctest 测试用例
```

`xmake.lua` 会自动扫描 `*/test.cpp` 注册为测试目标，无需修改构建配置。
