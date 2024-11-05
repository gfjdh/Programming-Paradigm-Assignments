//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <vector>
//struct chessType {
//    int more;    //长连   
//    int win5;    //连五
//    int alive4;  //活4
//    int conti4;  //冲4
//    int dead4;   //死4
//    int alive3;  //活3
//    int conti3;  //眠3
//    int dead3;   //死3
//    int alive2;  //活2
//    int conti2;  //眠2
//    int dead2;   //死2
//    int alive1;  //活1
//    int conti1;  //眠1
//    int dead1;   //死1
//};
//// 坐标结构体
//struct coordinate {
//    int x = -1;
//    int y = -1;
//    long long score = 0;
//    coordinate(int a = 0, int b = 0, long long s = 0) : x(a), y(b), score(s) {}
//};
//
////根据连子数目和边缘信息判断棋型
//chessType typeAnalysis(const char b[8], int length, int player)
//{
//    chessType temp = { 0 };
//    if (length > 5)
//        temp.more++;
//    else if (length == 5)
//        temp.win5++;
//    else if (length == 4)
//    {
//        if (b[0] == 0)
//            if (b[4] == 0)
//                temp.alive4++;
//            else
//                temp.conti4++;
//        else
//            temp.dead4++;
//    }
//    else if (length == 3)
//    {
//        //if ((b[0] == 0 && b[1] == player) && (b[4] == 0 && b[5] == player))
//        //    temp.conti4 += 2;
//        //else if ((b[0] == 0 && b[1] == player) || (b[4] == 0 && b[5] == player))
//        //    temp.conti4++;
//        //else if (b[0] == 0 && b[4] == 0 && (b[1] == 0 || b[5] == 0))
//        //    temp.alive3++;
//        //else if ((b[0] == 0 && b[1] == 0) || (b[4] == 0 && b[5] == 0))
//        //    temp.conti3++;
//        //else
//        //    temp.dead3++;
//        if (b[0] == 0)
//            if (b[4] == 0)
//                if (b[1] == player)
//                    if (b[5] == player)
//                        temp.conti4 += 2;
//                    else
//                        temp.conti4++;
//                else
//                    temp.alive3++;
//            else
//                if (b[1] == player)
//                    temp.conti4++;
//                else
//                    temp.conti3++;
//        else
//            if (b[4] == 0)
//                if (b[5] == player)
//                    temp.conti4++;
//                else
//                    temp.conti3++;
//            else
//                temp.dead3++;
//    }
//    else if (length == 2)
//    {
//        if (b[0] == 0)
//            if (b[1] == player)
//                if (b[2] == player)
//                    if (b[4] == 0)
//                        if (b[5] == player)
//                            if (b[6] == player)
//                                temp.conti4 += 2;
//                            else
//                                temp.conti4++;
//                    else
//                        temp.conti4++;
//                else//b2!=player x101101
//                    if (b[4] == 0)
//                        if (b[5] == player)
//                            temp.alive3++;
//                        else
//                            temp.conti3++;
//                    else
//                        temp.conti3++;
//            else
//                if (b[4] == 0)
//                    if (b[5] == player)
//                        if (b[6] == 0)
//                            temp.alive3++;
//                        else
//                            temp.conti3++;
//                    else
//                        if (b[6] == 0)
//                            temp.alive2++;
//                        else
//                            temp.conti2++;
//                else
//                    if (b[5] == 0)
//                        temp.conti2++;
//                    else
//                        temp.dead3++;
//        else
//            if (b[4] == 0)
//                if (b[5] == player)
//                    if (b[6] == player)
//                        temp.conti4++;
//                    else
//                        temp.conti3++;
//                else
//                    if (b[6] == 0)
//                        temp.alive2++;
//                    else
//                        temp.conti2++;
//            else
//                if (b[5] == 0)
//                    temp.conti2++;
//                else
//                    temp.dead3++;
//        //if ((b[0] == 0 && b[1] == player && b[2] == player) && (b[4] == 0 && b[5] == player && b[6] == player))
//        //    temp.conti4 += 2;
//        //else if ((b[0] == 0 && b[1] == player && b[2] == player) || (b[4] == 0 && b[5] == player && b[6] == player))
//        //    temp.conti4++;
//        //else if (b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == 0) || (b[5] == player && b[6] == 0)))
//        //    temp.alive3++;
//        //else if ((b[0] == 0 && b[2] == 0 && b[1] == player) || (b[4] == 0 && b[6] == 0 && b[5] == player) ||
//        //        ((b[0] == 0 && b[4] == 0) && (b[1] == player || b[5] == player)) ||
//        //         (b[0] == 0 && b[1] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[6] == player))
//        //    temp.conti3++;
//        //else if ((b[0] == 0 && b[4] == 0 && b[5] == 0 && b[6] == 0) || (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[5] == 0) || (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[4] == 0))
//        //    temp.alive2++;
//        //else if ((b[0] == 0 && b[1] == 0 && b[2] == 0) || (b[4] == 0 && b[5] == 0 && b[6] == 0))
//        //    temp.conti2++;
//    }
//    else if (length == 1) {
//        //if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) && (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
//        //    temp.conti4 += 2;
//        //else if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
//        //    temp.conti4++;
//        //else if (b[0] == 0 && b[4] == 0 && ( (b[1] == player && b[2] == player && b[3] == 0) || (b[5] == player && b[6] == player && b[7] == 0) ) )
//        //    temp.alive3++;
//        //else if ((b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == player) || (b[5] == player && b[6] == player))) ||
//        //         (b[0] == 0 && b[3] == 0 && b[1] == player && b[2] == player) || (b[4] == 0 && b[7] == 0 && b[5] == player && b[6] == player) ||
//        //         (b[0] == 0 && b[1] == 0 && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == player && b[7] == player) ||
//        //         (b[0] == 0 && b[2] == 0 && b[1] == player && b[3] == player) || (b[4] == 0 && b[6] == 0 && b[5] == player && b[7] == player))
//        //    temp.conti3++;
//        //else if ((b[0] == 0 && b[4] == 0 && b[6] == 0 && b[5] == player && (b[1] == 0 || b[7] == 0)) ||
//        //         (b[4] == 0 && b[0] == 0 && b[2] == 0 && b[1] == player && (b[5] == 0 || b[3] == 0)) || 
//        //         (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[7] == 0 && b[6] == player)  || 
//        //         (b[4] == 0 && b[0] == 0 && b[1] == 0 && b[3] == 0 && b[2] == player))
//        //    temp.alive2++;
//        //else if ((b[0] == 0 && b[2] == 0 && b[3] == 0 && b[1] == player) || (b[4] == 0 && b[6] == 0 && b[7] == 0 && b[5] == player) || 
//        //         (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[1] == player) || (b[4] == 0 && b[0] == 0 && b[1] == 0 && b[5] == player) ||
//        //         (b[0] == 0 && b[1] == 0 && b[3] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[7] == 0 && b[6] == player) ||
//        //         (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[0] == 0 && b[6] == player) ||
//        //         (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == 0 && b[7] == player))
//        //    temp.conti2++;
//        //else if (b[0] == 0 && b[4] == 0)
//        //    temp.alive1++;
//        //else if (b[0] == 0 || b[4] == 0)
//        //    temp.conti1++;
//        //else
//        //    temp.dead1++;
//        if (b[0] == 0)
//            if (b[1] == player)
//                if (b[2] == player)
//                    if (b[3] == player)
//                        if (b[4] == 0)
//                            if (b[5] == player)
//                                if (b[6] == player)
//                                    if (b[7] == player)
//                                        temp.conti4 += 2;
//                                    else
//                                        temp.conti4++;
//                                else
//                                    temp.alive3++;
//                            else
//                                temp.conti4++;
//                        else
//                            temp.conti4++;
//                    else
//                        if (b[4] == 0)
//                            if (b[5] == player)
//                                if (b[6] == player)
//                                    temp.alive3++;
//                                else
//                                    temp.conti3++;
//                            else
//                                temp.conti3++;
//                        else
//                            temp.conti3++;
//                else
//                    if (b[4] == 0)
//                        if (b[5] == player)
//                            if (b[6] == player)
//                                if (b[7] == 0)
//                                    temp.alive3++;
//                                else
//                                    temp.conti3++;
//                            else
//                                if (b[7] == 0)
//                                    temp.alive2++;
//                                else
//                                    temp.conti2++;
//                        else
//                            if (b[7] == 0)
//                                temp.alive2++;
//                            else
//                                temp.conti2++;
//                    else
//                        if (b[5] == 0)
//                            temp.conti2++;
//                        else
//                            temp.dead3++;
//            else
//                if (b[4] == 0)
//                    if (b[5] == player)
//                        if (b[6] == player)
//                            if (b[7] == player)
//                                temp.conti4++;
//                            else
//                                temp.conti3++;
//                        else
//                            if (b[7] == 0)
//                                temp.alive2++;
//                            else
//                                temp.conti2++;
//                    else
//                        if (b[7] == 0)
//                            temp.alive2++;
//                        else
//                            temp.conti2++;
//                else
//                    if (b[5] == 0)
//                        temp.conti2++;
//                    else
//                        temp.dead3++;
//        else
//            if (b[4] == 0)
//                if (b[5] == player)
//                    if (b[6] == player)
//                        if (b[7] == player)
//                            temp.conti4++;
//                        else
//                            temp.conti3++;
//                    else
//                        if (b[7] == 0)
//                            temp.alive2++;
//                        else
//                            temp.conti2++;
//                else
//                    if (b[7] == 0)
//                        temp.alive2++;
//                    else
//                        temp.conti2++;
//            else
//                if (b[5] == 0)
//                    temp.conti2++;
//                else
//                    temp.dead3++;
//    }
//    return temp;
//}
//chessType typeAnalysis2(const char b[8], int length, int player)
//{
//    chessType temp = { 0 };
//    if (length > 5)
//        temp.more++;
//    else if (length == 5)
//        temp.win5++;
//    else if (length == 4)
//    {
//        if (b[0] == 0)
//            if (b[4] == 0)
//                temp.alive4++;
//            else
//                temp.conti4++;
//        else
//            temp.dead4++;
//    }
//    else if (length == 3)
//    {
//        if ((b[0] == 0 && b[1] == player) && (b[4] == 0 && b[5] == player))
//            temp.conti4 += 2;
//        else if ((b[0] == 0 && b[1] == player) || (b[4] == 0 && b[5] == player))
//            temp.conti4++;
//        else if (b[0] == 0 && b[4] == 0 && (b[1] == 0 || b[5] == 0))
//            temp.alive3++;
//        else if ((b[0] == 0 && b[1] == 0) || (b[4] == 0 && b[5] == 0))
//            temp.conti3++;
//        else
//            temp.dead3++;
//    }
//    else if (length == 2)
//    {
//        if ((b[0] == 0 && b[1] == player && b[2] == player) && (b[4] == 0 && b[5] == player && b[6] == player))
//            temp.conti4 += 2;
//        else if ((b[0] == 0 && b[1] == player && b[2] == player) || (b[4] == 0 && b[5] == player && b[6] == player))
//            temp.conti4++;
//        else if (b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == 0) || (b[5] == player && b[6] == 0)))
//            temp.alive3++;
//        else if ((b[0] == 0 && b[2] == 0 && b[1] == player) || (b[4] == 0 && b[6] == 0 && b[5] == player) ||
//                ((b[0] == 0 && b[4] == 0) && (b[1] == player || b[5] == player)) ||
//                 (b[0] == 0 && b[1] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[6] == player))
//            temp.conti3++;
//        else if ((b[0] == 0 && b[4] == 0 && b[5] == 0 && b[6] == 0) || (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[5] == 0) || (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[4] == 0))
//            temp.alive2++;
//        else if ((b[0] == 0 && b[1] == 0 && b[2] == 0) || (b[4] == 0 && b[5] == 0 && b[6] == 0))
//            temp.conti2++;
//    }
//    else if (length == 1) {
//        if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) && (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
//            temp.conti4 += 2;
//        else if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
//            temp.conti4++;
//        else if (b[0] == 0 && b[4] == 0 && ( (b[1] == player && b[2] == player && b[3] == 0) || (b[5] == player && b[6] == player && b[7] == 0) ) )
//            temp.alive3++;
//        else if ((b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == player) || (b[5] == player && b[6] == player))) ||
//                 (b[0] == 0 && b[3] == 0 && b[1] == player && b[2] == player) || (b[4] == 0 && b[7] == 0 && b[5] == player && b[6] == player) ||
//                 (b[0] == 0 && b[1] == 0 && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == player && b[7] == player) ||
//                 (b[0] == 0 && b[2] == 0 && b[1] == player && b[3] == player) || (b[4] == 0 && b[6] == 0 && b[5] == player && b[7] == player))
//            temp.conti3++;
//        else if ((b[0] == 0 && b[4] == 0 && b[6] == 0 && b[5] == player && (b[1] == 0 || b[7] == 0)) ||
//                 (b[4] == 0 && b[0] == 0 && b[2] == 0 && b[1] == player && (b[5] == 0 || b[3] == 0)) || 
//                 (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[7] == 0 && b[6] == player)  || 
//                 (b[4] == 0 && b[0] == 0 && b[1] == 0 && b[3] == 0 && b[2] == player))
//            temp.alive2++;
//        else if ((b[0] == 0 && b[2] == 0 && b[3] == 0 && b[1] == player) || (b[4] == 0 && b[6] == 0 && b[7] == 0 && b[5] == player) || 
//                 (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[1] == player) || (b[4] == 0 && b[0] == 0 && b[1] == 0 && b[5] == player) ||
//                 (b[0] == 0 && b[1] == 0 && b[3] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[7] == 0 && b[6] == player) ||
//                 (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[2] == player) || (b[4] == 0 && b[5] == 0 && b[0] == 0 && b[6] == player) ||
//                 (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == 0 && b[7] == player))
//            temp.conti2++;
//        else if (b[0] == 0 && b[4] == 0)
//            temp.alive1++;
//        else if (b[0] == 0 || b[4] == 0)
//            temp.conti1++;
//        else
//            temp.dead1++;
//    }
//    return temp;
//}
//
//// 清屏函数
//void clearScreen() {
//#ifdef _WIN32
//    system("cls");
//#else
//    system("clear");
//#endif
//}
//// 辅助函数：生成所有可能的 b[8] 组合
//std::vector<std::vector<char>> generateCombinations() {
//    std::vector<std::vector<char>> combinations;
//    for (int i = 0; i < (1 << 8); ++i) {
//        std::vector<char> combination(8, 0);
//        for (int j = 0; j < 8; ++j) {
//            if (i & (1 << j)) {
//                combination[j] = 1; // 假设 player 为 1
//            }
//        }
//        combinations.push_back(combination);
//    }
//    return combinations;
//}
//
//// 测试函数
//void test() {
//    std::vector<std::vector<char>> combinations = generateCombinations();
//    int player = 1; // 假设 player 为 1
//
//    for (int length = 1; length <= 5; ++length) {
//        for (const auto &b : combinations) {
//            chessType result1 = typeAnalysis(b.data(), length, player);
//            chessType result2 = typeAnalysis2(b.data(), length, player);
//
//            if (memcmp(&result1, &result2, sizeof(chessType)) != 0) {
//                std::cout << "Mismatch found for length=" << length << " and b=[";
//                for (char c : b) {
//                    std::cout << (int)c << " ";
//                }
//                std::cout << "]" << std::endl;
//                std::cout << "typeAnalysis result: ";
//                std::cout << "more=" << result1.more << ", win5=" << result1.win5 << ", alive4=" << result1.alive4 << ", conti4=" << result1.conti4 << ", dead4=" << result1.dead4 << ", alive3=" << result1.alive3 << ", conti3=" << result1.conti3 << ", dead3=" << result1.dead3 << ", alive2=" << result1.alive2 << ", conti2=" << result1.conti2 << ", dead2=" << result1.dead2 << ", alive1=" << result1.alive1 << ", conti1=" << result1.conti1 << ", dead1=" << result1.dead1 << std::endl;
//                std::cout << "typeAnalysis2 result: ";
//                std::cout << "more=" << result2.more << ", win5=" << result2.win5 << ", alive4=" << result2.alive4 << ", conti4=" << result2.conti4 << ", dead4=" << result2.dead4 << ", alive3=" << result2.alive3 << ", conti3=" << result2.conti3 << ", dead3=" << result2.dead3 << ", alive2=" << result2.alive2 << ", conti2=" << result2.conti2 << ", dead2=" << result2.dead2 << ", alive1=" << result2.alive1 << ", conti1=" << result2.conti1 << ", dead1=" << result2.dead1 << std::endl;
//            }
//        }
//    }
//}
//
//// 主函数
//int main() {
//    test();
//    return 0;
//}

		//if ((b[0] == 0 && b[1] == player && b[2] == player) && (b[4] == 0 && b[5] == player && b[6] == player))
		//    temp.conti4 += 2;
		//else if ((b[0] == 0 && b[1] == player && b[2] == player) ||
		//    (b[4] == 0 && b[5] == player && b[6] == player))
		//    temp.conti4++;
		//else if (b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == 0) || (b[5] == player && b[6] == 0)))
		//    temp.alive3++;
		//else if ((b[0] == 0 && b[2] == 0 && b[1] == player) ||
		//    (b[4] == 0 && b[6] == 0 && b[5] == player) ||
		//    (b[0] == 0 && b[4] == 0 && (b[1] == player || b[5] == player)) ||
		//    (b[0] == 0 && b[1] == 0 && b[2] == player) ||
		//    (b[4] == 0 && b[5] == 0 && b[6] == player))
		//    temp.conti3++;
		//else if ((b[0] == 0 && b[4] == 0 && b[5] == 0 && b[6] == 0) ||
		//    (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[5] == 0) ||
		//    (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[4] == 0))
		//    temp.alive2++;
		//else if ((b[0] == 0 && b[1] == 0 && b[2] == 0) ||
		//    (b[4] == 0 && b[5] == 0 && b[6] == 0))
		//    temp.conti2++;
		//else
		//    temp.dead2++;

		//if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) && (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
		//    temp.conti4 += 2;
		//else if ((b[0] == 0 && b[1] == player && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == player && b[6] == player && b[7] == player))
		//    temp.conti4++;
		//else if (b[0] == 0 && b[4] == 0 && ( (b[1] == player && b[2] == player && b[3] == 0) || (b[5] == player && b[6] == player && b[7] == 0) ) )
		//    temp.alive3++;
		//else if ((b[0] == 0 && b[4] == 0 && ((b[1] == player && b[2] == player) || (b[5] == player && b[6] == player))) ||
		//         (b[0] == 0 && b[3] == 0 && b[1] == player && b[2] == player) || (b[4] == 0 && b[7] == 0 && b[5] == player && b[6] == player) ||
		//         (b[0] == 0 && b[1] == 0 && b[2] == player && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == player && b[7] == player) ||
		//         (b[0] == 0 && b[2] == 0 && b[1] == player && b[3] == player) || (b[4] == 0 && b[6] == 0 && b[5] == player && b[7] == player))
		//    temp.conti3++;
		//else if ((b[0] == 0 && b[4] == 0 && b[5] == player && b[6] == 0 && (b[1] == 0 || b[7] == 0)) ||
		//         (b[0] == 0 && b[1] == player && b[2] == 0 && b[4] == 0 && (b[5] == 0 || b[3] == 0)) ||
		//         (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[6] == player && b[7] == 0)  ||
		//         (b[0] == 0 && b[1] == 0 && b[2] == player && b[3] == 0 && b[4] == 0))
		//    temp.alive2++;
		//else if ((b[0] == 0 && b[1] == player && b[2] == 0 && b[3] == 0) || (b[4] == 0 && b[5] == player && b[6] == 0 && b[7] == 0) ||
		//         (b[0] == 0 && b[1] == player && b[4] == 0 && b[5] == 0) || (b[0] == 0 && b[1] == 0 && b[4] == 0 && b[5] == player) ||
		//         (b[0] == 0 && b[1] == 0 && b[2] == player && b[3] == 0) || (b[4] == 0 && b[5] == 0 && b[6] == player && b[7] == 0) ||
		//         (b[0] == 0 && b[1] == 0 && b[2] == player && b[4] == 0) || (b[0] == 0 && b[4] == 0 && b[5] == 0 && b[6] == player) ||
		//         (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == player) || (b[4] == 0 && b[5] == 0 && b[6] == 0 && b[7] == player))
		//    temp.conti2++;
		//else if (b[0] == 0 && b[4] == 0)
		//    temp.alive1++;
		//else if (b[0] == 0 || b[4] == 0)
		//    temp.conti1++;
		//else
		//    temp.dead1++;
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <set>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

