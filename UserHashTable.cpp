#include <vector>
#include <list>
#include <string>
#include <functional>  // for std::hash
#include <utility>     // for std::pair

class UserHashTable {
public:
    UserHashTable(size_t size = 100) : table(size) {}

    void addUser(const std::string& username, const std::string& profileData) {
        size_t index = hashFunction(username);
        // Check if the username already exists in the chain
        for (auto& pair : table[index]) {
            if (pair.first == username) {
                pair.second = profileData;  // Update profile data if username exists
                return;
            }
        }
        // If not found, add new username and profileData pair
        table[index].emplace_back(username, profileData);
    }

    std::string getUser(const std::string& username) const {
        size_t index = hashFunction(username);
        // Search for the username in the chain at that index
        for (const auto& pair : table[index]) {
            if (pair.first == username) {
                return pair.second;  // Return profile data if found
            }
        }
        return "";  // Return empty string if user not found
    }

private:
    size_t hashFunction(const std::string& username) const {
        return std::hash<std::string>{}(username) % table.size();
    }

    std::vector<std::list<std::pair<std::string, std::string>>> table;  // Hash table with separate chaining
};
