# 2026-10-11：GitHub Issues 与 PR 关联

## 今日目标

- 理解 Issue 的用途
- 学会创建、分配和标记 Issue
- 学会在 Commit 和 PR 中引用 Issue
- 使用 `Closes #编号` 在 PR 合并后自动关闭 Issue

## Issue 是什么

Issue 是项目中的任务、问题、需求或讨论记录。它和 Pull Request 使用同一套编号。

```text
Issue    = 记录要做什么、为什么做
Branch   = 实际进行修改的时间线
Commit   = 一次代码或文档修改
PR       = 请求把分支合并到目标分支
Merge    = 真正执行合并
```

## 本次 Issue

- Issue #4：学习 GitHub Issues 与 PR 关联流程
- 状态：Open
- 目标：完成 Issue 学习笔记，并通过 PR 合并后自动关闭

## Issue 常用功能

- `Assignees`：指派负责人
- `Labels`：添加标签，例如 `documentation`、`enhancement`
- `Milestone`：归入某个阶段目标
- 评论区：讨论任务
- `#编号`：链接 Issue 或 PR
- `@用户名`：提醒相关用户

## 关联与自动关闭

在 Commit 说明或 PR 描述中写：

```text
Refs #4
```

表示引用 Issue #4，但不会自动关闭。

在 PR 描述中写：

```text
Closes #4
```

当 PR 合并到默认分支后，GitHub 会自动关闭 Issue #4。

其他常用关键字：

```text
Closes #4
Fixes #4
Resolves #4
```

## 本次工作流程

```text
创建 Issue #4
-> 创建功能分支 docs/github-issues
-> 新增 Issue 学习笔记
-> Commit 中引用 #4
-> Push 功能分支
-> 创建 PR，并在描述中写 Closes #4
-> 检查 Commits 和 Files changed
-> Merge PR
-> 确认 Issue #4 自动变为 Closed
```

## 本次 Commit

```text
docs: add GitHub Issues notes (#4)
```

## 关键理解

- Issue 和 PR 共享编号空间。
- Issue 描述任务，PR 提供解决方案。
- Commit 可以引用 Issue 编号。
- PR 使用 `Closes #编号` 后，合并会关闭对应 Issue。
- Issue 关闭不代表必须删除，历史记录仍然保留。