# 2026-10-11：全排列独立重写与回退追踪

## 今日目标

- 用自己的话解释保存 `[1,2,3]` 后为什么必须 `pop_back()` 并撤销标记
- 手动追踪 `[1,2,3]` 的前两条排列
- 关闭参考代码，独立写出全排列递归函数
- 再完成一道简单的回溯题

## 完成情况

| 步骤 | 内容 | 结果 |
| --- | --- | --- |
| 1 | 用自己的话解释 `pop_back()` 和撤销标记的分工 | 完成 |
| 2 | 手动追踪 `[1,2,3]` 的前两条排列 | 完成 |
| 3 | 关闭参考代码独立写出全排列 | 完成，编译运行 6 条结果顺序正确 |
| 4 | LeetCode 78 子集 | 只完成差异分析，未写代码 |

## 第 1 步：为什么必须回退

最终说清的结论：

- `path.pop_back()` 修的是 `path` 自己（当前分支已经排好的前缀）。不写它，`path` 会越挂越长，混进重复数字。
- `flag[i] = false`（代码里叫 `used[i]`）修的是数字的可用性。不写它，所有数字一直标着「已用」，`for` 里每次都 `continue`，一条新分支都开不出来，最后只剩一条答案。

关键对照实验（把 `path.pop_back()` 整行删掉）：

```text
[1]  ->  push 2  ->  [1,2]  ->  push 3  ->  [1,2,3]  ->  保存，return
                                                          ^ 这个 3 没人摘掉
回到「选了 2 的那层」改选 3：path 此刻是 [1,2,3]，再 push 3 得到 [1,2,3,3]  ❌
```

结论：`path` 是通过引用（`vector<int>& path`）在每层 `dfs` 之间共享的同一个对象，它不会自动回退，全靠 `pop_back()` 那一行显式恢复。

## 第 2 步：手动追踪前两条排列

```text
[1,2,3] --pop(3)--> [1,2] --pop(2)--> [1] --push(3)--> [1,3] --push(2)--> [1,3,2]
             第三层            第二层            第二层            第三层
```

- 两次 `pop_back()`：第一次在第三层摘掉 `3`，第二次在第二层摘掉 `2`。
- `used` 同步规则：每层都是「pop 完立刻撤销自己这一层当初标记的那个数字」。

| 时刻 | `path` | `used` |
| --- | --- | --- |
| `[1,2]` 那层选 3 之前 | `[1,2]` | `[T,T,F]` |
| 选 3 之后 | `[1,2,3]` | `[T,T,T]` |
| 第三层 pop 之后 | `[1,2]` | `[T,T,F]` |
| 第二层 pop 之后 | `[1]` | `[T,F,F]` |
| 第二层改选 3 | `[1,3]` | `[T,F,T]` |

## 第 3 步：独立写出的最终代码

```cpp
#include <iostream>
using namespace std;
#include <vector>

void dfs( const vector<int>&nums,vector<vector<int>>&res,vector<int>&path,vector<bool>&used)
{
    if(path.size()==nums.size())
    {
        res.push_back(path);
        return;
    }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])continue;

            path.push_back(nums[i]);
            used[i]=true;

            dfs(nums,res,path,used);

            path.pop_back();
            used[i]=false;
        }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>>res;
    vector<int>path;
    vector<bool>used;

    res.clear();
    path.clear();
    used.resize(nums.size(),false);

    dfs(nums,res,path,used);
    return res;
}

int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>>res;
    res=permute(nums);
    for(int i=0;i<res.size();i++)
    {
        cout<<"["<<res[i][0];
        for(int j=1;j<nums.size();j++)
        {
            cout<<','<<res[i][j];
        }
        cout<<"]";
        cout<<endl;
    }

return 0;
}
```

用 `g++ -Wall -std=c++17` 编译（exit code 0），运行输出：

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

输出是字典序，原因是 `for` 里 `i` 从小到大扫，每一层都优先挑最小的可用数字。编译器给出 3 条 `-Wsign-compare` 警告（有符号和无符号比较）。

## 本次踩过并修复的问题

1. 一开始把 `pop_back()` 和撤销标记说成同一件事。实际是两件：一个修 `path`，一个修数字的可用性。
2. 以为 `path` 会自动回退（答「push 之前 `path` 是 `[1,2]`」）—— 那是「有 `pop_back()` 时」才成立。
3. `for` 循环误写在 `if (path.size()==nums.size())` 的花括号里面、`return` 之后，永远执行不到，一次递归都不会发生。
4. `path.push_back(i)` 存的是下标而不是数字，应为 `path.push_back(nums[i])`。
5. `path.pop_back(i)` —— `pop_back()` 不带参数。
6. 少了 `#include <vector>`（编译器报 `'vector' does not name a type`）。
7. `permute` 返回类型写成 `vector<vector<int>>&`，返回了局部变量 `res` 的引用，属于悬垂引用（编译器 `-Wreturn-local-addr`）。去掉 `&` 才是安全写法。
8. `main` 里用 `nums.size()` 控制打印列数，应该看 `res[i].size()`。注意：这个 bug 换成 `[1,2,3,4]` 也测不出来，因为排列长度永远等于输入长度。

## 第 4 步：LeetCode 78 子集（只做了分析）

```text
输入：nums = [1, 2, 3]
输出：[]、[1]、[2]、[3]、[1,2]、[1,3]、[2,3]、[1,2,3]（共 2^3 = 8 条）
```

已指出的关键差别：全排列里只有「长度等于 3」的 `path` 才算答案；子集里空集和 `[1]` 也是答案，长度各不相同，所以「收集答案」不能放在「走到最深一层」的那个出口里。

待回答的问题：「收集答案」应该放在 `dfs` 的哪个位置？这题还需要 `used` 数组吗？

## 下次从这里继续

1. 补交问题 11 的文字答案：`res` 是 `permute` 的局部变量，函数 `return` 之后返回它的引用会怎样。
2. 把 `main` 打印改成 `res[i].size()`；三处循环用 `static_cast<int>(nums.size())` 消掉 `-Wsign-compare`。
3. 顺手清理：`#include <vector>` 挪到 `using namespace std;` 之前；`res.clear()` / `path.clear()` 是多余的；`used` 可以直接写成 `vector<bool> used(nums.size(), false);`。
4. 做 LeetCode 78 子集：先回答「收集答案放在哪里」，再独立写出代码并运行验证 8 条结果（练习代码可以放在 `build/` 目录，`build/` 已被 `.gitignore` 忽略）。
5. 回答附加问题：子集题还需要 `used` 数组吗？