#define _DEBUG_ 1
#define _ONLINE_DEBUG_ 0
#define _TIMER_ 0

//³£Á¿Óëdef
typedef long long LL;
const int board_size = 12;
const int dpth = 4;
const int hashIndexSize = 0xffff;//ÑÚÂë,ÓÃÓÚÏÞÖÆÎ»Êý(¶þ½øÖÆ¶ÔÓ¦1111111111111111)
const int hashNoneScore = 99999999;//ÖÃ»»±íÖÐµÄ¿ÕÖµ

//·ÖÊýÆÀ¹À±í
const int MAX_SCORE = 10000000;
const int MIN_SCORE = -10000000;
const int FIVE_LINE = 1000000;     // ÎåÁ¬·ÖÊý
const int LIVE_FOUR = 40000;        // »îËÄ(ÔÚÁ½¸öµãÉÏÏÂ¶¼¿ÉÒÔÎåÁ¬)·ÖÊý
const int BLOCK_FOUR = 3000;       // ³åËÄ(ÔÚÎ¨Ò»µÄÒ»µãÉÏÏÂ¿ÉÒÔÎåÁ¬)·ÖÊý
const int LIVE_THREE = 3000;   // »îÈý(¿ÉÒÔ±ä³É»î4)·ÖÊý
const int BLOCK_THREE = 300;       // ÃßÈý(¿ÉÒÔ±ä³É³å4)·ÖÊý
const int LIVE_TWO = 200;          // »î¶þ(¿ÉÒÔ±ä³É»î3)·ÖÊý
const int BLOCK_TWO = 30;          // Ãß¶þ(¿ÉÒÔ±ä³ÉÃßÈý)·ÖÊý
const int LIVE_ONE = 30;           // »îÒ»(¿ÉÒÔ±ä³É»î¶þ)·ÖÊý
const int BLOCK_ONE = 1;           // ÃßÒ»(¿ÉÒÔ±ä³ÉÃß¶þ)·ÖÊý

