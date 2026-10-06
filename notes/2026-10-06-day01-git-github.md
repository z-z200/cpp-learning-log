# 2026-10-06：Git 与 GitHub 入门

## 今日目标

- 认识 Git 与 GitHub 的区别
- 配置 Git 提交身份
- 建立第一个本地 Git 仓库
- 完成 `add`、`commit`、`push` 完整流程
- 学会使用 `git status` 和 `git log` 查看状态与历史

## 今日完成

- 确认 Git 已安装：`git 2.55.0`
- 配置提交身份：
  - `user.name = z-z200`
  - `user.email = z-z200@users.noreply.github.com`
- 创建本地仓库：`cpp-learning-log`
- 建立 GitHub 远程仓库并连接为 `origin`
- 完成第一次提交：`adae83f chore: initialize C++ learning log`
- 修改 README，完成第二次提交：`96d2d9b docs: record first GitHub workflow`
- 将两次提交推送到 GitHub
- 确认本地 `main` 与 `origin/main` 保持同步

## 核心概念

### Git 与 GitHub

- Git：安装在电脑上的版本管理工具，可以离线记录修改。
- GitHub：存放 Git 仓库的网站，用于备份、展示与协作。
- 本地仓库：位于电脑上的项目及完整提交历史。
- 远程仓库：GitHub 等服务器上的仓库副本。

### Repository（仓库）

被 Git 管理的项目。执行 `git init` 后，项目目录中会生成隐藏的 `.git` 目录，提交历史保存在其中。

### Commit（提交）

一次正式保存的代码存档。每次提交包含：

- 文件内容快照
- 作者与时间
- 提交说明
- 对上一次提交的引用

### 工作区、暂存区与本地仓库

```text
工作区                 暂存区                 本地仓库               GitHub
正在编辑的文件  --add-->  下次提交清单  --commit-->  提交历史  --push-->  远程仓库
```

- 工作区：当前实际看到和编辑的文件。
- 暂存区：下一次 Commit 的待提交清单，也叫 Index 或 Staging Area。
- 本地仓库：已经完成 Commit 的提交历史。
- 远程仓库：位于 GitHub 上的仓库。

文件进入暂存区时不会移动位置，只是 Git 把它的当前版本登记到下一次提交中。

### Branch（分支）

一条独立的开发时间线。当前主分支名称为 `main`。

### Remote（远程仓库）

本地仓库连接的远程地址。当前配置为：

```text
origin  https://github.com/z-z200/cpp-learning-log.git
```

- `origin`：远程仓库的常用简称。
- `fetch`：从 GitHub 获取更新。
- `push`：向 GitHub 上传提交。

## 常用命令

### 检查 Git 版本

```powershell
git --version
```

### 配置提交身份

```powershell
git config --global user.name "z-z200"
git config --global user.email "z-z200@users.noreply.github.com"
```

### 初始化本地仓库

```powershell
git init
```

### 查看状态

```powershell
git status
```

### 将修改放入暂存区

```powershell
git add .
```

或只暂存一个文件：

```powershell
git add README.md
```

### 创建本地提交

```powershell
git commit -m "docs: record first GitHub workflow"
```

### 连接 GitHub 远程仓库

```powershell
git remote add origin https://github.com/z-z200/cpp-learning-log.git
```

### 查看远程仓库地址

```powershell
git remote -v
```

### 上传本地提交

```powershell
git push
```

第一次推送并建立跟踪关系：

```powershell
git push -u origin main
```

### 查看提交历史

```powershell
git log --oneline --decorate
```

## 标准工作流程

以后每次修改项目时重复以下步骤：

```powershell
git status
git add .
git commit -m "说明这次修改了什么"
git push
git status
```

## 状态含义回顾

```text
Changes not staged for commit
```

文件已经修改，但还没有进入暂存区。

```text
Changes to be committed
```

修改已经进入暂存区，准备提交。

```text
nothing to commit, working tree clean
```

工作区没有未提交的修改。

```text
Your branch is ahead of 'origin/main' by 1 commit.
```

本地提交比 GitHub 多一个，需要执行 `git push`。

```text
Your branch is up to date with 'origin/main'.
```

本地和 GitHub 的提交历史已经同步。

## 安全注意事项

- 不要向任何人发送 GitHub 密码、验证码或访问 Token。
- 不要提交 `.env`、API Key、密码和私钥。
- 执行 `git restore <file>` 会放弃文件中的未提交修改，必须谨慎。
- 执行 `git restore --staged <file>` 只会取消暂存，文件修改仍然保留。

## 今日验收问题

1. Git 与 GitHub 有什么区别？
2. `git add`、`git commit`、`git push` 分别做什么？
3. 为什么 README 修改后，`git status` 显示 `modified`？
4. 为什么提交后状态变成 `ahead by 1 commit`？
5. `working tree clean` 表示什么？

## 下次学习

- 创建新分支 `git switch -c`
- 在分支上修改文件并提交
- 将分支推送到 GitHub
- 创建第一个 Pull Request（PR）
- 合并分支后同步本地 `main`
