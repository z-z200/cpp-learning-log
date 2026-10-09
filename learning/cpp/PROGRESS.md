# C++ 项目学习进度

## 2026-10-08：cli-todo 第一版

- 创建第一个 C++ 命令行待办程序
- 学习 `vector`、`getline`、`push_back` 和菜单循环
- 提交：`ccd3ef8`
- 创建并合并 PR #2
- 学习日志：[cli-todo 第一版](notes/2026-10-08-day03-cli-todo.md)

## 2026-10-09：struct、完成状态和删除

- 使用 `struct Todo` 保存标题和完成状态
- 将容器升级为 `std::vector<Todo>`
- 支持标记完成和按编号删除
- 学习成员访问、下标转换和 `erase`
- 提交：`540c383`
- 创建并合并 PR #3
- 学习日志：[struct、完成状态和删除](notes/2026-10-09-day04-struct-todo-status.md)

## 当前状态

- 程序功能可以正常编译和手动测试
- 数据只保存在内存中
- 业务逻辑仍集中在 `main`
- 下一次可以为函数拆分或文件持久化