//Ã¶¾ÙÀà
enum Chess {
	None = 0,
	Black = 1,
	White = 2,
};
//½á¹¹Ìå
struct Point {
	int x;
	int y;
	bool operator==(const Point &p) const {
		return x == p.x && y == p.y;
	}
	bool operator<(const Point &p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
};

struct Move {
	Point p;
	LL score;
};

struct Pattern {
	string pattern;
	int score;
};

struct HashItem {
	LL checksum;
	int depth;
	LL score;
	enum Flag { ALPHA = 0, BETA = 1, EXACT = 2, EMPTY = 3 } flag;
};

class PositionManager;

//È«¾Ö±äÁ¿
Chess field; // ¼º·½ÑÕÉ«
Chess opponent; // ¶Ô·½ÑÕÉ«
Chess board[board_size][board_size] = { None }; // ÆåÅÌ
LL all_score[2]; // ×Ü·ÖÊý,all_score[0]Îª¼º·½·ÖÊý,all_score[1]Îª¶Ô·½·ÖÊý
LL point_score[2][4][board_size * 2];//[chess][direction][index],¶ÔÓÚÊúºÍºá,»á¿Õ³öÀ´board_size¸öÎ»ÖÃ
Move bestMove = { {-1, -1} , MIN_SCORE };
//zobrist
LL boardZobristValue[2][board_size][board_size];//ÆåÅÌÃ¿¸öÎ»ÖÃµÄZobristÖµ,ÓÃÓÚ¼ÆËãµ±Ç°¾ÖÃæµÄZobristÖµ
LL currentZobristValue;//Ã¿Ò»¸ö¾ÖÃæ¶ÔÓ¦Ò»¸öZobristÖµ,currentZobristValueÎªµ±Ç°¾ÖÃæµÄZobristÖµ

//vector<Pattern> patterns = {
//	{ "11111" ,  FIVE_LINE   }, // Á¬Îå
//	{ "011110",  LIVE_FOUR   }, // »îËÄ
//	{ "211110",  BLOCK_FOUR  }, // ³åËÄ
//	{ "011112",  BLOCK_FOUR  },
//	{ "11011" ,  BLOCK_FOUR  },
//	{ "10111" ,  BLOCK_FOUR  },
//	{ "11101" ,  BLOCK_FOUR  },
//	{ "0011100", LIVE_THREE }, // »îÈý
//	{ "0011102", LIVE_THREE },
//	{ "2011100", LIVE_THREE },
//	{ "010110",  LIVE_THREE  },
//	{ "011010",  LIVE_THREE  },
//	{ "211100",  BLOCK_THREE }, // ÃßÈý
//	{ "001112",  BLOCK_THREE },
//	{ "210110",  BLOCK_THREE },
//	{ "010112",  BLOCK_THREE },
//	{ "210011",  BLOCK_THREE },
//	{ "110012",  BLOCK_THREE },
//	{ "011000",  LIVE_TWO    }, // »î¶þ
//	{ "001100",  LIVE_TWO    },
//	{ "000110",  LIVE_TWO    },
//	{ "010100",  LIVE_TWO    },
//	{ "001010",  LIVE_TWO    },
//	{ "010010",  LIVE_TWO    },
//	{ "211000",  BLOCK_TWO   }, // Ãß¶þ
//	{ "210100",  BLOCK_TWO   },
//	{ "000112",  BLOCK_TWO   },
//	{ "001012",  BLOCK_TWO   },
//	{ "210010",  BLOCK_TWO   },
//	{ "010012",  BLOCK_TWO   },
//	{ "210001",  BLOCK_TWO   },
//	{ "100012",  BLOCK_TWO   },
//	{ "010000",  LIVE_ONE    }, // »îÒ»
//	{ "001000",  LIVE_ONE    },
//	{ "000100",  LIVE_ONE    },
//	{ "000010",  LIVE_ONE    },
//	{ "210000",  BLOCK_ONE   }, // ÃßÒ»
//	{ "000012",  BLOCK_ONE   }
//};

//ÆÀ¹Àº¯Êý
LL Evaluate(Chess color);//×ÜÆÀ¹Àº¯Êý(ÆÀ¹ÀÕû¸öÆåÅÌ)
LL EvaluatePosition(Chess color, int x, int y);//ÆÀ¹ÀÄ³Ò»Î»ÖÃ
//LL PatternScore(Chess color, const string& line);//ËÑË÷Ä£Ê½,·µ»Ø¸÷¸öÆ¥ÅäµÄÄ£Ê½µÄ·ÖÊý
void UpdateScore(int x, int y);//¸üÐÂ·ÖÊý±í

//ËÑË÷º¯Êý
LL Alpha_Beta(Chess color, LL alpha, LL beta, int depth);//alpha-beta¼ôÖ¦
Point MakePlay(int depth);//¼º·½ÏÂÆå

//Ö÷º¯Êý
void StartGame();//ÓÎÏ·Ö÷Ñ­»·

//ÆäËüº¯Êý
struct PointComparator {
	bool operator()(const Point &a, const Point &b) const {
		return EvaluatePosition(field, a.x, a.y) > EvaluatePosition(field, b.x, b.y);
	}
};
void UpdateInfo(int x, int y) {
	UpdateScore(x, y);
}

set<Point, PointComparator> GetPossibleMoves(Chess color);//»ñÈ¡ËùÓÐ¿ÉÄÜµÄÂä×ÓÎ»ÖÃ

//position manager
struct HistoryPosition {
	HistoryPosition() : chosenPosition({ -1, -1 })
	{}
	Point chosenPosition;						//Ñ¡ÔñµÄÂä×Óµã
	set<Point> addedPositions;	//ÓÉÓÚchosenPosition¶øÌí¼ÓµÄ¿ÉÄÜÂä×Óµã
};

class PositionManager {
public:
	void AddPossiblePos(int x, int y);
	void RecoverLastState();
	set<Point, PointComparator> &GetPossiblePos();
private:
	bool isInBound(int x, int y) {
		return x >= 0 && x < board_size && y >= 0 && y < board_size;
	}
private:
	set<Point> currentPossiblePos;
	vector<HistoryPosition> history;
}ppm;

void PositionManager::AddPossiblePos(int x, int y) {
	HistoryPosition hp;
	hp.chosenPosition = { x, y };
	//°ÑÆå×Ó(x,y)ÖÜÎ§°Ë¸ö·½ÏòµÄµã(Empty,ÇÒÔÚÆåÅÌ·¶Î§ÄÚ)¼ÓÈëµ½currentPossiblePosºÍaddedPositionsÖÐ,Ã¿¸ö·½Ïò¼ÓÁ½¸öµã
	int dir[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
	for (int j = 1; j < 2; j++) {//change 3 to 2!to test
		for (int i = 0; i < 4; i++) {
			int dx = dir[i][0] * j, dy = dir[i][1] * j;
			if (isInBound(x + dx, y + dy) && board[x + dx][y + dy] == None) {
				auto insertRes = currentPossiblePos.insert({ x + dx, y + dy });
				if (insertRes.second)
					hp.addedPositions.insert({ x + dx, y + dy });
			}

			if (isInBound(x - dx, y - dy) && board[x - dx][y - dy] == None) {
				auto insertRes = currentPossiblePos.insert({ x - dx, y - dy });
				if (insertRes.second)
					hp.addedPositions.insert({ x - dx, y - dy });
			}
		}
	}
	//°Ñµ±Ç°µã´ÓcurrentPossiblePosÖÐÉ¾³ý
	currentPossiblePos.erase({ x, y });
	history.push_back(hp);
}

void PositionManager::RecoverLastState() {
	if (history.empty()) return;//²»´æÔÚÀúÊ·¼ÇÂ¼
	//È¡³ö×î½üÒ»ÌõÀúÊ·¼ÇÂ¼
	HistoryPosition hp = history.back();
	history.pop_back();
	//»Ö¸´currentPossiblePos(È¥³ýadded,¼ÓÉÏchosen)
	for (const auto &p : hp.addedPositions) {
		currentPossiblePos.erase(p);
	}
	currentPossiblePos.insert(hp.chosenPosition);
}

set<Point, PointComparator> &PositionManager::GetPossiblePos() {
	static set<Point, PointComparator> pp;
	pp.clear();
	for (const auto &p : currentPossiblePos) {
		//if (EvaluatePosition(field, p.x, p.y) > 0)
		pp.insert(p);
	}
	return pp;
}
//ÖÃ»»±í
//zobrist
// Éú³É64Î»Ëæ»úÊý
LL Random64() {
	return (LL)rand() | ((LL)rand() << 15) | ((LL)rand() << 30) | ((LL)rand() << 45) | ((LL)rand() << 60);
}

// ³õÊ¼»¯Ëæ»úÊý±í
void RandomBoardZobristValue() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size; k++) {
				boardZobristValue[i][j][k] = Random64();
			}
		}
	}
}

