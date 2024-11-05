#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#define BOARD_SIZE 12  // 棋盘大小
#define EMPTY 0        // 空位
#define BLACK 1        // 黑棋
#define WHITE 2        // 白棋
#define INF 9223372036854775800 // 正无穷
#define _INF -9223372036854775800 // 负无穷
#define DEPTH 6        //搜索深度
#define START "START"  // 开始游戏
#define PLACE "PLACE"  // 放置棋子
#define TURN "TURN"    // 轮到我方下棋
#define END "END"      // 游戏结束
const int BOARD_MIDDLE_1 = (BOARD_SIZE + 1) / 2 - 1;
const int BOARD_MIDDLE_2 = BOARD_SIZE / 2;
struct chessType {
    int more;    //长连   
    int win5;    //连五
    int alive4;  //活4
    int conti4;  //冲4
    int dead4;   //死4
    int alive3;  //活3
    int conti3;  //眠3
    int dead3;   //死3
    int alive2;  //活2
    int conti2;  //眠2
    int dead2;   //死2
    int alive1;  //活1
    int conti1;  //眠1
    int dead1;   //死1
};
// 坐标结构体
struct coordinate {
    int x = -1;
    int y = -1;
    long long score = 0;
    coordinate(int a = 0, int b = 0, long long s = 0) : x(a), y(b), score(s) {}
};
// 棋盘节点结构体
struct Nude {
    int board[BOARD_SIZE][BOARD_SIZE] = { {0} }; // 棋盘状态
    int state = 0; // 棋盘状态标识
    Nude() {
        // 初始化棋盘，放置初始棋子
        board[BOARD_MIDDLE_1][BOARD_MIDDLE_1] = WHITE;
        board[BOARD_MIDDLE_2][BOARD_MIDDLE_2] = WHITE;
        board[BOARD_MIDDLE_2][BOARD_MIDDLE_1] = BLACK;
        board[BOARD_MIDDLE_1][BOARD_MIDDLE_2] = BLACK;
    }
    void arr_input(int x, int y, int playerround) {
        board[x][y] = playerround; // 在指定位置放置棋子
    }
};
class Game {
public:
    int myFlag;
    int enemyFlag;
    Nude MAP;
    Game() : myFlag(0), enemyFlag(0){}

