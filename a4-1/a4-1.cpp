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
    // ���캯����Ĭ�ϵȼ�Ϊ��ѧ�ߣ�Ĭ������Ϊ "guest"
    User_Prof(const std::string &name = "guest", PlayerLevel level = PlayerLevel::Beginner, int id = 0)
        : name(name), id(id), gamesPlayed(0), gamesWon(0), level(level) {}

    // ��¼����
    void login() {
        loginTime = std::chrono::system_clock::now();
        std::cout << "�û� " << name << " (ID: " << id << ") ��¼ʱ��: "
            << std::chrono::system_clock::to_time_t(loginTime) << std::endl;
    }

    // �ǳ�����
    void logout() {
        auto logoutTime = std::chrono::system_clock::now();
        std::cout << "�û� " << name << " (ID: " << id << ") �ǳ�ʱ��: "
            << std::chrono::system_clock::to_time_t(logoutTime) << std::endl;
    }

    // ���������
    bool operator==(const User_Prof &other) const {
        return id == other.id;
    }

    // ���Բ������
    bool operator!=(const User_Prof &other) const {
        return !(*this == other);
    }

    // ��ȡ�������
    std::string getName() const {
        return name;
    }

    // ��ȡ���ID
    int getId() const {
        return id;
    }

    // ��ȡ��ҵȼ�
    PlayerLevel getLevel() const {
        return level;
    }

    // ��ȡ���������
    int getGamesPlayed() const {
        return gamesPlayed;
    }

    // ��ȡ��ʤ������
    int getGamesWon() const {
        return gamesWon;
    }

    // ��ȡʤ��
    double getWinRate() const {
        if (gamesPlayed == 0) return 0.0;
        return static_cast<double>(gamesWon) / gamesPlayed;
    }

    // �����������
    void setName(const std::string &newName) {
        name = newName;
    }

    // ������ҵȼ�
    void setLevel(PlayerLevel newLevel) {
        level = newLevel;
    }

    // �������������
    void incrementGamesPlayed() {
        gamesPlayed++;
    }

    // ���ӻ�ʤ������
    void incrementGamesWon() {
        gamesWon++;
    }
};

// ������������ PlayerLevel ת��Ϊ�ַ���
std::string levelToString(PlayerLevel level) {
    switch (level) {
        case PlayerLevel::Beginner: return "��ѧ��";
        case PlayerLevel::Professional: return "רҵ";
        case PlayerLevel::Expert: return "ר��";
        default: return "δ֪";
    }
}

// ����������������뻺����
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::unordered_map<std::string, std::vector<User_Prof>> users;
    int nextUserId = 1;

    while (true) {
        std::cout << "1. �������û�\n"
            << "2. �û���¼\n"
            << "3. �û��ǳ�\n"
            << "4. �Ƚ��û�\n"
            << "5. �˳�\n"
            << "��ѡ��һ��ѡ��: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "������Ч�����������֡�\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "�������û���: ";
            std::cin >> name;

            int levelChoice;
            std::cout << "��ѡ����ҵȼ� (1: ��ѧ��, 2: רҵ, 3: ר��): ";
            std::cin >> levelChoice;

            if (std::cin.fail()) {
                std::cout << "������Ч�����������֡�\n";
                clearInputBuffer();
                continue;
            }

            PlayerLevel level;
            switch (levelChoice) {
                case 1: level = PlayerLevel::Beginner; break;
                case 2: level = PlayerLevel::Professional; break;
                case 3: level = PlayerLevel::Expert; break;
                default:
                    std::cout << "��Чѡ��Ĭ������Ϊ��ѧ�ߡ�\n";
                    level = PlayerLevel::Beginner;
                    break;
            }

            users[name].push_back(User_Prof(name, level, nextUserId++));
            std::cout << "�û� " << name << " (ID: " << nextUserId - 1 << ") �����ɹ����ȼ�Ϊ " << levelToString(level) << "��\n";

        }
        else if (choice == 2) {
            std::string name;
            int id;
            std::cout << "�������û����Ե�¼: ";
            std::cin >> name;
            std::cout << "�������û�ID�Ե�¼: ";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cout << "������Ч�����������֡�\n";
                clearInputBuffer();
                continue;
            }

            auto it = std::find_if(users[name].begin(), users[name].end(), [id](const User_Prof &user) {
                return user.getId() == id;
                });

            if (it == users[name].end()) {
                std::cout << "�û������ڡ�\n";
                continue;
            }

            it->login();

        }
        else if (choice == 3) {
            std::string name;
            int id;
            std::cout << "�������û����Եǳ�: ";
            std::cin >> name;
            std::cout << "�������û�ID�Եǳ�: ";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cout << "������Ч�����������֡�\n";
                clearInputBuffer();
                continue;
            }

            auto it = std::find_if(users[name].begin(), users[name].end(), [id](const User_Prof &user) {
                return user.getId() == id;
                });

            if (it == users[name].end()) {
                std::cout << "�û������ڡ�\n";
                continue;
            }

            it->logout();

        }
        else if (choice == 4) {
            std::string name1, name2;
            int id1, id2;
            std::cout << "�������һ���û����ԱȽ�: ";
            std::cin >> name1;
            std::cout << "�������һ���û�ID�ԱȽ�: ";
            std::cin >> id1;
            std::cout << "������ڶ����û����ԱȽ�: ";
            std::cin >> name2;
            std::cout << "������ڶ����û�ID�ԱȽ�: ";
            std::cin >> id2;

            if (std::cin.fail()) {
                std::cout << "������Ч�����������֡�\n";
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
                std::cout << "һ���������û������ڡ�\n";
                continue;
            }

            if (*it1 == *it2) {
                std::cout << "�û���ȡ�\n";
            }
            else {
                std::cout << "�û�����ȡ�\n";
            }

        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "��Чѡ��������ѡ��\n";
        }
    }

    return 0;
}