// ³õÊ¼»¯³õÊ¼¾ÖÃæµÄZobristÖµ
void InitCurrentZobristValue() {
	currentZobristValue = 0;
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (board[i][j] != None) {
				currentZobristValue ^= boardZobristValue[(int)board[i][j] - 1][i][j];
			}
		}
	}
}

// ¸üÐÂZobristÖµ
void UpdateZobristValue(int x, int y, Chess color) {
	currentZobristValue ^= boardZobristValue[(int)color - 1][x][y];
}
//´æ´¢ÒÑ¾­¼ÆËã¹ýµÄÆå¾ÖÆÀ·Ö¡£Ã¿¸öÌõÄ¿°üº¬¾ÖÃæµÄ¹þÏ£Öµ¡¢ÆÀ·Ö¡¢Éî¶ÈºÍÆÀ·ÖÀàÐÍ
HashItem hashItems[hashIndexSize + 1];//ÏÂ±ê·¶Î§0-1111111111111111

//¼ÇÂ¼ÖÃ»»±íÐÅÏ¢
void RecordHashItem(int depth, LL score, HashItem::Flag flag) {
	int index = currentZobristValue & hashIndexSize;
	//½öÔÚÒÔÏÂÁ½ÖÖÇé¿öÏÂ¸üÐÂÖÃ»»±í: 
		// 1.ÖÃ»»±íÎª¿Õ    
		// 2.µ±Ç°µÝ¹éÉî¶È´óÓÚÖÃ»»±íÉî¶È,ËµÃ÷µ±Ç°ÐÅÏ¢¸ü¾«×¼,ÔòÌæ»»µôÖÃ»»±íÄÚµÄÐÅÏ¢
	if (hashItems[index].flag == HashItem::EMPTY || hashItems[index].depth < depth) {
		hashItems[index].checksum = currentZobristValue;
		hashItems[index].depth = depth;
		hashItems[index].score = score;
		hashItems[index].flag = flag;
	}
}