    void loop();
    void test();
};
Game game;
void debug(const char *str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);
}
// 判断坐标是否在棋盘范围内
bool judgeInRange(coordinate temp) {
    if (temp.x < 0) return false;
    if (temp.y < 0) return false;
    if (temp.x >= BOARD_SIZE) return false;
    if (temp.y >= BOARD_SIZE) return false;
    return true;
}
// 获取指定位置的棋子颜色
int getColor(coordinate target) {
    if (judgeInRange(target))
        return game.MAP.board[target.x][target.y];
    else
        return game.enemyFlag;
}
// 在指定位置放置棋子
void place(coordinate target, int player = game.myFlag) {
    game.MAP.board[target.x][target.y] = player;
}
// 快速排序函数
int partition(coordinate *s, int high, int low) {
    long long pi = s[high].score;
    int i = low;
    for (int j = low; j <= high - 1; j++) {
        if (s[j].score >= pi) {
            coordinate temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
        }
    }
    coordinate temp = s[i];
    s[i] = s[high];
    s[high] = temp;
    return i;
}
void quickSort(coordinate *s, int high, int low = 0) {
    if (low < high) {
        int pi = partition(s, high, low);
        quickSort(s, pi - 1, low);
        quickSort(s, high, pi + 1);
    }
}
//返回p点dire方向上w距离的点
coordinate Neighbor(coordinate temp, int dire, int w) {
    const int direction[4][2] = { {1,0},{0,1},{1,1},{1,-1} };
    coordinate neighbor;
    neighbor.x = temp.x + w * direction[dire][0];
    neighbor.y = temp.y + w * direction[dire][1];
    return neighbor;
}
//判断点在d距离内是否有邻居
int hasNeighbor(coordinate temp, int d) {
    //找棋盘上有落子点d个距离内
    for (int i = 0; i < 4; i++) {
        for (int j = -d; j <= d; j++) {
            if (j != 0) {
                coordinate neighbor = Neighbor(temp, i, j);
                if (judgeInRange(neighbor) && getColor(neighbor))
                    return 1;
            }
        }
    }
    return 0;
}  
//获取drie方向上的情况
int analyzeDire(coordinate temp, int dire, int player, char *beside) {
    int length = 1;
    int i;
    for (i = -1; ; i--) {
        coordinate neighbor = Neighbor(temp, dire, i);
        if (judgeInRange(neighbor) && player == game.MAP.board[neighbor.x][neighbor.y])
            length++;
        else {
            for (int j = 0; j < 4; j++) {
                neighbor = Neighbor(temp, dire, i - j);
                if (judgeInRange(neighbor))
                    beside[j] = game.MAP.board[neighbor.x][neighbor.y];
                else
                    beside[j] = 3 - player;
            }
            break;
        }
    }
    for (i = 1; ; i++) {
        coordinate neighbor = Neighbor(temp, dire, i);
        if (judgeInRange(neighbor) && player == game.MAP.board[neighbor.x][neighbor.y])
            length++;
        else {
            for (int j = 0; j < 4; j++) {
                neighbor = Neighbor(temp, dire, i + j);
                if (judgeInRange(neighbor))
                    beside[4 + j] = game.MAP.board[neighbor.x][neighbor.y];
                else
                    beside[4 + j] = 3 - player;
            }
            break;
        }
    }
    return length;
}
int analyzeDire(coordinate temp, int dire, int player) {
    int length = 1;
    int i;
    for (i = -1; ; i--) {
        coordinate neighbor = Neighbor(temp, dire, i);
        if (judgeInRange(neighbor) && player == game.MAP.board[neighbor.x][neighbor.y])
            length++;
        else
            break;
    }
    for (i = 1; ; i++) {
        coordinate neighbor = Neighbor(temp, dire, i);
        if (judgeInRange(neighbor) && player == game.MAP.board[neighbor.x][neighbor.y])
            length++;
        else
            break;
    }
    return length;
}
//根据连子数目和边缘信息判断棋型
chessType typeAnalysis(coordinate p, int dire, int player)
{
    char b[8] = { 0 }; //beside
    int length = analyzeDire(p, dire, player, b); // 获取p点连子的长度和两边延伸4子的信息
    chessType temp = { 0 };
    if (length > 5)
        temp.more++;
    else if (length == 5)
        temp.win5++;
    else if (length == 4){
        if (b[0] == 0)
            if (b[4] == 0)
                temp.alive4++;//011110
            else
                temp.conti4++;//011112
        else
            if (b[4] == 0)
                temp.conti4++;//211110
            else
                temp.dead4++;//211112 
    }
    else if (length == 3){
        if (b[0] == 0)
            if (b[1] == player)
                if (b[4] == 0)
                    if (b[5] == player)
                        temp.conti4 += 2;//1011101
                    else if (b[5] == 0)
                        temp.alive3++;//1011100
                    else
                        temp.conti4++;//1011102
                else
                    temp.conti4++;//101112x
            else if (b[1] == 0)
                if (b[4] == 0)
                    if (b[5] == player)
                        temp.conti4++;//0011101
                    else
                        temp.alive3++;//0011102
                else
                    temp.conti3++;//001112x
            else
                if (b[4] == 0)
                    if (b[5] == player)
                        temp.conti4++;//0011101
                    else
                        temp.alive3++;//0011102
                else
                    temp.conti3++;//001112x
        else
            if (b[4] == 0)
                if (b[5] == player)
                    temp.conti4++;//x211101
                else
                    temp.conti3++;//x211100
            else
                temp.dead3++;//x21112x
    }
    else if (length == 2) {
        if (b[0] == 0) {
            if (b[4] == 0) {
                if (b[1] == player)
                    if (b[5] == player)
                        if (b[2] == player)
                            if (b[6] == player)
                                temp.conti4 += 2;//11011011
                            else
                                temp.conti4++;//1101101x
                        else if (b[2] == 0)
                            if (b[6] == player)
                                temp.conti4++;//01011011
                            else
                                temp.alive3++;//0101101x
                        else
                            if (b[6] == player)
                                temp.conti4++;//21011011
                            else if (b[6] == 0)
                                temp.alive3++;//21011010
                            else
                                temp.conti3++;//21011012
                    else
                        if (b[2] == player)
                            temp.conti4++;//110110xx
                        else if (b[2] == 0)
                            temp.alive3++;//010110xx
                        else
                            temp.conti3++;//210110xx
                else if (b[1] == 0)
                    if (b[5] == player)
                        if (b[6] == player)
                            temp.conti4++;//x0011011
                        else if (b[6] == 0)
                            temp.alive3++;//x0011010
                        else
                            temp.conti3++;//x0011012
                    else
                        temp.alive2++;//x00110xx
                else
                    if (b[5] == player)
                        if (b[6] == player)
                            temp.conti4++;//x2011011
                        else if (b[6] == 0)
                            temp.alive3++;//x2011010
                        else
                            temp.conti3++;//x2011012
                    else if (b[5] == 0)
                        temp.alive2++;//x201100x
                    else
                        temp.dead2++;//x201102x
            }
            else
                if (b[1] == player)
                    if (b[2] == player)
                        temp.conti4++;//110112xx
                    else if (b[2] == 0)
                        temp.conti3++;//010112xx
                    else
                        temp.dead3++;//210112xx
                else if (b[1] == 0)
                    if (b[2] == player)
                        temp.conti3++;//100112xx
                    else if (b[2] == 0)
                        temp.conti2++;//000112xx
                    else
                        temp.dead2++;//200112xx
                else
                    temp.dead2++;//x20112xx
        }
        else
            if (b[4] == 0) {
                if (b[5] == player)
                    if (b[6] == player)
                        temp.conti4++;//xx211011
                    else if (b[6] == 0)
                        temp.conti3++;//xx211010
                    else
                        temp.dead3++;//xx211012
                else if (b[5] == 0)
                    if (b[6] == player)
                        temp.conti3++;//xx211001
                    else if (b[6] == 0)
                        temp.conti2++;//xx211000
                    else
                        temp.dead2++;//xx211002
                else
                    temp.dead2++;//xx21102x
            }
            else
                temp.dead2++;//xx2112xx
    }
    else {
        if (b[0] == 0) {
            if (b[4] == 0) {
                if (b[1] == player) {
                    if (b[5] == player) {
                        if (b[2] == player) {
                            if (b[6] == player) {
                                if (b[3] == player)
                                    if (b[7] == player)
                                        temp.conti4 += 2; // 111010111                                   
                                    else
                                        temp.conti4++; // 11101011x
                                else if (b[3] == 0)
                                    if (b[7] == player)
                                        temp.conti4++; // 011010111                                   
                                    else
                                        temp.alive3++; // 01101011x                                                                 
                                else
                                    if (b[7] == player)
                                        temp.conti4++; // 211010111                                   
                                    else if (b[7] == 0)
                                        temp.alive3++; // 211010110                                   
                                    else
                                        temp.conti3++; // 211010112                                   
                            }
                            else
                                if (b[3] == player)
                                    temp.conti4++; // 1110101xx                              
                                else if (b[3] == 0)
                                    temp.alive3++; // 0110101xx                               
                                else
                                    temp.conti3++; // 2110101xx                              
                        }
                        else if (b[2] == 0) {
                            if (b[6] == player)
                                if (b[7] == player)
                                    temp.conti4++; // x01010111
                                else if (b[7] == 0)
                                    temp.alive3++; // x01010110
                                else
                                    temp.conti3++; // x01010112
                            else
                                temp.alive2++; // x010101xx
                        }
                        else {
                            if (b[6] == player)
                                if (b[7] == player)
                                    temp.conti4++; // x21010111
                                else if (b[7] == 0)
                                    temp.alive3++; // x21010110
                                else
                                    temp.conti3++; // x21010112
                            else if (b[6] == 0)
                                temp.alive2++; // x2101010x     
                            else
                                temp.conti3++; // x2101012x    
                        }
                    }
                    else {
                        if (b[2] == player)
                            if (b[3] == player)
                                temp.conti4++; // 1110102xx
                            else if (b[3] == 0)
                                temp.alive3++; // 0110102xx                                                                 
                            else
                                temp.conti3++; // 2110102xx
                        else if (b[2] == 0)
                            temp.alive2++; // x010102xx
                        else
                            temp.conti2++; // x210102xx  
                    }
                }
                else {
                    if (b[5] == player)
                        if (b[6] == player)
                            if (b[7] == player)
                                temp.conti4++; // xxx010111                                   
                            else if (b[7] == 0)
                                temp.alive3++; // xxx010110
                            else
                                temp.conti3++; // xxx010112
                        else if (b[6] == 0)
                            temp.alive2++; // xxx01010x
                        else
                            temp.conti2++; // xxx01012x  
                    else
                        temp.alive1++; // xxx0102xx  
                }
            }
            else {
                if (b[1] == player) {
                    if (b[2] == player)
                        if (b[3] == player)
                            temp.conti4++; // 111012xxx
                        else if (b[3] == 0)
                            temp.conti3++; // 011012xxx                                                                 
                        else
                            temp.dead3++; // 211012xxx                                              
                    else if (b[2] == 0) 
                        if (b[3] == player)
                            temp.conti3++; // 101012xxx
                        else if (b[3] == 0)
                            temp.conti2++; // 001012xxx                                                                 
                        else
                            temp.dead2++; // 201012xxx   
                    else
                        temp.dead2++; // x21012xxx 
                }
                else
                     temp.conti1++; // xxx012xxx 
            }
        }
        else {
            if (b[4] == 0) {
                if (b[5] == player) {
                    if (b[6] == player)
                        if (b[7] == player)
                            temp.conti4++; // xxx210111                                   
                        else if (b[7] == 0)
                            temp.conti3++; // xxx210110
                        else
                            temp.dead4++; // xxx210112
                    else if (b[6] == 0)
                        if (b[7] == player)
                            temp.conti3++; // xxx210101                                   
                        else if (b[7] == 0)
                            temp.conti2++; // xxx210100
                        else
                            temp.dead2++; // xxx210102
                    else
                        temp.dead2++; // xxx21012x
                }
                else if (b[5] == 0) {
                    if (b[6] == player)
                        if (b[7] == player)
                            temp.conti3++; // xxx210011                                   
                        else if (b[7] == 0)
                            temp.conti2++; // xxx210010
                        else
                            temp.dead2++; // xxx210102
                    else if (b[6] == 0)
                        if (b[7] == player)
                            temp.conti2++; // xxx210001                                   
                        else if (b[7] == 0)
                            temp.conti1++; // xxx210000
                        else
                            temp.dead1++; // xxx210002
                    else
                        temp.dead1++; // xxx21002x
                }
                else
                    temp.dead1++; // xxx2102xx
            }
            else
                temp.dead1++; // xxx212xxx 
        }
    }
    return temp;
}
//单点得分
int singleScore(coordinate p, int player) {
    chessType chesstype = typeAnalysis(p, 0, player);
    for (int i = 1; i < 4; i++) {
        chessType temp;
        temp = typeAnalysis(p, i, player);
        chesstype.more += temp.more;
        chesstype.win5 += temp.win5;
        chesstype.alive4 += temp.alive4;
        chesstype.conti4 += temp.conti4;
        chesstype.dead4 += temp.dead4;
        chesstype.alive3 += temp.alive3;
        chesstype.conti3 += temp.conti3;
        chesstype.dead3 += temp.dead3;
        chesstype.alive2 += temp.alive2;
        chesstype.conti2 += temp.conti2;
        chesstype.dead2 += temp.dead2;
        chesstype.alive1 += temp.alive1;
        chesstype.conti1 += temp.conti1;
        chesstype.dead1 += temp.dead1;
    }
    int score = ((chesstype.more << 30) + (chesstype.win5 << 30) + (chesstype.alive4 << 18) + (chesstype.conti4 << 13) + (chesstype.dead4 << 8) + (chesstype.alive3 << 14) + (chesstype.conti3 << 10) + 
                (chesstype.dead3 << 7) + (chesstype.alive2 << 10) + (chesstype.conti2 << 7)  + (chesstype.dead2 << 2) + (chesstype.alive1 << 7)  + (chesstype.conti1 << 3)  +  chesstype.dead1);
    if ((chesstype.conti4 >= 1 && chesstype.alive3 >= 1) || chesstype.alive4 >= 1 || chesstype.conti4 >= 2)//必胜
        score += 8388608;
    if (chesstype.alive3 >= 2)//必胜?
        score += 1048576;
    return score;
}
//棋盘整体局面分
long long wholeScore(int player) {
    long long comScore = 0, humScore = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            coordinate temp = { i,j,0 };
            if (game.MAP.board[i][j] == player)//己方落子的单点分相加
                comScore += singleScore(temp, player);
            else if (game.MAP.board[i][j] == 3 - player)//对方落子的单点分相加
                humScore += singleScore(temp, 3 - player);
        }
    }
    return comScore - humScore;//己方总分减对方总分 得到当前对己方来说的局势分
}
//响应上一次的操作
int respondMove(coordinate *scoreBoard, coordinate command, int player) {
    int length = 1;
    // 分析落子点周围的棋型
    for (int i = 0; i < 4; i++) {
        chessType temp = typeAnalysis(command, i, player);
        // 如果出现活三或四，进行相应的处理
        if (temp.conti4 >= 1 || temp.alive4 >= 1) {
            for (int j = -4; j <= 4; j++) {
                coordinate target = Neighbor(command, i, j);
                if (getColor(target)) continue;
                place(target, player);
                if (analyzeDire(command, i, player) >= 5){
                    scoreBoard[0] = target;
                    place(target, 0);
                    break;
                }
                place(target, 0);
            }
            return -1;
        }
        if (temp.alive3 >= 1) {
            for (int j = -3; j <= 3; j++) {
                coordinate target = Neighbor(command, i, j);
                if (getColor(target)) continue;
                place(target, player);
                if (analyzeDire(command, i, player) == 4)
                    scoreBoard[length - 1] = target;
                place(target, 0);
            }
            return length;
        }
    }
    return 0;
}
// 启发性搜索
int inspireSearch(coordinate *scoreBoard, int player) {
    int length = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game.MAP.board[i][j] == 0) {
                coordinate temp = { i, j ,0};
                if (hasNeighbor(temp, 4)) {
                    scoreBoard[length] = temp;
                    scoreBoard[length].score = singleScore(temp, player);
                    scoreBoard[length].score += singleScore(temp, 3 - player);
                    length++;
                }
            }
        }
    }
    quickSort(scoreBoard, length - 1);
    return length > 8 ? 8 : length;
}
//负极大极小值搜索
coordinate alphaBeta(int depth, long long alpha, long long beta, int player, coordinate p) {
    if (depth == 0) {
        p.score = wholeScore(player);
        return p;
    }
    coordinate temp = p;
    coordinate steps[BOARD_SIZE * BOARD_SIZE];
    int length = inspireSearch(steps, player);
    for (int i = 0; i < length; i++) {
        place(steps[i], player);//模拟落子
        temp = alphaBeta(depth - 1, -beta, -alpha, 3 - player, steps[i]);//取负值并交换alpha和beta
        temp.score *= -1;
        place(steps[i], 0);//还原落子
        if (temp.score >= beta) {
            temp.score = beta;
            return temp;//剪枝
        }
        if (temp.score > alpha)
            alpha = temp.score;
    }
    temp.score = alpha;
    return temp;
}
//搜索入口
coordinate entrance(int depth, long long alpha, long long beta, int player, coordinate command, coordinate current) {
    coordinate steps[BOARD_SIZE * BOARD_SIZE]{};
    coordinate temp;
    coordinate best;
    int length;
    int myRespons = respondMove(steps, current, player);
    if (myRespons == -1) return steps[0];
    int enemyRespons = respondMove(steps, command, 3 - player);
    if (enemyRespons == -1) return steps[0];
    if (myRespons == 0 && enemyRespons > 0)
        length = enemyRespons;
    else
        length = inspireSearch(steps, player);//搜索可落子点
    for (int i = 0; i < length; i++) {
        place(steps[i], player);//模拟落子
        temp = alphaBeta(depth - 1, -beta, -alpha, 3 - player, steps[i]);//递归
        temp.score *= -1;
        place(steps[i], 0);//还原落子
        if (temp.score > alpha) {
            alpha = temp.score;
            best = steps[i];//记录最佳落子
        }
    }   
    return best;
}
// 主循环函数，处理游戏指令 
void Game::loop() {
    char tag[10] = { 0 }; // 存储指令的字符串
    coordinate command; // 存储命令的坐标
    coordinate current; // 当前棋子位置
    while (1) {
        memset(tag, 0, sizeof(tag)); // 清空指令字符串
        scanf("%s", tag); // 读取指令
        if (strcmp(tag, START) == 0) { // 开始游戏
            scanf("%d", &myFlag); // 读取我方棋子颜色
            enemyFlag = 3 - myFlag; // 计算敌方棋子颜色
            if (myFlag == 1) { // 如果我方是黑棋
                current.x = 4;
                current.y = 4;
            }
            else { // 如果我方是白棋
                current.x = BOARD_MIDDLE_1;
                current.y = BOARD_MIDDLE_1;
            }
            printf("OK\n"); // 回应开始指令
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0) { // 敌方放置棋子
            scanf("%d %d", &command.x, &command.y); // 读取敌方放置的坐标
            MAP.board[command.x][command.y] = enemyFlag; // 更新棋盘状态
            current = entrance(DEPTH, _INF, INF, myFlag, command, current); // 我方下棋的坐标
        }
        else if (strcmp(tag, TURN) == 0) { // 轮到我方下棋
            place(current); // 放置我方棋子
            printf("%d %d\n", current.x, current.y);
            fflush(stdout);
        }
    }
}
// 清屏函数
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// 打印棋盘
void printBoard(coordinate current) {
    printf("   0 1 2 3 4 5 6 7 8 9 1011\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%-3d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game.MAP.board[i][j] == 0) {
                printf(". ");
            }
            else if (game.MAP.board[i][j] == 1) {
                printf("X ");
            }
            else if (game.MAP.board[i][j] == 2) {
                printf("O ");
            }
        }
        printf("%3d\n", i);
    }
    printf("   0 1 2 3 4 5 6 7 8 9 1011\n");
    printf("%d %d\n", current.x, current.y);
}
// 测试函数
void Game::test() {
    coordinate command;
    coordinate current; // 当前棋子位置
    if (myFlag == 1) { // 如果我方是黑棋
        current.x = BOARD_MIDDLE_1;
        current.y = BOARD_MIDDLE_2;
        command = { BOARD_MIDDLE_1 ,BOARD_MIDDLE_1 ,0 };
    }
    else { // 如果我方是白棋
        current.x = BOARD_MIDDLE_1;
        current.y = BOARD_MIDDLE_1;
        command = { BOARD_MIDDLE_1 ,BOARD_MIDDLE_2 ,0 };
    }
    printf("Enter your flag (1 for black, 2 for white): ");
    scanf("%d", &enemyFlag);
    myFlag = 3 - enemyFlag;
    printf("OK\n");
    fflush(stdout);
    if (myFlag == 1){
        current = entrance(DEPTH, _INF, INF, myFlag, command, current);   
        fflush(stdout);
        place(current);
    }
    while (1) {
        clearScreen();
        printBoard(current);
        fflush(stdout);
        scanf("%d %d", &command.x, &command.y);
        MAP.board[command.x][command.y] = enemyFlag;
        current = entrance(DEPTH, _INF, INF, myFlag, command, current);
        place(current);
    }
}

// 主函数
int main() {
    if (1) game.test();
    game.loop(); // 进入主循环
    return 0;
}