### 五子棋AI实现文档

#### 1. 概述

本项目实现了一个基于极大极小搜索和Alpha-Beta剪枝算法的五子棋AI。该AI能够根据当前棋盘状态进行决策，选择最优的落子位置。AI的核心算法包括棋型分析、局面评估、启发式搜索和极大极小搜索。

#### 2. 主要功能模块

##### 2.1 棋盘表示

- **棋盘大小**：`BOARD_SIZE` 定义为12x12。
- **棋盘状态**：使用二维数组 `board[BOARD_SIZE][BOARD_SIZE]` 表示棋盘，其中：
  - `EMPTY` (0) 表示空位。
  - `BLACK` (1) 表示黑子。
  - `WHITE` (2) 表示白子。

##### 2.2 棋型分析

- **棋型结构体 `Info`**：用于存储棋型的信息，包括长连、活四、冲四、死四、活三、眠三、死三、活二、眠二、死二、活一、眠一、死一等。
- **棋型分析函数 `typeAnalysis`**：根据连子数目和边缘信息判断棋型。
- **单点得分函数 `singleScore`**：计算某个点的得分，考虑该点的棋型信息。
- **整体局面得分函数 `wholeScore`**：计算整个棋盘的得分，考虑所有棋子的得分。

##### 2.3 极大极小搜索

- **极大极小搜索函数 `minmax`**：在给定的搜索深度内，通过递归搜索找到最优的落子位置。
- **Alpha-Beta剪枝函数 `alphaBeta`**：在极大极小搜索的基础上，通过Alpha-Beta剪枝减少不必要的搜索。

##### 2.4 启发式搜索

- **启发式搜索函数 `inspireFind`**：在棋盘上找到所有可能的落子位置，并计算每个位置的得分，然后根据得分进行排序。
- **快速排序函数 `quickSortMoves`**：对启发式搜索得到的落子位置进行排序，提高搜索效率。

##### 2.5 落子与判断

- **落子函数 `set`**：在棋盘上落子。
- **取消落子函数 `unSet`**：撤销之前的落子。
- **判断五连函数 `JudgeFive`**：判断某个位置是否形成五连。

##### 2.6 AI决策

- **AI初始化函数 `initAI`**：初始化AI的对手标识。
- **AI落子函数 `turn`**：AI根据当前局面进行决策，选择最优的落子位置。

##### 2.7 交互接口

- **开始游戏函数 `start`**：初始化棋盘，并根据AI的标识进行初始化。
- **结束游戏函数 `end`**：结束游戏并退出程序。
- **主循环函数 `loop`**：通过命令行与外部程序进行交互，接收命令并执行相应的操作。

#### 3. 代码结构

- **头文件包含**：包括标准输入输出库、字符串处理库、时间库等。
- **宏定义**：定义了棋盘大小、棋子类型、搜索深度、极大极小值等常量。
- **数据结构**：定义了棋盘、棋型、落子位置等结构体。
- **函数实现**：包括棋型分析、局面评估、极大极小搜索、启发式搜索、落子与判断、AI决策、交互接口等功能的实现。

#### 4. 算法流程

1. **初始化**：根据AI的标识初始化棋盘和对手标识。
2. **接收命令**：通过命令行接收外部程序的命令，包括开始游戏、落子、轮到AI落子、结束游戏等。
3. **棋型分析**：在AI落子前，对当前棋盘进行棋型分析，计算每个可能落子位置的得分。
4. **极大极小搜索**：在给定的搜索深度内，通过极大极小搜索和Alpha-Beta剪枝找到最优的落子位置。
5. **落子**：AI根据搜索结果选择最优的落子位置，并更新棋盘状态。
6. **结束游戏**：当游戏结束时，接收结束命令并退出程序。

#### 5. 性能优化

- **启发式搜索**：通过启发式搜索减少搜索空间，提高搜索效率。
- **Alpha-Beta剪枝**：在极大极小搜索中使用Alpha-Beta剪枝减少不必要的搜索。
- **快速排序**：对启发式搜索得到的落子位置进行排序，进一步提高搜索效率。

#### 6. 使用说明

- **编译**：使用C语言编译器编译代码，生成可执行文件。
- **运行**：通过命令行运行可执行文件，并与外部程序进行交互。
- **命令格式**：外部程序通过标准输入发送命令，AI通过标准输出返回结果。

#### 7. 未来改进方向

- **增加搜索深度**：在计算资源允许的情况下，增加搜索深度，提高AI的决策能力。
- **优化棋型分析**：进一步优化棋型分析算法，提高局面评估的准确性。
- **多线程优化**：利用多线程技术并行化搜索过程，提高计算效率。

#### 8. 总结

本项目实现了一个基于极大极小搜索和Alpha-Beta剪枝算法的五子棋AI，能够根据当前棋盘状态进行决策，选择最优的落子位置。通过启发式搜索、快速排序和Alpha-Beta剪枝等技术，提高了搜索效率和决策能力。