//È¡ÖÃ»»±íÐÅÏ¢
LL GetHashScore(int depth, int alpha, int beta) {
	int index = currentZobristValue & hashIndexSize;
	//¿ÕÖµ
	if (hashItems[index].flag == HashItem::EMPTY) {
		return hashNoneScore;
	}
	if (hashItems[index].checksum == currentZobristValue) {
		//Èô¹þÏ£±íÉî¶È>=µ±Ç°Éî¶È,Ôò¿ÉÐÅ,·µ»Ø¹þÏ£±íÖÐµÄÖµ
		if (hashItems[index].depth >= depth) {
			//×¼È·ÖµÔòÖ±½Ó·µ»Ø
			if (hashItems[index].flag == HashItem::EXACT) {
				return hashItems[index].score;
			}
			//alphaÖµËµÃ÷´æ´¢µÄÖµÊÇÒ»¸öÏÂÏÞÖµ(²»±»µÐ·½¼ôÖ¦µÄÇé¿öÏÂµÄ×î´óÖµ)
			if (hashItems[index].flag == HashItem::ALPHA && hashItems[index].score <= alpha) {
				return alpha;
			}
			//betaÖµËµÃ÷´æ´¢µÄÖµÊÇÒ»¸öÉÏÏÞÖµ(²»±»¼º·½¼ôÖ¦µÄÇé¿öÏÂµÄ×îÐ¡Öµ)
			if (hashItems[index].flag == HashItem::BETA && hashItems[index].score >= beta) {
				return beta;
			}
		}
	}
	return hashNoneScore;
}

//AC×Ô¶¯»úÊµÏÖ×Ö·û´®Æ¥Åä,ÓÃÓÚ²éÕÒÆåÐÍ
class TrieNode;
class AC_Auto;
//TrieÊ÷½Úµã
class TrieNode {
public:
	friend class AC_Auto;
	TrieNode() : fail(-1), next{ -1, -1, -1 }, length(0), score(0) {}
private:
	char data;//½Úµã´æ´¢µÄ×Ö·û
	int fail;//Ê§°ÜÖ¸Õë
	int next[3];//×Ó½Úµã
	int length;//µ±Ç°½Úµã´ú±íµÄ×Ö·û´®³¤¶È
	int score;//µ±Ç°½Úµã´ú±íµÄ×Ö·û´®µÄ·ÖÊý
};

//AC×Ô¶¯»ú
class AC_Auto {
public:
	AC_Auto();
	void BuildTrieTree();
	void BuildFailPointer();
	LL PatternScore(const string &text);
private:
	vector<TrieNode> nodes;//TrieÊ÷
	vector<string> patterns;//Ä£Ê½´®
	vector<int> scores;//Ä£Ê½´®¶ÔÓ¦µÄ·ÖÊý
}AC_Searcher;

AC_Auto::AC_Auto()
	: patterns({ "11111", "011110", "211110", "011112", "11011", "10111", "11101", "0011100", "0011102",
				 "2011100", "010110", "011010", "211100", "001112", "210110", "010112", "210011", "110012", "011000",
				 "001100", "000110", "010100", "001010", "010010", "211000", "210100", "000112", "001012", "210010",
				 "010012","210001", "100012", "010000", "001000", "000100", "000010", "210000", "000012" }), //38
	scores({ FIVE_LINE, LIVE_FOUR, BLOCK_FOUR, BLOCK_FOUR, BLOCK_FOUR, BLOCK_FOUR, BLOCK_FOUR, LIVE_THREE, LIVE_THREE,
			 LIVE_THREE, LIVE_THREE, LIVE_THREE, BLOCK_THREE, BLOCK_THREE, BLOCK_THREE, BLOCK_THREE, BLOCK_THREE, BLOCK_THREE,
			 LIVE_TWO, LIVE_TWO, LIVE_TWO, LIVE_TWO, LIVE_TWO, LIVE_TWO, BLOCK_TWO, BLOCK_TWO, BLOCK_TWO, BLOCK_TWO,
			 BLOCK_TWO, BLOCK_TWO, BLOCK_TWO, BLOCK_TWO, LIVE_ONE, LIVE_ONE, LIVE_ONE, LIVE_ONE, BLOCK_ONE , BLOCK_ONE })
{
	nodes.resize(104);
}

void AC_Auto::BuildTrieTree() {
	nodes.push_back(TrieNode());
	int newNodeIndex = 1;
	for (int i = 0; i < patterns.size(); i++) {
		int cur = 0;
		for (char c : patterns[i]) {
			int index = c - '0';
			if (nodes[cur].next[index] == -1) {
				nodes[cur].next[index] = newNodeIndex;
				nodes[newNodeIndex] = TrieNode();
				nodes[newNodeIndex].data = c;
				newNodeIndex++;
			}
			cur = nodes[cur].next[index];//curÖ¸ÕëÏòÏÂÒ»¸ö×Ö·û
		}
		nodes[cur].length = patterns[i].length();//¼ÇÂ¼Ä£Ê½´®µÄ³¤¶È
		nodes[cur].score = scores[i];//¼ÇÂ¼·ÖÊý
	}
}

