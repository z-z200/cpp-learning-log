# 学习进度

## 2026-10-06：Git 与 GitHub 入门

- 理解 Git 与 GitHub 的区别
- 配置 Git 提交身份
- 初始化本地仓库并连接 GitHub
- 完成 `add`、`commit`、`push` 标准流程
- 理解工作区、暂存区、本地仓库和远程仓库
- 相关提交：`adae83f`、`96d2d9b`、`b707c52`
- 学习日志：[2026-10-06：Git 与 GitHub 入门](notes/2026-10-06-day01-git-github.md)

## 2026-10-07：Branch 与 Pull Request

- 理解 Branch 是指向提交的时间线
- 创建并推送 `learn/branch-and-pr`
- 新增第二天学习笔记
- 功能分支提交：`5e5b97e`
- 创建并合并 PR #1
- 合并提交：`8ac6b6d`
- 删除本地和远程功能分支
- 同步本地 `main` 与 `origin/main`
- 理解本地合并与远程 PR 的区别
- 学习日志：[2026-10-07：分支与 Pull Request](notes/2026-10-07-day02-branch-pr.md)

## 2026-10-08：cli-todo 第一版

- 创建 `feature/cli-todo-v01` 功能分支
- 完成添加、查看和退出的 C++ 命令行程序
- 提交：`ccd3ef8`
- 创建并合并 PR #2
- 合并提交：`fe33486`
- 学习 `vector`、`getline`、`push_back` 和菜单循环
- 处理 GitHub 连接超时和 Steam++ 网络加速问题
- 学习日志：[2026-10-08：cli-todo 第一版](notes/2026-10-08-day03-cli-todo.md)

## 2026-10-09：struct、完成状态和删除

- 使用 `struct Todo` 保存标题和完成状态
- 将容器升级为 `std::vector<Todo>`
- 支持标记完成和按编号删除
- 学习成员访问、下标转换和 `erase`
- 提交：`540c383`
- 创建并合并 PR #3
- 合并提交：`72cba0f`
- 学习日志：[2026-10-09：struct、完成状态和删除](notes/2026-10-09-day04-struct-todo-status.md)

## 2026-10-10：递归与全排列

- 检查递归学习中的思路和实现问题
- 分析 LeetCode 46 全排列
- 找出递归出口、`used/flag` 标记、选择与回退结构
- 生成参考代码并逐步解释
- 仍需独立复述回退过程并关闭参考代码重写
- 学习日志：[2026-10-10：递归与全排列](notes/2026-10-10-day05-recursion-permutations.md)

## 下一次学习

- 用自己的话解释 `pop_back()` 和撤销标记的作用
- 手动追踪 `[1,2,3]` 的前两条全排列
- 关闭参考代码，独立写出全排列递归函数
- 再完成一道简单的递归或回溯题
