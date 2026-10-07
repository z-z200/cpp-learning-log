# 2026-10-07：分支与 Pull Request

## 今日目标

- 理解 Branch 是一条独立的提交时间线
- 学会从 `main` 创建功能分支
- 在功能分支上提交并推送修改
- 创建第一个 Pull Request
- 完成合并、同步本地 `main` 和删除功能分支

## 今日完成

- 创建功能分支 `learn/branch-and-pr`
- 新增学习笔记 `notes/2026-10-07-day02-branch-pr.md`
- 创建提交 `5e5b97e docs: add day 02 branch and PR notes`
- 将功能分支推送到 GitHub
- 创建并合并 PR #1
- 使用 `Create a merge commit` 完成远程合并
- 删除 GitHub 上的功能分支
- 在本地切换到 `main` 后执行 `git pull --prune`
- 删除本地功能分支
- 确认本地 `main` 和 `origin/main` 保持同步

## Branch（分支）

Branch 不是文件或文件夹，而是指向某个 Commit 的命名时间线。

创建分支时不会复制整个项目。新分支一开始与 `main` 指向同一个 Commit，产生新的提交后才会与 `main` 分开：

```text
             main
               |
A --- B --- C  |
          \    |
           D --+
               |
      learn/branch-and-pr
```

创建并切换分支：

```powershell
git switch -c learn/branch-and-pr
```

查看本地分支：

```powershell
git branch
```

## Pull Request（PR）

PR 是 GitHub 上的合并申请，用于请求把源分支合并到目标分支：

```text
learn/branch-and-pr  ->  main
```

PR 页面可以查看：

- `Conversation`：讨论和操作记录
- `Commits`：包含的提交
- `Files changed`：具体文件差异
- `Checks`：自动测试和检查结果
- `Merge pull request`：确认合并
- `Close pull request`：关闭但不合并

## 本地合并与远程 PR 的区别

本地可以直接合并，不是必须经过 GitHub：

```powershell
git switch main
git merge learn/branch-and-pr
git push origin main
```

远程 PR 流程：

```text
功能分支
-> git push
-> GitHub 功能分支
-> 创建 PR
-> 检查 Commit 和文件差异
-> Merge pull request
-> GitHub main
-> git pull 同步本地 main
```

PR 的主要价值：

- 合并前检查和讨论
- 记录修改范围
- 运行自动测试
- 支持代码审查
- 为团队协作保留完整历史

## 实际执行的命令

创建分支：

```powershell
git switch -c learn/branch-and-pr
git branch
git status
```

暂存和提交：

```powershell
git add .\notes\2026-10-07-day02-branch-pr.md
git commit -m "docs: add day 02 branch and PR notes"
git status
```

推送功能分支：

```powershell
git push -u origin learn/branch-and-pr
```

合并 PR 后同步本地：

```powershell
git switch main
git pull --prune
git branch -d learn/branch-and-pr
git branch -a
git status
```

## 最终状态

- PR #1 已合并
- 合并提交：`8ac6b6d Merge pull request #1 from z-z200/learn/branch-and-pr`
- 功能分支提交：`5e5b97e docs: add day 02 branch and PR notes`
- 本地 `main` 与 `origin/main` 同步
- 本地和远程功能分支均已删除
- 工作区状态干净

## 关键理解

- Git 是本地版本控制工具，GitHub 是远程协作平台。
- Branch 是指向提交的指针，不是复制出来的文件夹。
- 开发功能时通常从最新的 `main` 创建分支。
- `git push -u origin <branch>` 上传功能分支并建立跟踪关系。
- PR 是 GitHub 上的合并申请，不是 Git 命令。
- 本地合并和远程 PR 都是有效方式，PR 更适合协作和正式项目。
- 合并后需要把本地 `main` 从 GitHub 更新下来。
- 删除已经合并的功能分支不会丢失提交。