void AC_Auto::BuildFailPointer() {
	queue<int> q;
	for (int i = 0; i < 3; i++) {//root½ÚµãµÄ×Ó½ÚµãµÄfailÖ¸Õë¶¼Ö¸Ïòroot½Úµã
		nodes[nodes[0].next[i]].fail = 0;
		q.push(nodes[0].next[i]);
	}
	while (!q.empty()) {
		int cur = q.front();//È¡¶ÓÍ·
		q.pop();
		for (int i = 0; i < 3; ++i) {
			if (nodes[cur].next[i] != -1) {//Èç¹ûµ±Ç°½ÚµãµÄÓÐÆ¥ÅäµÄ×Ó½Úµã
				int fail = nodes[cur].fail;//×Ó½ÚµãµÄfailÖ¸Õë³õÊ¼»¯Îªµ±Ç°½ÚµãµÄfailÖ¸Õë
				while (nodes[fail].next[i] == -1) {//failÖ¸ÕëÖ¸ÏòµÄ½ÚµãÃ»ÓÐ¶ÔÓ¦µÄ×Ó½Úµã,Ôò¼ÌÐøÏòÉÏÌø×ª
					fail = nodes[fail].fail;
				}
				nodes[nodes[cur].next[i]].fail = nodes[fail].next[i];//×Ó½ÚµãµÄfailÖ¸ÕëÖ¸Ïòfail½ÚµãµÄ¶ÔÓ¦×Ó½Úµã
				q.push(nodes[cur].next[i]);//½«×Ó½Úµã¼ÓÈë¶ÓÁÐ
			}
		}
	}
}

LL AC_Auto::PatternScore(const string &text) {
	int cur = 0;
	LL totalScore = 0;
	for (int i = 0; i < text.size(); i++) {
		int c = text[i] - '0';
		while (nodes[cur].next[c] == -1 && cur != 0) {//Èç¹ûµ±Ç°½ÚµãÃ»ÓÐ¶ÔÓ¦µÄ×Ó½Úµã,ÔòÆ¥ÅäÊ§°Ü,Ìø×ªµ½failÖ¸Õë
			cur = nodes[cur].fail;
		}
		cur = nodes[cur].next[c];//Èç¹ûÓÐ¶ÔÓ¦µÄ×Ó½Úµã,ÔòÖ¸ÕëÖ¸Ïò×Ó½Úµã
		if (cur == -1) cur = 0;//Èç¹ûµ±Ç°Ö¸ÕëcurÎª-1,ËµÃ÷Ç°ÃæµÄfailÖ¸ÕëÈ«²¿Æ¥ÅäÊ§°Ü,ÔòÖ¸ÕëÖ¸Ïò¸ù½Úµã
		int temp = cur;
		while (temp != 0) {
			//Èç¹ûlengthÎª0,ËµÃ÷µ±Ç°½Úµã²»ÊÇÒ»¸öÄ£Ê½´®µÄ½áÎ²,Ôò²»»á½øÈëÑ­»·
			//Èç¹ûlength²»Îª0,ÔòËµÃ÷µ±Ç°½ÚµãÊÇÒ»¸öÄ£Ê½´®µÄ½áÎ²,Ôò¼ÆËã·ÖÊý
			totalScore += nodes[temp].score;
			temp = nodes[temp].fail;
		}
	}
	return totalScore;
}

/******************************************************************************************************/
/***********************************************µ÷ÊÔº¯Êý************************************************/
//Timer
#if _TIMER_
#include <chrono>
#include <string>
class Timer {
public:
	Timer(const string &msg) : m_begin(std::chrono::high_resolution_clock::now()), m_msg(msg) {}
	~Timer() {
		end();
	}
	void end() {
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_begin);
		printf("DEBUG %s takes : %lld ms\n", m_msg.c_str(), dur.count());
		fflush(stdout);
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
	string m_msg;
};
#endif

//DEBUG´òÓ¡ÆåÅÌ
#if _DEBUG_
//´òÓ¡ÆåÅÌ
void PrintBoard() {
	printf("\nDEBUG Board:\n");
	// ´òÓ¡ÁÐºÅ
	printf("  ");
	for (int j = 0; j < board_size; j++) {
		printf("\033[32m%x \033[0m", j); // ÂÌÉ«
	}
	printf("\n");

	for (int i = 0; i < board_size; i++) {
		// ´òÓ¡ÐÐºÅ
		printf("\033[32m%x \033[0m", i); // ÂÌÉ«
		for (int j = 0; j < board_size; j++) {
			if (board[i][j] == None) {
				printf("0 ");
			}
			else if (board[i][j] == Black) {
				printf("\033[31m1 \033[0m"); // ºìÉ«
			}
			else {
				printf("\033[33m2 \033[0m"); // »ÆÉ«
			}
		}
		printf("\n");
	}
	printf("\n");
	fflush(stdout);
}
#endif
/***********************************************µ÷ÊÔº¯Êý************************************************/
//*****************************************************************************************************
//º¯ÊýÊµÏÖ
set<Point, PointComparator> GetPossibleMoves(Chess color) {
	set<Point, PointComparator> moves;
	int minX = board_size, maxX = 0, minY = board_size, maxY = 0;

	// ÕÒµ½µ±Ç°Æå¾ÖµÄ×î×ó¡¢×îÓÒ¡¢×îÉÏ¡¢×îÏÂµã
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (board[i][j] != None) {
				if (i < minX) minX = i;
				if (i > maxX) maxX = i;
				if (j < minY) minY = j;
				if (j > maxY) maxY = j;
			}
		}
	}

	// À©Õ¹2¸ñµÄ·¶Î§
	minX = max(0, minX - 2);
	maxX = min(board_size - 1, maxX + 2);
	minY = max(0, minY - 2);
	maxY = min(board_size - 1, maxY + 2);

	// ÔÚÀ©Õ¹ºóµÄ·¶Î§ÄÚÑ°ÕÒ¿ÉÄÜµÄÂä×ÓÎ»ÖÃ
	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			if (board[i][j] == None) {
				if (EvaluatePosition(color, i, j) > 0)
					moves.insert({ i, j });//°´ÕÕÆÀ¹À·ÖÊý´Ó´óµ½Ð¡ÅÅÐò
			}
		}
	}

	return moves;
}


Point MakePlay(int depth) {
#if _TIMER_
	Timer t("Alpha_BetaÉîËÑ");
#endif
	// ³õÊ¼»¯ bestMove
	bestMove = { {-1, -1}, MIN_SCORE };
	//µÝ¹é,¼ÆËãÄ£ÄâÎ»ÖÃµÄ·ÖÊý
	Alpha_Beta(field, MIN_SCORE, MAX_SCORE, depth);
	board[bestMove.p.x][bestMove.p.y] = field;
	UpdateInfo(bestMove.p.x, bestMove.p.y);
	ppm.AddPossiblePos(bestMove.p.x, bestMove.p.y);
	return bestMove.p;
}

