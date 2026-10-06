# Git 基础笔记

## 三个核心概念

- 仓库（Repository）：被 Git 管理的项目。
- 提交（Commit）：一次代码存档。
- 远程仓库（Remote）：位于 GitHub 等服务器上的仓库。

## 第一次提交流程

```powershell
git status
git add .
git commit -m "说明这次修改了什么"
```

## 查看历史

```powershell
git log --oneline
```