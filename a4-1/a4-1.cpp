#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <limits>
#include <vector>

enum class PlayerLevel {
    Beginner,
    Professional,
    Expert
};

class User_Prof {
private:
    std::string name;
    int id;
    std::chrono::system_clock::time_point loginTime;
    int gamesPlayed;
    int gamesWon;
    PlayerLevel level;

public:
    // 构造函数，默认等级为初学者，默认名称为 "guest"
    User_Prof(const std::string &name = "guest", PlayerLevel level = PlayerLevel::Beginner, int id = 0)
        : name(name), id(id), gamesPlayed(0), gamesWon(0), level(level) {}

    // 登录操作
    void login() {
        loginTime = std::chrono::system_clock::now();
        std::cout << "用户 " << name << " (ID: " << id << ") 登录时间: "
            << std::chrono::system_clock::to_time_t(loginTime) << std::endl;
    }

    // 登出操作
    void logout() {
        auto logoutTime = std::chrono::system_clock::now();
        std::cout << "用户 " << name << " (ID: " << id << ") 登出时间: "
            << std::chrono::system_clock::to_time_t(logoutTime) << std::endl;
    }

    // 测试相等性
    bool operator==(const User_Prof &other) const {
        return id == other.id;
    }

    // 测试不相等性
    bool operator!=(const User_Prof &other) const {
        return !(*this == other);
    }

    // 获取玩家姓名
    std::string getName() const {
        return name;
    }

    // 获取玩家ID
    int getId() const {
        return id;
    }

    // 获取玩家等级
    PlayerLevel getLevel() const {
        return level;
    }

    // 获取已玩比赛数
    int getGamesPlayed() const {
        return gamesPlayed;
    }

    // 获取获胜比赛数
    int getGamesWon() const {
        return gamesWon;
    }

    // 获取胜率
    double getWinRate() const {
        if (gamesPlayed == 0) return 0.0;
        return static_cast<double>(gamesWon) / gamesPlayed;
    }

    // 设置玩家姓名
    void setName(const std::string &newName) {
        name = newName;
    }

    // 设置玩家等级
    void setLevel(PlayerLevel newLevel) {
        level = newLevel;
    }

    // 增加已玩比赛数
    void incrementGamesPlayed() {
        gamesPlayed++;
    }

    // 增加获胜比赛数
    void incrementGamesWon() {
        gamesWon++;
    }
};

// 辅助函数：将 PlayerLevel 转换为字符串
std::string levelToString(PlayerLevel level) {
    switch (level) {
        case PlayerLevel::Beginner: return "初学者";
        case PlayerLevel::Professional: return "专业";
        case PlayerLevel::Expert: return "专家";
        default: return "未知";
    }
}

// 辅助函数：清除输入缓冲区
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::unordered_map<std::string, std::vector<User_Prof>> users;
    int nextUserId = 1;

    while (true) {
        std::cout << "1. 创建新用户\n"
            << "2. 用户登录\n"
            << "3. 用户登出\n"
            << "4. 比较用户\n"
            << "5. 退出\n"
            << "请选择一个选项: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "输入无效，请输入数字。\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "请输入用户名: ";
            std::cin >> name;

            int levelChoice;
            std::cout << "请选择玩家等级 (1: 初学者, 2: 专业, 3: 专家): ";
            std::cin >> levelChoice;

            if (std::cin.fail()) {
                std::cout << "输入无效，请输入数字。\n";
                clearInputBuffer();
                continue;
            }

            PlayerLevel level;
            switch (levelChoice) {
                case 1: level = PlayerLevel::Beginner; break;
                case 2: level = PlayerLevel::Professional; break;
                case 3: level = PlayerLevel::Expert; break;
                default:
                    std::cout << "无效选择，默认设置为初学者。\n";
                    level = PlayerLevel::Beginner;
                    break;
            }

            users[name].push_back(User_Prof(name, level, nextUserId++));
            std::cout << "用户 " << name << " (ID: " << nextUserId - 1 << ") 创建成功，等级为 " << levelToString(level) << "。\n";

        }
        else if (choice == 2) {
            std::string name;
            int id;
            std::cout << "请输入用户名以登录: ";
            std::cin >> name;
            std::cout << "请输入用户ID以登录: ";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cout << "输入无效，请输入数字。\n";
                clearInputBuffer();
                continue;
            }

            auto it = std::find_if(users[name].begin(), users[name].end(), [id](const User_Prof &user) {
                return user.getId() == id;
                });

            if (it == users[name].end()) {
                std::cout << "用户不存在。\n";
                continue;
            }

            it->login();

        }
        else if (choice == 3) {
            std::string name;
            int id;
            std::cout << "请输入用户名以登出: ";
            std::cin >> name;
            std::cout << "请输入用户ID以登出: ";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cout << "输入无效，请输入数字。\n";
                clearInputBuffer();
                continue;
            }

            auto it = std::find_if(users[name].begin(), users[name].end(), [id](const User_Prof &user) {
                return user.getId() == id;
                });

            if (it == users[name].end()) {
                std::cout << "用户不存在。\n";
                continue;
            }

            it->logout();

        }
        else if (choice == 4) {
            std::string name1, name2;
            int id1, id2;
            std::cout << "请输入第一个用户名以比较: ";
            std::cin >> name1;
            std::cout << "请输入第一个用户ID以比较: ";
            std::cin >> id1;
            std::cout << "请输入第二个用户名以比较: ";
            std::cin >> name2;
            std::cout << "请输入第二个用户ID以比较: ";
            std::cin >> id2;

            if (std::cin.fail()) {
                std::cout << "输入无效，请输入数字。\n";
                clearInputBuffer();
                continue;
            }

            auto it1 = std::find_if(users[name1].begin(), users[name1].end(), [id1](const User_Prof &user) {
                return user.getId() == id1;
                });

            auto it2 = std::find_if(users[name2].begin(), users[name2].end(), [id2](const User_Prof &user) {
                return user.getId() == id2;
                });

            if (it1 == users[name1].end() || it2 == users[name2].end()) {
                std::cout << "一个或两个用户不存在。\n";
                continue;
            }

            if (*it1 == *it2) {
                std::cout << "用户相等。\n";
            }
            else {
                std::cout << "用户不相等。\n";
            }

        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "无效选择，请重新选择。\n";
        }
    }

    return 0;
}