LL Alpha_Beta(Chess color, LL alpha, LL beta, int depth) {
	HashItem::Flag flag = HashItem::ALPHA;
	LL score = GetHashScore(depth, alpha, beta);
	//´ÓµÚ¶þ´ÎµÝ¹é¿ªÊ¼,Èç¹ûÖÃ»»±íÖÐÓÐÖµ,ÔòÖ±½Ó·µ»Ø
	if (score != hashNoneScore && depth != dpth) {
		return score;
	}
	LL score_self = Evaluate(color);
	LL score_oppo = Evaluate((color == Black) ? White : Black);
	//µÝ¹éµ½×îºóÒ»²ã,Ö±½Ó·µ»ØÆÀ¹ÀÖµ,ÒÔExact·½Ê½´æÈëÖÃ»»±í
	if (depth == 0) {
		RecordHashItem(depth, score_self - score_oppo, HashItem::EXACT);
		return score_self - score_oppo;
	}
	//Èç¹û¼º·½»ò¶Ô·½ÎåÁ¬,ÔòÖ±½Ó·µ»ØMAX·ÖÊý,ºóÃæµÄdpth-depthÊÇÎªÁËÈÃ±éÀú²ãÊýÉÙ(depth¸ü´óµÄ)½á¹û¸üÓÅÏÈ
	if (score_self >= FIVE_LINE)
		return MAX_SCORE - 10 - (dpth - depth);
	if (score_oppo >= FIVE_LINE)
		return MIN_SCORE + 10 + (dpth - depth);

	//set<Point, PointComparator> Moves = GetPossibleMoves(color);
	set<Point, PointComparator> Moves = ppm.GetPossiblePos();
	if (Moves.empty()) {
		return score_self - score_oppo;
	}
	Chess oppo = (color == Black) ? White : Black;
	int cnt = 0;
	for (const auto &p : Moves) {
		if (cnt > 10) break;
		//Ä£ÄâÂä×Ó
		board[p.x][p.y] = color;
		UpdateZobristValue(p.x, p.y, color);
		UpdateInfo(p.x, p.y);
		ppm.AddPossiblePos(p.x, p.y);

		//µÝ¹é,¼ÆËãÄ£ÄâÎ»ÖÃµÄ·ÖÊý
		LL val = -Alpha_Beta(oppo, -beta, -alpha, depth - 1);//ÒÔ¶ÔÊÖÊÓ½Ç½øÐÐÆÀ¹À
		//»¹Ô­ÆåÅÌ
		board[p.x][p.y] = None;
		UpdateZobristValue(p.x, p.y, color);
		UpdateInfo(p.x, p.y);
		ppm.RecoverLastState();
		//alpha-beta¼ôÖ¦
		//¶ÔÊÖÊÓ½Ç,È¡×îÐ¡Öµ,Èç¹ûµ±Ç°ÖµÒÑ¾­´óÓÚbetaÁË,Ôò¶ÔÊÖ²»»áÑ¡ÔñÕâ¸öÎ»ÖÃ,Ö±½Ó·µ»Øbeta
		if (val >= beta) {
			RecordHashItem(depth, beta, HashItem::BETA);
			return beta;
		}
		//¼º·½ÊÓ½Ç,È¡×î´óÖµ
		if (val > alpha) {
			flag = HashItem::EXACT;
			alpha = val;
			if (depth == dpth) {
				bestMove = { p, alpha };
			}
		}
		cnt++;
	}
	RecordHashItem(depth, alpha, flag);
	return alpha;
}

LL Evaluate(Chess color) {
	if (color == field) {
		return all_score[0];
	}
	else {
		return all_score[1];
	}
}

LL EvaluatePosition(Chess color, int x, int y) {
	//ÀàËÆÓÚUpdateScore,µ«ÊÇ²¢·Ç¸üÐÂ,¶øÊÇ¼ÆËã²¢·µ»ØÒ»¸öNoneÎ»ÖÃÏÂ×ÓcolorµÃµ½µÄ·ÖÊý(¼º·½-µÐ·½),ÓÃÓÚÄ£ÄâÂä×ÓµÄ¹ý³Ì
	//ÆÀ¹ÀÊ±Ö»¿¼ÂÇ×óÓÒ(Ë®Æ½Ê±)¸÷5¸ñµÄÆå×ÓÇé¿ö
	if (board[x][y] != None) return 0;
	board[x][y] = color;
	Chess opp = (color == Black) ? White : Black;
	//³õÊ¼»¯pattern
	string myPattern[4];//´óÐ¡Îª4,·Ö±ð´æ´¢ºá,Êú,×óÉÏ-ÓÒÏÂ,ÓÒÉÏ-×óÏÂµÄÆå×Ópattern
	string oppoPattern[4];
	//Èç¹û¿ªÍ·ÊÇ±ß½ç,ÔòÄ£Äâ±ß½ç
	if (x - 5 < 0) {
		myPattern[0] += '2';
		oppoPattern[0] += '2';
	}
	if (y - 5 < 0) {
		myPattern[1] += '2';
		oppoPattern[1] += '2';
	}
	if (x - min(5, min(x, y)) < 0) {
		myPattern[2] += '2';
		oppoPattern[2] += '2';
	}
	if (x + min(5, min(board_size - 1 - x, y)) >= board_size) {
		myPattern[3] += '2';
		oppoPattern[3] += '2';
	}

	//ºáÏò
	for (int i = max(0, x - 5); i < min(board_size, x + 6); i++) {
		myPattern[0] += (board[i][y] == color) ? '1' : (board[i][y] == None ? '0' : '2');
		oppoPattern[0] += (board[i][y] == opp) ? '1' : (board[i][y] == None ? '0' : '2');
	}
	//×ÝÏò
	for (int i = max(0, y - 5); i < min(board_size, y + 6); i++) {
		myPattern[1] += (board[x][i] == color) ? '1' : (board[x][i] == None ? '0' : '2');
		oppoPattern[1] += (board[x][i] == opp) ? '1' : (board[x][i] == None ? '0' : '2');
	}
	//×óÉÏ-ÓÒÏÂ
	for (int i = max(0, x - min(5, min(x, y))), j = max(0, y - min(5, min(x, y))); i < min(board_size, x + 6) && j < min(board_size, y + 6); i++, j++) {
		myPattern[2] += (board[i][j] == color) ? '1' : (board[i][j] == None ? '0' : '2');
		oppoPattern[2] += (board[i][j] == opp) ? '1' : (board[i][j] == None ? '0' : '2');
	}
	//ÓÒÉÏ-×óÏÂ
	for (int i = max(0, x + min(5, min(y, board_size - 1 - x))), j = max(0, y - min(5, min(y, board_size - 1 - x))); i >= 0 && j < min(board_size, y + 6); i--, j++) {
		myPattern[3] += (board[i][j] == color) ? '1' : (board[i][j] == None ? '0' : '2');
		oppoPattern[3] += (board[i][j] == opp) ? '1' : (board[i][j] == None ? '0' : '2');
	}
	//Èç¹û½áÎ²ÊÇ±ß½ç,ÔòÄ£Äâ±ß½ç
	if (x + 5 >= board_size) {
		myPattern[0] += '2';
		oppoPattern[0] += '2';
	}
	if (y + 5 >= board_size) {
		myPattern[1] += '2';
		oppoPattern[1] += '2';
	}
	if (x + min(5, min(board_size - 1 - x, y)) >= board_size) {
		myPattern[3] += '2';
		oppoPattern[3] += '2';
	}
	if (x - min(5, min(x, y)) < 0) {
		myPattern[2] += '2';
		oppoPattern[2] += '2';
	}
	LL myScore = 0;
	LL oppoScore = 0;

	for (int i = 0; i < 4; i++) {
		//¼ÆËã¼º·½·ÖÊý
		myScore += AC_Searcher.PatternScore(myPattern[i]);
		//¼ÆËã¶Ô·½·ÖÊý
		oppoScore += AC_Searcher.PatternScore(oppoPattern[i]);
	}

	//myScoreºÍoppoScore·Ö±ð¼õÈ¥Ä£ÄâÂä×ÓÇ°Çé¿öµÄ·ÖÊý
	myScore -= point_score[0][0][x];
	myScore -= point_score[0][1][y];
	myScore -= point_score[0][2][x - y + board_size];
	myScore -= point_score[0][3][x + y];
	oppoScore -= point_score[1][0][x];
	oppoScore -= point_score[1][1][y];
	oppoScore -= point_score[1][2][x - y + board_size];
	oppoScore -= point_score[1][3][x + y];

	board[x][y] = None;
	return myScore - oppoScore;
}


