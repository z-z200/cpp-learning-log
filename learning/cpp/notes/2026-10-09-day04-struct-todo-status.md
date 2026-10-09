# 2026-10-09：struct、完成状态和删除

## 今日目标

- 学会使用 `struct` 组合相关数据
- 把 `vector<std::string>` 升级为 `vector<Todo>`
- 为每条待办保存完成状态
- 增加标记完成和删除功能
- 完整走一遍功能分支和 PR 流程

## 今日完成

- 从 `main` 创建功能分支 `feature/cli-todo-v02`
- 在 `src/cli_todo.cpp` 中新增 `Todo` 结构体
- 支持标记待办完成
- 支持按编号删除待办
- 编译并完成手动测试
- 提交 `540c383 feat: add todo completion and deletion`
- 创建并合并 PR #3
- 合并提交：`72cba0f Merge pull request #3`
- 将合并结果同步到本地 `main`

## struct

`struct` 把属于同一个对象的多个数据组合在一起：

```cpp
struct Todo {
    std::string title;
    bool completed = false;
};
```

一条待办包含：

- `title`：待办内容
- `completed`：是否已经完成

容器从保存字符串：

```cpp
std::vector<std::string> todos;
```

升级为保存待办对象：

```cpp
std::vector<Todo> todos;
```

访问成员：

```cpp
todos[i].title
todos[i].completed
```

其中 `.` 表示访问对象的成员。

## 完成状态

列表状态显示为：

```text
[ ] 未完成
[x] 已完成
```

标记完成：

```cpp
todos[position].completed = true;
```

## 编号和下标转换

用户看到的待办编号从 `1` 开始：

```text
第 1 条、第 2 条、第 3 条
```

C++ 容器下标从 `0` 开始：

```text
todos[0]、todos[1]、todos[2]
```

因此用户输入编号后需要：

```cpp
const std::size_t position = static_cast<std::size_t>(index - 1);
```

## 删除元素

```cpp
todos.erase(todos.begin() + static_cast<std::ptrdiff_t>(position));
```

`erase` 删除指定位置，后面的元素会自动向前移动。

删除前先检查编号是否合法：

```cpp
if (index < 1 || index > static_cast<int>(todos.size())) {
    std::cout << "Invalid todo number.\n";
}
```

## 验证结果

已手动测试：

1. 添加两条待办
2. 查看后显示两个 `[ ]`
3. 标记第一条完成后显示 `[x]`
4. 删除第二条
5. 列表只剩第一条
6. 输入 `0` 正常退出

程序运行符合预期。

## 本次命令

创建功能分支：

```powershell
git switch main
git pull
git switch -c feature/cli-todo-v02
```

编译运行：

```powershell
g++ .\src\cli_todo.cpp -o .\build\cli_todo.exe
.\build\cli_todo.exe
```

提交推送：

```powershell
git add .\src\cli_todo.cpp
git commit -m "feat: add todo completion and deletion"
git push -u origin feature/cli-todo-v02
```

合并后同步：

```powershell
git switch main
git pull --prune
git branch -d feature/cli-todo-v02
```

## 遇到的问题

GitHub 拉取再次被本机 `127.0.0.1:443` 代理拦截。确认网络加速器状态后，重新执行 `git fetch origin --prune` 并成功取得 PR #3 的合并结果。

## 当前限制

- 数据仍然只保存在内存中
- 程序退出后待办事项会丢失
- 所有业务逻辑仍集中在 `main`
- 没有自动测试和 CMake

## 下次学习

- 使用函数拆分添加、显示、完成和删除逻辑
- 学习函数参数中的值传递和引用传递
- 学习 `const` 引用
- 让 `main` 只负责菜单和调度
