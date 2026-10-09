# 2026-10-10：递归与全排列

## 今日目标

- 检查递归思路和代码实现分别卡在哪里
- 使用问题引导分析 LeetCode 46 全排列
- 理解递归出口、选择、标记、递归和回退
- 记录仍需独立完成的部分

## 题目

LeetCode 46：全排列

```text
输入：[1, 2, 3]
输出：
[1,2,3], [1,3,2], [2,1,3],
[2,3,1], [3,1,2], [3,2,1]
```

## 本次逐步分析

已经能够正确列出 `[1, 2, 3]` 的六个排列：

```text
123、132、213、231、312、321
```

已经找出的过程：

```text
固定第一位
-> 从剩余未使用的数字中选一个放第二位
-> 再处理剩下的位置
```

已经确定的状态：

- `res`：保存所有排列结果
- `path`：保存当前正在形成的排列
- `flag`：标记某个数字是否已经使用
- 递归出口：`path.size() == nums.size()`
- 出口操作：把 `path` 保存进 `res`
- 循环中只选择 `flag[i] == false` 的数字
- 选择后：标记、加入 `path`、递归
- 回退后：撤销标记、移除 `path` 末尾元素

## 参考代码

由于本次时间有限，按照要求先生成一版参考代码，后续需要自己复述和重写：

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(
        const vector<int>& nums,
        vector<vector<int>>& res,
        vector<int>& path,
        vector<bool>& flag
    ) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (flag[i]) {
                continue;
            }

            flag[i] = true;
            path.push_back(nums[i]);

            dfs(nums, res, path, flag);

            path.pop_back();
            flag[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> flag(nums.size(), false);

        dfs(nums, res, path, flag);
        return res;
    }
};
```

## 关键步骤

```text
flag[i] = true          选择 nums[i]
path.push_back(nums[i]) 加入当前排列
dfs(...)                继续选择下一位
path.pop_back()         撤销路径末尾
flag[i] = false         撤销数字的使用标记
```

第一条路径：

```text
选择 1 -> 选择 2 -> 选择 3
path = [1,2,3]
保存结果
撤销 3
回到上一层后撤销 2
再尝试 3 -> 2
得到 [1,3,2]
```

## 本次纠正的问题

- `flag[1]` 必须写成 `flag[i]`
- 递归调用、`pop_back()` 和撤销标记必须位于 `if` 成功分支内
- 引用语法是 `类型& 名称`
- 如果 `res`、`path`、`flag` 只属于当前调用，更适合作为引用参数传入
- `nums` 不会被修改，因此可以使用 `const vector<int>&`

## 需要继续巩固

目前仍然需要能够独立回答：

1. 为什么保存 `[1,2,3]` 后必须执行 `pop_back()`？
2. 为什么撤销 `flag[i]` 后还需要修改 `path`？
3. 不使用参考代码，能否独立写出函数签名和递归结构？
4. 能否逐步模拟 `[1,2,3]` 的回退过程？

## 下次学习

- 先用自己的话解释 `pop_back()` 和撤销标记的作用
- 手动追踪 `[1,2,3]` 的前两条排列
- 关闭参考代码，独立写出递归函数
- 再完成一道简单的递归题或回溯题