void UpdateScore(int x, int y) {
	string myPattern[4];//´óÐ¡Îª4,·Ö±ð´æ´¢ºá,Êú,×óÉÏ-ÓÒÏÂ,ÓÒÉÏ-×óÏÂµÄÆå×Ópattern
	string oppoPattern[4];
	//ºáÏò
	for (int i = 0; i < board_size; i++) {
		myPattern[0] += (board[x][i] == field) ? '1' : (board[x][i] == None ? '0' : '2');
		oppoPattern[0] += (board[x][i] == opponent) ? '1' : (board[x][i] == None ? '0' : '2');
	}
	//×ÝÏò
	for (int i = 0; i < board_size; i++) {
		myPattern[1] += (board[i][y] == field) ? '1' : (board[i][y] == None ? '0' : '2');
		oppoPattern[1] += (board[i][y] == opponent) ? '1' : (board[i][y] == None ? '0' : '2');
	}
	//×óÉÏ-ÓÒÏÂ
	for (int i = x - min(x, y), j = y - min(x, y); i < board_size && j < board_size; i++, j++) {
		myPattern[2] += (board[i][j] == field) ? '1' : (board[i][j] == None ? '0' : '2');
		oppoPattern[2] += (board[i][j] == opponent) ? '1' : (board[i][j] == None ? '0' : '2');
	}
	//ÓÒÉÏ-×óÏÂ
	for (int i = x + min(board_size - 1 - x, y), j = y - min(board_size - 1 - x, y); i >= 0 && j < board_size; i--, j++) {
		myPattern[3] += (board[i][j] == field) ? '1' : (board[i][j] == None ? '0' : '2');
		oppoPattern[3] += (board[i][j] == opponent) ? '1' : (board[i][j] == None ? '0' : '2');
	}

	//Ê×Î²¼ÓÉÏµÐ·½×Ó,Ä£Äâ±ß½ç
	for (int i = 0; i < 4; i++) {
		myPattern[i] = "2" + myPattern[i] + "2";
		oppoPattern[i] = "2" + oppoPattern[i] + "2";
	}

	LL myScore[4] = { 0 };
	LL oppoScore[4] = { 0 };

	//¼ÆËã·ÖÊý

	for (int i = 0; i < 4; i++) {
		//¼ÆËã¼º·½·ÖÊý
		myScore[i] += AC_Searcher.PatternScore(myPattern[i]);
		//¼ÆËã¶Ô·½·ÖÊý
		oppoScore[i] += AC_Searcher.PatternScore(oppoPattern[i]);
	}

	//¸üÐÂ·ÖÊý
	//ÏÈ¼õÈ¥Ô­À´µÄ·ÖÊý
	for (int i = 0; i < 2; i++) {
		all_score[i] -= point_score[i][0][x];
		all_score[i] -= point_score[i][1][y];
		all_score[i] -= point_score[i][2][x - y + board_size];
		all_score[i] -= point_score[i][3][x + y];
	}
	//¸üÐÂpoint_score
	point_score[0][0][x] = myScore[0];
	point_score[0][1][y] = myScore[1];
	point_score[0][2][x - y + board_size] = myScore[2];
	point_score[0][3][x + y] = myScore[3];
	point_score[1][0][x] = oppoScore[0];
	point_score[1][1][y] = oppoScore[1];
	point_score[1][2][x - y + board_size] = oppoScore[2];
	point_score[1][3][x + y] = oppoScore[3];

	//ÔÙ¼ÓÉÏÐÂµÄ·ÖÊý
	for (int i = 0; i < 2; i++) {
		all_score[i] += point_score[i][0][x];
		all_score[i] += point_score[i][1][y];
		all_score[i] += point_score[i][2][x - y + board_size];
		all_score[i] += point_score[i][3][x + y];
	}
}

//LL PatternScore(Chess color, const string& line) {
//	//Èç¹ûlineÖÐÎÞ1,ÔòÖ±½Ó·µ»Ø0
//	if (line.find("1") == string::npos) return 0;
//	LL totalScore = 0;
//	double colorRate = (color == White) ? 0.45 : 1;
//	for (size_t i = 0; i < patterns.size(); i++) {
//		size_t pos = 0;
//		while ((pos = line.find(patterns[i].pattern, pos)) != string::npos) {
//			totalScore += (LL)(colorRate * patterns[i].score);
//			pos += patterns[i].pattern.size();
//		}
//	}
//	return totalScore;
//}

void InitGame() {
	//³õÊ¼»¯Zobrist
	RandomBoardZobristValue();
	InitCurrentZobristValue();
	//³õÊ¼AC×Ô¶¯»ú
	AC_Searcher.BuildTrieTree();
	AC_Searcher.BuildFailPointer();
	//³õÊ¼»¯ÆåÅÌ
	board[5][6] = Black;
	UpdateZobristValue(5, 6, Black);
	UpdateInfo(5, 6);
	ppm.AddPossiblePos(5, 6);
	board[5][5] = White;
	UpdateZobristValue(5, 5, White);
	UpdateInfo(5, 5);
	ppm.AddPossiblePos(5, 5);
	board[6][5] = Black;
	UpdateZobristValue(6, 5, Black);
	UpdateInfo(6, 5);
	ppm.AddPossiblePos(6, 5);
	board[6][6] = White;
	UpdateZobristValue(6, 6, White);
	UpdateInfo(6, 6);
	ppm.AddPossiblePos(6, 6);
}

//Ö÷º¯Êý
void StartGame() {
	char cmd[10];
	//Ö÷Ñ­»·
	while (1) {
		// ½ÓÊÕÖ¸Áî
		int color = 0;
		scanf("%s %d", cmd, &color);
		// ¼ì²éÖ¸ÁîÊÇ·ñÎª START
		if (strcmp(cmd, "START") == 0 && (color == 1 || color == 2)) {
			field = (color == 1) ? Black : White;
			printf("OK\n");
			fflush(stdout);
			opponent = (field == Black) ? White : Black;
			InitGame();
			break;
		}
	}
	//¿ªÊ¼ÓÎÏ·
	while (1) {
		scanf("%s", cmd);

		if (strcmp(cmd, "TURN") == 0) {//¼º·½ÏÂÆå
			Point p = MakePlay(dpth);
#if _DEBUG_
			PrintBoard();
#endif
			printf("%d %d\n", p.x, p.y);
			fflush(stdout);
		}
		else if (strcmp(cmd, "PLACE") == 0) {//¶Ô·½ÏÂÆå
			int x, y;
			scanf("%d %d", &x, &y);
			board[x][y] = opponent;
			UpdateZobristValue(x, y, opponent);
			UpdateInfo(x, y);
			ppm.AddPossiblePos(x, y);
		}
		//ÅÐ¶ÏÓÎÏ·½áÊø
		if (strcmp(cmd, "END") == 0) {
#if _DEBUG_
			int w;
			scanf("%d", &w);
			if (w == 1) {
				printf("DEBUG winner is Black\n");
			}
			else {
				printf("DEBUG winner is White\n");
			}
#endif
			break;
		}
	}
}

//mainº¯Êý
int main() {
	StartGame();
	return 0;
}