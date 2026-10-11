# 2026-10-11：边界检查、未定义行为与子集入门

## 今日目标

- 补全全排列收尾：问题 11 的文字答案、修 `main` 列数、消除 `-Wsign-compare`
- 认识「越界访问 = 未定义行为」这个 C++ 核心概念
- 进入 LeetCode 78 子集

## 完成情况

| 内容 | 结果 |
| --- | --- |
| 问题 11：局部变量返回引用（悬垂引用） | 完成 |
| `operator[]` 越界 = UB、`.at()` 抛异常 | 完成 |
| 「构造反例」验证「碰巧对」的代码 | 完成 |
| 全排列零警告对照版（`-Wall -Wextra`，`[1,2,3,4]` 输出 24 条） | 完成 |
| LeetCode 78 子集 | 只提出问题，未写代码 |

## 关键知识点

1. **悬垂引用（dangling reference）**：局部变量的生命周期到函数返回就结束，返回它的引用会指向一块「已不属于你」的内存。最坑的是它可能碰巧还能打印出正确结果。
2. **`vector::operator[]` 不做边界检查**：越界读/写属于**未定义行为（UB）**——可能读到垃圾值、可能崩溃、每次运行结果都可能不同。写越界（`res[0][1] = 999`）可能悄悄改掉别人的内存，更隐蔽。
3. 要让它**拦住你**，用 `.at()`：`res[0].at(1)` 会抛 `std::out_of_range`。代价是每次访问多一次检查，所以 C++ 默认给快的 `[]`，检查责任交给程序员。
4. **验证「碰巧对」的代码**：不能靠换更大的输入（全排列里答案长度恒等于输入长度，换 `[1,2,3,4]` 也测不出列数问题），要**直接构造反例**——手动塞一个长度不相等的 `res`。
5. 结论：**「程序输出了正确结果」不等于「代码正确」**。

## 全排列零警告对照版

```cpp
#include <vector>
#include <iostream>
using namespace std;

void dfs(const vector<int>& nums, vector<vector<int>>& res,
         vector<int>& path, vector<bool>& used)
{
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, res, path, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    dfs(nums, res, path, used);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < static_cast<int>(res.size()); ++i) {
        cout << "[";
        int m = static_cast<int>(res[i].size());
        for (int j = 0; j < m; ++j) {
            if (j) cout << ",";
            cout << res[i][j];
        }
        cout << "]\n";
    }
    return 0;
}
```

编译 `g++ -Wall -Wextra -std=c++17`：0 警告；`[1,2,3,4]` 输出 24 条全排列。

## 本次纠正的问题

- dfs 循环误写成 `i < res[i].size()`——把「列数看 `res[i].size()`」放错了循环；dfs 里 `i` 是遍历 `nums` 的下标，应看 `nums.size()`（且 dfs 一开始 `res` 为空，读 `res[i]` 直接越界）。
- `main` 里 `j < nums.size()` 仍未改，应为 `res[i].size()`。
- `permute` 多塞了一个 `res` 参数，已改回 `res` 在函数内部定义。
- 打印从「先打 `res[i][0]`」升级为 `for(j=0...)` + `if(j) cout<<","`，以兼容空答案。

## 第 4 步：LeetCode 78 子集（只提出问题）

```text
输入：nums = [1, 2, 3]
输出：[]、[1]、[2]、[3]、[1,2]、[1,3]、[2,3]、[1,2,3]（共 2^3 = 8 条）
```

已提出的两个问题（尚未回答）：

1. 子集里空集和 `[1]` 也是答案，所以「收集答案」不能只放在 `path.size() == nums.size()` 的出口里——应该放在 `dfs` 的哪个位置？
2. 打印升级成 `for(j=0...)` + `if(j)`，是因为空集 `[]` 会让旧的 `res[i][0]` 越界——这个问题直接关系到子集题。

## 下次从这里继续

1. 回答：子集「收集答案」应该放在 `dfs` 的哪个位置。
2. 回答：这题还需要 `used` 数组吗。
3. 独立写出 LeetCode 78 子集代码，跑出 8 条结果。
4. 练习代码继续放 `build/`（已被 `.gitignore` 忽略）。